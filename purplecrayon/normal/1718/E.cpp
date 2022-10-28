#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

struct DSU {
	vector<int> p, sz;
	void init(int n) { 
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
	int find_set(int v) { 
        return v == p[v] ? v : p[v] = find_set(p[v]);
    }
	bool union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a, sz[a] += sz[b], sz[b] = 0;
		return true;
	}
} da, db;


#include<bits/extc++.h>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

auto get_swaps(vector<int> p) {
    int n = sz(p);
    vector<int> inv(n);
    for (int i = 0; i < n; i++) inv[p[i]] = i;
    
    vector<bool> vis(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        vector<int> cyc;
        int c = i;
        while (!vis[c]) {
            vis[c] = 1;
            cyc.push_back(c);
            c = inv[c];
        }
        for (int i = 1; i < sz(cyc); i++) {
            ans.emplace_back(cyc[0], cyc[i]);
        }
        // swap a, p[a], you take p[a] out of the cycle
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
auto fill_empty(vector<int> ans) {
    int n = sz(ans);
    vector<bool> unused(n, 1);
    for (int i = 0; i < n; i++) if (ans[i] != -1) unused[ans[i]] = 0;
    vector<int> fill;
    for (int i = 0; i < n; i++) if (unused[i]) fill.push_back(i);
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = fill.back();
            fill.pop_back();
        }
    }
    return ans;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) for (auto& c : r) cin >> c;
    vector<vector<int>> b(n, vector<int>(m));
    for (auto& r : b) for (auto& c : r) cin >> c;
    bool flipped = 0;
    if (n > m) {
        flipped = true;
        vector<vector<int>> na(m, vector<int>(n));
        vector<vector<int>> nb(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                na[j][i] = a[i][j];
                nb[j][i] = b[i][j];
            }
        }
        swap(na, a), swap(nb, b);
        swap(n, m);
    }

    da.init(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < m; k++) if (a[i][k] && a[j][k]) {
                da.union_sets(i, j);
                // cerr << "merge: " << i << ' ' << j << endl;
            }
        }
    }
    db.init(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < m; k++) if (b[i][k] && b[j][k]) {
                db.union_sets(i, j);
                // cerr << "merge: " << i << ' ' << j << endl;
            }
        }
    }
    vector<hash_map<int, int>> loc_b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (b[i][j])
            loc_b[i][b[i][j]] = j;
    }

    vector<hash_map<int, int>> which_b(m);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) if (b[i][j])
            which_b[j][b[i][j]] = i;
    }


    vector<int> ans(m, -1);
    vector<int> who(n, -1);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) if (da.p[i] == i) {
        // cerr << "on_i: " << i << endl;
        // fixing one fixes the rest
        // brute force over one O(N)
        // the rest I need to do in O(nM + n^2)
        vector<int> use;
        for (int j = 0; j < n; j++) if (da.find_set(j) == i)
            use.push_back(j);

        vector<vector<int>> has(m);
        for (int j : use) {
            for (int k = 0; k < m; k++) if (a[j][k])
                has[k].push_back(j);
        }
        bool has_nonz = 0;
        for (int x : a[i]) if (x) has_nonz = 1;
        if (!has_nonz) continue;

        // for (int x : use) cerr << x << ' ';
        // cerr << endl;

        bool finished_comp = 0;
        for (int me = 0; me < n; me++) {
            int root = db.find_set(me);
            if (db.sz[root] != sz(use)) continue;
            bool bad = 0;

            vector<bool> pushed(m);
            queue<int> q; q.push(i);
            for (int j : use) vis[j] = 0, who[j] = -1;
            vis[i] = 1;

            vector<int> cur(m, -1);
            for (int k = 0; k < m; k++) if (a[i][k]) {
                if (loc_b[me].find(a[i][k]) == loc_b[me].end()) {
                    bad = 1;
                    break;
                }
                    
                cur[k] = loc_b[me][a[i][k]]; // loc of a[i][k] in b[me]
            }

            // for (int x : cur) cerr << x << ' ';
            // cerr << endl;

            while (sz(q) && !bad) {
                int c = q.front(); q.pop();
                // cerr << "start: " << c << endl;
                for (int k = 0; k < m; k++) if (a[c][k] && cur[k] != -1) {
                    // cerr << "> " << k << ' ' << cur[k] << endl;
                    if (which_b[cur[k]].find(a[c][k]) == which_b[cur[k]].end()) {
                        bad = 1;
                        break;
                    }

                    who[c] = which_b[cur[k]][a[c][k]]; // which array in b has a[c][k] in the cur[k]th position
                    break;
                }
                // cerr << "q: " << c << endl;
                if (who[c] == -1) {
                    bad = 1;
                    break;
                }
                if (bad) break;

                for (int k = 0; k < m; k++) if (a[c][k] && cur[k] == -1) {
                    if (loc_b[who[c]].find(a[c][k]) == loc_b[who[c]].end()) {
                        bad = 1;
                        break;
                    }

                    cur[k] = loc_b[who[c]][a[c][k]]; // loc of a[c][k] in b[who[c]]
                }
                for (int k = 0; k < m; k++) if (a[c][k] && !pushed[k]) {
                    pushed[k] = 1;
                    for (int nxt : has[k]) if (!vis[nxt]) {
                        vis[nxt] = 1;
                        q.push(nxt);
                    }
                }
                // cerr << "end q: " << c << endl;
            }
            /*
            cerr << "done\n";
            cerr << "perm: ";
            for (int x : cur) cerr << x << ' ';
            cerr << endl;
            cerr << "who\n";
            for (int x : who) cerr << x << ' ';
            cerr << endl;
            */

            if (bad) continue;

            for (int j : use) if (db.find_set(who[j]) != root) {
                bad = 1;
                break;
            }
            for (int j : use) {
                if (bad) break;

                vector<int> my_new(m);
                for (int k = 0; k < m; k++) if (a[j][k]) {
                    assert(cur[k] != -1);
                    my_new[cur[k]] = a[j][k];
                }

                
                if (my_new != b[who[j]]) {
                    bad = 1;
                }
                // if (bad) cerr << "failed check: " << j << endl;
            }
            if (bad) continue;
            // cerr << "YAY!!!!!!!!!!!!!!!!!!\n";

            for (int j = 0; j < m; j++) if (cur[j] != -1)
                ans[j] = cur[j];


            finished_comp = 1;
            break;
        }
        if (!finished_comp) {
            cout << -1 << '\n';
            return;
        }
    }
    // cerr << "finished perms\n";
    // for (int x : ans) cerr << x << ' ';
    // cerr << endl;

    /*
    cerr << "rows: "; for (int x : who) cerr << x << ' ';
    cerr << endl;
    cerr << "cols: "; for (int x : ans) cerr << x << ' ';
    cerr << endl;
    */

    ans = fill_empty(ans), who = fill_empty(who);
    auto two = get_swaps(ans);
    auto one = get_swaps(who);
    cout << sz(two) + sz(one) << '\n';
    for (auto [x, y] : two) {
        int cur = 2;
        if (flipped) cur = 1;
        cout << cur << ' ' << x+1 << ' ' << y+1 << '\n';
    }
    for (auto [x, y] : one) {
        int cur = 1;
        if (flipped) cur = 2;
        cout << cur << ' ' << x+1 << ' ' << y+1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}