#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
vector<int> need[sz], all[sz];
int inst[sz];

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	int whocol = -1;
	foru(i, 0, n) {
		need[i].clear();
		all[i].clear();
		cin >> a[i]; a[i]--;
	}
	foru(i, 0, n) {
		cin >> b[i]; b[i]--;
	}
	foru(i, 0, m) {
		cin >> c[i]; c[i]--;
	}
	foru(i, 0, n) {
		if (a[i] != b[i]) need[b[i]].pb(i);
		else all[b[i]].pb(i);
	}
	ford(i, m - 1, 0) {
		if (!need[c[i]].empty()) {
			inst[i] = need[c[i]].back(); need[c[i]].pop_back();
			if (whocol == -1)whocol = inst[i];
		}
		else if (!all[c[i]].empty()) {
			inst[i] = all[c[i]].back();
			if (whocol == -1)whocol = inst[i];
		}
		else {
			if (whocol != -1)inst[i] = whocol;
			else {
				cout << "NO\n";
				return;
			}
		}
	}
	foru(i, 0, n) {
		if (!need[i].empty()) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	foru(i, 0, m)cout << inst[i] + 1 << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}