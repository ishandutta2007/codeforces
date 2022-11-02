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
#include <random>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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

template<class T> struct Fenv {
    int N, LOG;
    T *fenv;
    Fenv(int N) {
        this->N = N;
        LOG = log2(N);
        fenv = new T[N];
        for (int i = 0; i < N; ++i) fenv[i] = 0;
    }
    void add(int r, T x) { //adds x to a[r]
        for (; r < N; r |= r + 1) fenv[r] += x;
    }
    T get(int r) { //sum of [0, r]
        T ans = 0;
        for (; r >= 0; r = (r & r + 1) - 1) 
            ans += fenv[r];
        return ans;
    }
    T get(int l, int r) { //sum of [l, r]
        return get(r) - get(l - 1);
    }
    int lb(T k) { //first index which sum is >= k
        int ans = -1;
        for (int l = LOG; l >= 0; --l) {
            int next = ans + (1 << l);
            if (next < N && k > fenv[next]) {
                ans = next;
                k -= fenv[next];
            }
        }
        return ans + 1;
    }
};

signed main() {
	FAST; FIXED; RANDOM;
	int n;
	cin >> n;
	vector<int> b(n);
	cin >> b;
	vector<pii> a(n);
	for (int i = 0; i < n; ++i) a[i] = {b[i], -i};
	sort(a);
	int m;
	cin >> m;
	vector<vector<pii>> query(n);
	vector<int> answer(m);
	for (int i = 0; i < m; ++i) {
		int k, pos;
		cin >> k >> pos;
		query[k - 1].pb({pos, i});
	}
	reverse(a);
	Fenv<int> st(n);
	for (int i = 0; i < n; ++i) {
		st.add(-a[i].s, 1);
		for (auto q : query[i])
			answer[q.s] = st.lb(q.f);
	}
	for (auto i : answer) cout << b[i] << '\n';
	return 0;
}