//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
const int N=1000100;
const ll mod=998244353;
const int Lg=61;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
ll x[N],p[N];
ll val[N];
ll pref[N];
ll suf[N];
ll ans[N];
void solve(){
    ll n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>x[i]>>p[i],val[i]=0;
    vector<pair<int,int> >R;
    for (int i=1;i<=n;i++) R.push_back({x[i],i});
    sort(R.begin(),R.end());

    {
        set<pair<ll,int> >st;
        ll sum=0ll;
        for (auto cur:R){
            int i=cur.second;
            st.insert({p[i]+x[i],i});
            sum+=p[i]+x[i];
            while (!st.empty() && (*st.begin()).first<=x[i]){
                sum-=(*st.begin()).first;
                st.erase(st.begin());
            }
            val[i]=sum-x[i]*(ll)st.size();
//            cout<<i<<" "<<x[i]<<" "<<val[i]<<endl;
        }
    }
    {
        ll sum=0ll;
        reverse(R.begin(),R.end());
        set<pair<ll,int> >st;
        for (auto cur:R){
            int i=cur.second;
            st.insert({p[i]-x[i],i});
            sum+=p[i]-x[i];
            while (!st.empty() && (*st.begin()).first<=-x[i]){
                sum-=(*st.begin()).first;
                st.erase(st.begin());
            }
            val[i]+=sum+x[i]*(ll)st.size();
        }
        reverse(R.begin(),R.end());
    }
    for (int i=1;i<=n;i++) val[i]-=p[i];
    for (int i=1;i<=n;i++){
        val[i]=max(0ll,val[i]-m);
    }

    pref[0]=-10000000000001ll;
    ll last=1000000001;
    for (int i=0;i<R.size();i++){
        if (val[R[i].second]>0) pref[i+1]=max(pref[i],val[R[i].second]-R[i].first);
        else pref[i+1]=pref[i];
    }
    suf[n+1]=-10000000000000001ll;
    for (int i=(int)R.size()-1;i>=0;i--){
        if (val[R[i].second]>0)
            suf[i+1]=max(suf[i+2],val[R[i].second]+R[i].first);
        else suf[i+1]=suf[i+2];
    }
    for (int i=0;i<R.size();i++){
        if (pref[i+1]<=p[R[i].second]-R[i].first && suf[i+1]<=p[R[i].second]+R[i].first) ans[R[i].second]=1;
        else ans[R[i].second]=0;
    }
    for (int i=1;i<=n;i++) cout<<ans[i];
    cout<<'\n';
//    for (int i=1;i<=n;i++) cout<<val[i]<<" ";
//    cout<<endl;

}


signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}