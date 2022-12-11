#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const ll inf = (ll)1e18;
vector<int> L[N];
int A[N];
ll dp[N];
int par[N];
vector<int> lay[N];
int lar;
int low[N], mx[N];

void dfs(int u, int d){
    lar = max(lar, d);
    low[d]=min(low[d], A[u]);
    mx[d]=max(mx[d], A[u]);
    lay[d].push_back(u);
    for(auto x : L[u]){
        dfs(x, d + 1);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n; i ++ ){
        low[i]=(int)1e9;
        mx[i]=0;
        L[i].clear();
        lay[i].clear();
    }
    lar=0;
    int p;
    for(int i = 2; i <= n; i ++ ){
        cin >> par[i];
        L[par[i]].push_back(i);
    }
    for(int i = 2; i <= n; i ++ ) {
        cin >> A[i];
    }
    dfs(1, 0);
    ll high;
    for(int i = 1; i <= lar; i ++ ){
        for(auto x : lay[i]){
            dp[x]=dp[par[x]]+max(mx[i]-A[x],A[x]-low[i]);
        }
        vector<pii> R;
        for(auto x : lay[i]){
            R.push_back(mp(A[x], x));
        }
        sort(R.begin(), R.end());
        high = -inf;
        for(auto x : R){
            dp[x.se] = max(dp[x.se], high + x.fi);
            high = max(high, dp[par[x.se]] - x.fi);
        }
        high = -inf;
        reverse(R.begin(), R.end());
        for(auto x : R){
            dp[x.se] = max(dp[x.se], high - x.fi);
            high = max(high, dp[par[x.se]] + x.fi);
        }

    }
    ll soln = 0;
    for(int i = 1; i <= n; i ++ ) soln = max(soln, dp[i]);
    cout << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}