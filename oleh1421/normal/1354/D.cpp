#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
int bit[N];
void add(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) bit[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>0;pos&=pos+1,pos--) sum+=bit[pos];
    return sum;
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        add(n,x,1);
    }
    for (int i=1;i<=q;i++){
        int x;cin>>x;
        if (x>0){
            add(n,x,1);
        } else {
            x=-x;
            int val=0;
            for (int j=20;j>=0;j--){
                if (val+(1<<j)<=n && get(val+(1<<j)-1)<x) val+=(1<<j);
            }
            add(n,val,-1);
        }
    }
    for (int i=1;i<=n;i++){
        if (get(i)){
            cout<<i<<endl;
            return;
        }
    }
    cout<<0<<endl;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
5 4
1 3 1
1 3
1 4
1 5
2 5
*/