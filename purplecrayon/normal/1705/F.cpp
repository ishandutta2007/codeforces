#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const int Q = 675;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

int hidden[N];

int n, start;
bool flip[N];

int cnt = 0;
int qry(vector<int> a) {
    cnt++; while (cnt > Q);
    for (int i = 0; i < n; i++) a[i] ^= flip[i];
    for (int i = 0; i < n; i++) cout << (a[i] ? 'T' : 'F');
    cout << endl;
    int ans; cin >> ans;
    ans = n - ans;
    /*
    int ans = 0;
    for (int i = 0; i < n; i++) ans += hidden[i] ^ a[i];
    */
    if (ans == 0) {
        cerr << cnt << endl;
        exit(0);
    }
    return ans;
}
vector<int> state;
void rec(vector<int> use) {
    if (sz(use) == 0) {
        return;
    }
    if (sz(use) % 2 == 1) {
        vector<int> he(n); he[use.back()] ^= 1;
        if (qry(he) < start) {
            state[use.back()] = 1;
        } else {
            state[use.back()] = 0;
        }
        use.pop_back();
        rec(use);
        return;
    }
    vector<pair<int, int>> link;
    vector<int> new_use;
    for (int i = 0; i < sz(use); i += 2) {
        vector<int> he(n);
        he[use[i]] = he[use[i+1]] = 1;
        int diff = qry(he) - start;
        if (diff == -2) {
            state[use[i]] = 1, state[use[i+1]] = 1;
        } else if (diff == 0) {
            link.emplace_back(use[i], use[i+1]);
            new_use.push_back(use[i]);
        } else if (diff == +2) {
            state[use[i]] = 0, state[use[i+1]] = 0;
        } else assert(false);
    }
    rec(new_use);
    for (auto [a, b] : link) {
        if (state[b] == -1) swap(a, b);
        assert(state[a] == -1 && state[b] != -1);
        state[a] = state[b] ^ 1;
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) hidden[i] = rnd(0, 1);
    for (int i = 0; i < n; i++) flip[i] = rnd(0, 1);
    start = qry(vector<int>(n));

    state.assign(n, -1);
    vector<int> use(n); iota(use.begin(), use.end(), 0);
    rec(use);
    qry(state);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}