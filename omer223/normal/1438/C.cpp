#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;

const int sz = 1e3;
int n, m;
int a[sz][sz], b[sz][sz];

void solve() {
	cin >> n >> m;
	vector<pair<int, vector<pii>>> v;
	unordered_map<int, int> mem;
	foru(i, 0, n) {
		foru(j, 0, m) {
			cin >> a[i][j];
			if (mem.find(a[i][j]) == mem.end()) {
				mem[a[i][j]] = v.size();
				v.pb({ a[i][j],{{i,j}} });
			}
			else v[mem[a[i][j]]].second.pb({ i,j });
		}
	}
	sort(v.begin(), v.end());
	foru(ind, 0, v.size()) {
		bool odd = ind & 1;
		for (pii x : v[ind].second) {
			int i = x.first, j = x.second;
			if ((i + j) & 1 and odd or (i + j) % 2 == 0 and not odd)a[i][j]++;
		}
	}
	foru(i, 0, n) {
		foru(j, 0, m)cout << a[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}