//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define double long double
const int N=500010;
int c[N],k[N];
ll pref[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>k[i];
    for (int i=1;i<=m;i++) cin>>c[i];
    pref[0]=0;
    for (int i=1;i<=m;i++){
        pref[i]=pref[i-1]+c[i];
    }
    sort(k+1,k+n+1);
    int cur=m+1;
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=c[k[i]];
    ll res=sum;

    for (int i=n;i>=1;i--){
        cur=min(cur-1,k[i]);
        sum-=c[k[i]];
        if (cur>=1){
            res=min(res,sum+pref[n-i+1]);
        }
    }
    cout<<res<<endl;

}
int32_t main()
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

*/