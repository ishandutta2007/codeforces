#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=800010;
const ll mod=998244353;
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (binpow(a,b-1)*a)%mod;
    else return binpow((a*a)%mod,b/2);
}
ll C(int n,int k){
    if (k<0 || n<k) return 0;
    return (((f[n]*rf[k])%mod)*rf[n-k])%mod;
}
int l[N];
int r[N];
map<int,int>mp;
int pref[N];
int cnt[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    f[0]=1ll;
    for (ll i=1;i<=n+n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n+n]=binpow(f[n+n],mod-2);
    for (ll i=n+n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    set<int>st;
    for (int i=1;i<=n;++i) {
        cin>>l[i]>>r[i];
        st.insert(l[i]);
        st.insert(r[i]);
    }
    int m=0;
    for (int x:st){
        mp[x]=++m;
    }
    for (int i=1;i<=n;i++){
        l[i]=mp[l[i]];
        r[i]=mp[r[i]];
    }
    for (int i=1;i<=n;i++){
        pref[l[i]]++;
        pref[r[i]+1]--;
        cnt[r[i]]++;
    }
    for (int i=1;i<=m;i++){
        pref[i]+=pref[i-1];
    }
    ll res=0ll;
    for (int i=1;i<=m;i++){
        res+=C(pref[i],k)-C(pref[i]-cnt[i],k)+mod;
        res%=mod;
    }
    cout<<res<<endl;

    return 0;
}