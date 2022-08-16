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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, m, k;
vector<ar<int, 3>> ed;
ll d[1010][1010];

void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c, --a, --b;
        ed.push_back({c, a, b});
    }
    sort(ed.begin(), ed.end());
    while (sz(ed) > k) ed.pop_back();
    m = min(m, k);

    map<int, int> mp;
    for (auto it : ed) mp[it[1]]++, mp[it[2]]++;
    int cc=0;
    for (auto& it : mp) it.second = cc++;
    for (auto& it : ed) it[1] = mp[it[1]], it[2] = mp[it[2]];
    n = cc;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        d[i][j] = (i != j ? ll(1e18) : 0);

    for (int i = 0; i < m; i++) {
        for (int rep : {0, 1}) {
        d[ed[i][1]][ed[i][2]] = min<ll>(d[ed[i][1]][ed[i][2]], ed[i][0]);
        swap(ed[i][1], ed[i][2]);
        }
    }

for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
    vector<ll> v;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if (d[i][j] < ll(1e18))
        v.push_back(d[i][j]);
    
    sort(v.begin(), v.end());
    cout << v[k-1] << '\n';
} 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}