//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
ll c[N];
ll sz[N];
ll mult[N];
ll suf[N];
ll cur[N];
void solve(){
    int n,k;cin>>n>>k;
    k++;
    vector<int>v,u;
    for (int i=1;i<=n;i++) {
        cin>>c[i];
        if (c[i]>0){
            v.push_back(c[i]);
        } else {
            u.push_back(-c[i]);
        }
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    reverse(u.begin(),u.end());
    ll add=0ll;
    ll sum=0ll;
    for (ll i=0;i<v.size();i++){
        add+=v[i]*i;
        sum+=v[i];
    }
    ll res=-1e18+1ll;
    for (int i=0;i<u.size();i++){
        c[i+1]=u[i];
    }
    int m=u.size();
    cur[m+1]=0ll;
    suf[m+1]=0ll;
    for (int i=m;i>=1;i--){
        suf[i]=suf[i+1]+cur[i+1];
        cur[i]=cur[i+1]+c[i];
    }
    ll pref=0ll;
    for (ll i=1;i<=m+1;++i){
        res=max(res,add+sum*(m-i+1ll+(i+k-2ll)/k)-pref-suf[i]-cur[i]*((i+k-2ll)/k));
        res=max(res,add+sum*(m-i+1ll+(i-1ll)/k)-pref-suf[i]-cur[i]*((i-1ll)/k));
        pref+=((i-1ll)/(k*1ll))*c[i];
    }
    cout<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}