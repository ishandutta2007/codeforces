#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	vector<int> deg(n, 0);
	vector<set<int>> mydat(n);
	foru(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	foru(i, 0, n) {
		for (int x : adj[i]) {
			if (deg[x] == 1) {
				mydat[i].insert(x);
			}
		}
	}
	set<pii, greater<pii>> pq;
	foru(i, 0, n)pq.insert({ mydat[i].size(),i });
	int tot = 0;
	while (!pq.empty()) {
		pii x = *pq.begin(); pq.erase(x);
		int i = x.second, amt = x.first;
		if (deg[i] == 0)continue;
		if (mydat[i].size() < k)break;
		foru(it, 0, k) {
			int cou = *mydat[i].begin();
			mydat[i].erase(cou);
			deg[i]--;
			deg[cou]--;
		}
		tot++;
		if (deg[i] == 1) {
			for (int x : adj[i]) {
				if (deg[x] != 0) {
					pq.erase({ mydat[x].size(),x });
					mydat[x].insert(i);
					pq.insert({ mydat[x].size(),x });
				}
			}
		}
		pq.insert({ amt - k,i });
	}
	cout << tot << '\n';
	
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}