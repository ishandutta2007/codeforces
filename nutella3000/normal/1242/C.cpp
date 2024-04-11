#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_k = 15;

int k;
set<int> a[max_k];
map<int, int> num_id;
int sum[max_k];
int mid;

vector<pip> cycle[(1 << max_k)];
int dp[(1 << max_k)];


bool scan() {
    int n, v;
    cin >> k;

    for(int i = 0;i < k;i++) {
        cin >> n;
        for(int j = 0;j < n;j++) {
            cin >> v;
            a[i].emplace(v);
            sum[i] += v;
            mid += v;
            num_id[v] = i;
        }
    }

    if (mid % k != 0) return false;
    mid /= k;
    return true;
}

void build_cycle(int st, int st_val) {
    int v = st, val = st_val;
    vector<bool> used(k);
    vector<pip> res;
    int mask = 0;

    while(true) {
        mask += (1 << v);
        used[v] = true;

        int new_val = mid - (sum[v] - val);
        if (!num_id.count(new_val)) return;
        int new_v = num_id[new_val];

        if (used[new_v]) {
            if ((new_v != st) || (new_v == st && new_val != st_val)) return;
            res.emplace_back(mp(st, mp(new_val, v)));
            break;
        }

        res.emplace_back(mp(new_v, mp(new_val, v)));

        v = new_v;
        val = new_val;
    }

    if (__builtin_popcount(mask) == 1) return;
    cycle[mask] = res;
}

int nalog(int num) {
    int res = 0;
    while((1 << res) != num) res++;
    return res;
}

void build_dp() {
    for(int mask = 0;mask < (1 << k);mask++) {
        if (mask != 0) dp[mask] = -1;
        for(int sub = mask;sub > 0;sub = ((sub - 1) & mask)) {
            if (cycle[sub].empty() || dp[mask ^ sub] == -1) continue;
            dp[mask] = sub;
            break; 
        }
    }
}

void solve() {
    if (!scan()) {
        cout << "No";
        return;
    }

    for(int i = 0;i < k;i++) {
        if (mid == sum[i]) {
            cycle[(1 << i)].emplace_back(mp(i, mp(*a[i].begin(), i)));
        }
    }

    for(int i = 0;i < k;i++) {
        for(int j : a[i])
            build_cycle(i, j);
    }

    /*for(int i = 0;i < (1 << k);i++) {
        cout << i << " " << sz(cycle[i]) << endl;
    }*/

    build_dp();

    int m = (1 << k) - 1;

    if (dp[m] == -1) {
        cout << "No";
        return;
    }

    cout << "Yes" << endl;
    vector<pip> res;
    while(m > 0) {
        res.insert(res.end(), all(cycle[dp[m]]));
        m = (m ^ dp[m]);
    }

    vector<pii> temp(k);
    for(auto i : res)
        temp[i.fi] = mp(i.se.fi, i.se.se + 1);

    for(auto i : temp)
        cout << i.fi << " " << i.se << endl;
}
    
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}