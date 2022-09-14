//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
const ll mod=998244353ll;
using namespace std;
ll dp[2011][4011];
ll h[300001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>h[i];
    h[n+1]=h[1];
    if (h[1]==h[2]){
        dp[2][2000]=k;
    } else {
        dp[2][2001]=1ll;
        dp[2][1999]=1ll;
        dp[2][2000]=k-2ll;
    }
    for (int i=2;i<=n;i++){
        for (int j=2000-i;j<=2000+i;j++){
            if (h[i]==h[i+1]) dp[i+1][j]=(dp[i+1][j]+dp[i][j]*k)%mod;
            else {
                dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(k-2ll))%mod;
                dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
                dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
            }
        }
    }
    ll sum=0ll;
    for (int i=2001;i<=2000+n;i++) sum=(sum+dp[n+1][i])%mod;
    cout<<sum;
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