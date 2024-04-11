#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

void solve() {
	pii mn, mx;
	cin >> mn.ff >> mn.ss >> mx.ff >> mx.ss;
	for (int i = 1; i <= 50; i++) {
		if (mn.ff <= i && i <= mn.ss && mx.ff <= i && mx.ss >= i) {
			cout << i << '\n';
			return;
		}
	}
	cout << mn.ff + mx.ff << '\n';
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}