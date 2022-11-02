#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000007
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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
	FAST;
	ll n, a, b;
	cin >> n >> a >> b;
	ll start = a + b;
	string s;
	cin >> s;
	vector<bool> free(n);
	for (int i = 0; i < n; ++i)
		free[i] = (s[i] == '.');
	if (a > b) swap(a, b);
	if (free[0]) s[0] = 'b', --b;
	for (int i = 1; i < n && (a > 0 || b > 0); ++i) {
		if (free[i]) {
			if (a > b) {
				if (s[i - 1] != 'a') {
					s[i] = 'a';
					--a;
				} else if (b > 0) {
					s[i] = 'b';
					--b;
				}
			} else {
				if (s[i - 1] != 'b') {
					s[i] = 'b';
					--b;
				} else if (a > 0) {
					s[i] = 'a';
					--a;
				}
			}
		}
	}
	cout << start - a - b;
    return 0;
}