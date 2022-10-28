#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, b[MAXN][2];
vector<int> adj[MAXN];
ll a[MAXN];

ar<ll, 5> dfs(int c=0, int p=-1){ //{have 0's, need 0's, have 1's, need 1's, ans}
    if (c) a[c]=min(a[c], a[p]);
    ar<ll, 5> ans; ans.fill(0);

    if (b[c][0] != b[c][1]){
        if (b[c][0]==0) ans[0]++, ans[3]++;
        else ans[2]++, ans[1]++;
    }

    for (auto nxt : adj[c]) if (nxt != p){
        ar<ll, 5> v=dfs(nxt, c);
        for (int j = 0; j < 5; j++) ans[j] += v[j];
    }
    ll pair_0 = min(ans[0], ans[1]), pair_1 = min(ans[2], ans[3]);
    ans[0] -= pair_0, ans[1] -= pair_0, ans[2] -= pair_1, ans[3] -= pair_1;
    ans[4] += a[c]*(pair_0 + pair_1);
    return ans;
}
void solve(){
    cin >> n;
    int cnt1[2]={}, cnt2[2]={};
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i][0] >> b[i][1], cnt1[b[i][0]&1]++, cnt2[b[i][1]&1]++;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    if (cnt1[0]!=cnt2[0]||cnt1[1]!=cnt2[1]){ cout << -1 << '\n'; return; }
    ll ans=dfs()[4];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}