#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const int inf=1000000001;
int bit[N];
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=1;
    int ind=1;
    for (int i=3;i<=n;i++){
        if (a[i-1]>a[i]){
            b[ind]=cnt;
            ind++;
            cnt=1;
        } else {
            cnt++;
        }
    }
    b[ind]=cnt;
    int cur=1;
    int res=0;
    int L=1;
    while (cur<=ind){
        res++;
        int nxt=min(cur+L-1,ind);
        int sum=0;
        L=0;
        for (int i=cur;i<=nxt;i++) L+=b[i];
        cur=nxt+1;
    }
    cout<<res<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
7
7 7 7 7 7 7 7
*/