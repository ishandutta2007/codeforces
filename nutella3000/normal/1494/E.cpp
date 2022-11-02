#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define all(b) b.begin(), b.end()
#define fi first
#define se second
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 2e5 + 3;


map<pii, string> adj;
set<pii> both, same;

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int v1, v2, k;
		string s, c;
		cin >> s;
		if (s == "+") {
			cin >> v1 >> v2 >> c;
			--v1, --v2;
			pii t1 = mp(v1, v2), t2 = mp(v2, v1), t3 = mp(min(v1, v2), max(v1, v2));
			adj[t1] = c;
			if (adj.count(t2)) {
				both.emplace(t3);
				if (adj[t2] == c) {
					same.emplace(t3);
				}
			}
		}else if (s == "-") {
			cin >> v1 >> v2;
			--v1, --v2;
			pii t1 = mp(v1, v2), t2 = mp(v2, v1), t3 = mp(min(v1, v2), max(v1, v2));
			string c = adj[t1];
			adj.erase(t1);
			same.erase(t3), both.erase(t3);
		}else {
			cin >> k;
			k--;
			if (size(same) || (k % 2 == 0 && size(both))) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}