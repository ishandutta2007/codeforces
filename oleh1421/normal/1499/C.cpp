//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=100010;
ll c[N];
ll mn[2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    mn[0]=mn[1]=1000000001ll;
    ll sum=0ll;
    ll res=1e18;
    for (int k=1;k<=n;k++){
        mn[k%2]=min(mn[k%2],c[k]);
        sum+=c[k];
        if (k==1) continue;
        ll cur=sum+mn[0]*(n-k/2ll)+mn[1]*(n-(k+1ll)/2ll);
        res=min(res,cur);
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}