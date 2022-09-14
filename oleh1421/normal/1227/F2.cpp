//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
const ll mod=998244353ll;
using namespace std;
ll dp[2011][4011];
ll h[300011];
ll f(int n,ll k){
    dp[2][2001]=1ll;
    dp[2][1999]=1ll;
    dp[2][2000]=k-2ll;
    for (int i=2;i<=n;i++){
        for (int j=2000-i;j<=2000+i;j++){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(k-2ll))%mod;
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
            dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
        }
    }
    ll sum=0ll;
    for (int i=2001;i<=2000+n;i++) sum=(sum+dp[n+1][i])%mod;
    return sum;
}
ll binpow(ll a,ll b){
    if (b==0) return 1ll;
    if (b%2) return (a*binpow(a,b-1ll))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll fact[300011];
ll inv_fact[300011];
ll C(int n,int k){
    return ((fact[n]*inv_fact[k])%mod*inv_fact[n-k])%mod;
}
ll solve(int n,ll k){
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        if (i%2) sum=(sum+((binpow(k-2ll,n-i)*binpow(2ll,i-1ll))%mod)*C(n,i))%mod;
        else sum=(sum+((((binpow(k-2ll,n-i)*(binpow(2ll,i)-C(i,i/2ll)+mod))%mod)*binpow(2ll,mod-2ll))%mod)*C(n,i))%mod;
    }
    /*for (int i=0;i<=n;i++){
        for (int j=i+1;i+j<=n;j++){
            sum+=((C(n,i)*C(n-i,j))%mod*binpow(k-2ll,n-i-j));
            sum%=mod;
        }
    }*/
    return sum;
}
int32_t main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    fact[0]=1ll;
    for (ll i=1;i<=300000;i++) fact[i]=(fact[i-1]*i)%mod;
    inv_fact[300000]=binpow(fact[300000],mod-2ll);
    for (ll i=300000-1;i>=0;i--) inv_fact[i]=(inv_fact[i+1]*(i+1ll))%mod;
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>h[i];
    h[n+1]=h[1];
    vector<int>v={h[1]};
    ll p=1ll;
    for (int i=2;i<=n+1;i++){
        if (h[i]!=h[i-1]) v.push_back(h[i]);
        else p=(p*k)%mod;
    }
    int cnt=0;
    for (auto i:v) h[++cnt]=i;
    n=cnt-1;
    cout<<(solve(n,k)*p)%mod;
    return 0;
}
/*
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[300001];
map<int,int>mp;
int val[300001];
set<int>g[300001];
int ans[300001];
void solve(){
    vector<pair<pair<int,int>,int> >q;
    int n;cin>>n;
    set<int>nn;
    for (int i=1;i<=n;i++) cin>>a[i],nn.insert(a[i]);
    int cnt=0;
    for (auto i:nn) mp[i]=++cnt,val[cnt]=i;
    vector<int>v;
    for (int i=1;i<=n;i++){
        g[mp[a[i]].insert(i);
        v.push_back(mp[a[i]]);
    }
    sort(v.begin(),v.end());
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        int k,pos;cin>>k>>pos;
        q.push_back({{k,pos},i});
    }
    sort(q.begin(),q.end());
    set<int>sub_seq;
    int K=0;
    for (int i=0;i<m;i++){
        int k=q[i].first.first;
        int pos=q[i].first.second;
        int ind=q[i].second;
        while (K<k){
            K++;
            int cur=v[n-K];
            if (sub_seq.empty()){
                sub_seq.insert(*g[cur].rbegin());
            } else {
                int j=-1;
                auto it=g[cur].lower_bound(*sub_seq.begin());
                if (it!=g[cur].begin()) it--;
                sub_seq.insert(*it);
                g[cur].erase(it);
            }
        }
        ans[ind]=sub_se
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
*/