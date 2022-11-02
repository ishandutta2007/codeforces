#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000009
#define inf 1000000000000000007ll
#define intinf (1 << 31) - 1
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
	ll n, A, B, C, T;
	cin >> n >> A >> B >> C >> T;
	C -= B;
	vector<ll> t(n);
	for (auto &i : t) cin >> i, --i;
	sort(t.begin(), t.end());
	ll ans = n * A, secans = n * A;
	ll ptr = 0;
	for (int i = 0; i < T; ++i) {
		secans += C * ptr;
		while (ptr < n && t[ptr] == i) ++ptr;
	}
	cout << max(ans, secans);
    return 0;
}