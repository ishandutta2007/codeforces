#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

namespace okwedook {
	#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
	#define FIXED cout << fixed << setprecision(12)
	#define ll long long
	#define ld long double
	#define pii pair<int, int>
	#define pll pair<ll, ll>
	#define graph vector<vector<int>>
	#define pb push_back
	#define pf push_front
	#define popb pop_back
	#define popf pop_front
	#define f first
	#define s second
	#define hashmap unordered_map
	#define hashset unordered_set
	#define eps 1e-9
	#define mod 1000000007
	#define inf 3000000000000000007ll
	#define sz(a) signed(a.size())
	#define all(a) a.begin(), a.end()
	#define rall(a) a.rbegin(), a.rend()

	#ifdef DEBUG
		mt19937 gen(857204);
	#else
		mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
	#endif

	template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
	template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
	template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
	template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
	template<class T> inline void sort(T &a) { sort(all(a)); }
	template<class T> inline void rsort(T &a) { sort(rall(a)); }
	template<class T> inline void reverse(T &a) { reverse(all(a)); }
	template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
	template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
	template<class T> inline T sorted(T a) { sort(a); return a; }
}; using namespace okwedook;

namespace debug {
	#ifdef DEBUG
		template<class T> T to_dbg(T x) { return x; }
		template<class T, class U> string to_dbg(pair<T, U> p) {
			stringstream ss;
			ss << '{' << p.f << ',' << p.s << '}';
			return ss.str();
		}
		string to_dbg(string s) { return "\"" + s + "\""; }
		template<class T> string to_dbg(vector<T> a) {
			stringstream ss;
			ss << '{';
			if (sz(a)) ss << to_dbg(a[0]);
			for (int i = 1; i < sz(a); ++i)
				ss << "," << to_dbg(a[i]);
			ss << '}';
			return ss.str();
		}
		template<class T>
		void dbgout(T x) { cout << to_dbg(x) << endl; }
		template<class T, class... U>
		void dbgout(T t, U... u) {
			cout << to_dbg(t) << ", ";
			dbgout(u...);
		}
		#define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
	#else
		#define dbg(...) 0
	#endif
}; using namespace debug;


void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    vector<ll> p(m);
    cin >> p;
    sort(p);
    for (int i = 1; i < m; ++i) p[i] += p[i - 1];
    graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    auto bfs = [&](int v) {
        vector<int> dist(n, -1);
        queue<int> que({v});
        dist[v] = 0;
        while (sz(que)) {
            auto f = que.front();
            que.pop();
            for (auto i : G[f])
                if (dist[i] == -1) {
                    dist[i] = dist[f] + 1;
                    que.push(i);
                }
        }
        return dist;
    };
    auto da = bfs(a), db = bfs(b), dc = bfs(c);
    dbg(da);
    dbg(db);
    dbg(dc);
    ll answer = inf;
    for (int v = 0; v < n; ++v) {
        int ans = da[v] + db[v] + dc[v];
        int add = db[v];
        dbg(v, ans, add);
        ll check = 0;
        if (ans <= m) {
            if (ans > 0) check += p[ans - 1];
            if (add > 0) check += p[add - 1];
            checkmin(answer, check);
        }
    }
    cout << answer << '\n';
}
 
signed main() {
    FAST; FIXED;
    int t;
    cin >> t;
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}