#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const int inf=1000000001;
int n;
int a[N];
pair<int,int> b[N];
int BIT[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1){
        BIT[pos]+=x;
    }
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=BIT[pos];
    return sum;
}
int c[N];
ll Count(int x){
    for (int i=1;i<=n;i++) b[i].first=(a[i]^x),b[i].second=i;
    sort(b+1,b+n+1);
    for (int i=0;i<=n;i++) BIT[i]=0;
    ll res=0ll;
    int cur=1;
    c[b[1].second]=1;
    for (int i=2;i<=n;i++){
        if (b[i].first!=b[i-1].first) cur++;
        c[b[i].second]=cur;
    }
    for (int i=1;i<=n;i++){
        res+=(i-1)-get(c[i]);
        upd(n,c[i],1);
    }
    return res;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int x=0;
    ll cur=Count(0);
    for (int i=30;i>=0;i--){
        ll nxt=Count(x^(1<<i));
        if (nxt<cur){
            cur=nxt;
            x^=(1<<i);
        }
    }
    cout<<cur<<" "<<x<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
8 7
1 7 5 6 8 2 6 5

*/