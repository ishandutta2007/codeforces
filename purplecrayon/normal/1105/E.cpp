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
typedef unsigned long long ull;
const int MAXN = 1e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m;
string ev[MAXN];
map<string, int> mp;
string rmp[MAXM];
ull bad[MAXM];
int dp[1<<(MAXM/2)]; //WARNING: change to short if needed

void solve(){
    cin >> n >> m; memset(bad, 0, sizeof(bad)); 
    for (int i = 0; i < n; i++){
        int ty; cin >> ty;
        if (ty == 1) ev[i] = "";
        else cin >> ev[i], mp[ev[i]]++;
    }
    int cc=0; for (auto& it : mp) it.second = cc++, rmp[it.second] = it.first;
    ll vm=0;
    for (int i = 0; i < n; i++){
        if (sz(ev[i])) vm |= 1ll<<mp[ev[i]];
        else {
            for (int j = 0; j < m; j++) if ((vm>>j)&1) bad[j] |= vm;
            vm = 0;
        }
    }
    if (vm){
        for (int j = 0; j < m; j++) if ((vm>>j)&1) bad[j] |= vm;
        vm=0;
    }
    assert(!vm);
    for (int i = 0; i < m; i++) bad[i] &= ~(1ll<<i);
    //for (int i = 0; i < m; i++) cerr << i << ' ' << bad[i] << '\n';
    int l=m/2, r=m-l; memset(dp, 0, sizeof(dp));
    for (int i = 0; i < (1<<l); i++){
        int c=0;
        for (int j = 0; j < l; j++) if (i&(1<<j)) c |= ((1ll<<l)-1)&bad[j];
        if (i&c) continue;
        dp[i] = __builtin_popcount(i);
    }
    for (int i = 0; i < (1<<l); i++) for (int j = 0; j < l; j++) if (i&(1<<j)) dp[i] = max(dp[i], dp[i^(1<<j)]);
    //for (int i = 0; i < (1<<l); i++) cerr << i << ' ' << dp[i] << '\n';
    int ans=0;
    for (int i = 0; i < (1<<r); i++){
        int c=0;
        for (int j = 0; j < r; j++) if (i&(1<<j)) c |= bad[l+j]>>l;
        if (i&c) continue;
        //cerr << i << '\n';
        c = 0;
        for (int j = 0; j < r; j++) if (i&(1<<j)) c |= ((1ll<<l)-1)&bad[l+j];
        ans = max(ans, __builtin_popcount(i)+dp[((1<<l)-1)^c]);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}