#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e9 + 4;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> w(n), deg(n);
		for(int i = 0;i < n;i++)
			cin >> w[i];
		for(int i = 0;i < n - 1;i++) {
			int v1, v2;
			cin >> v1 >> v2;
			v1--; v2--;
			deg[v1]++;
			deg[v2]++;
		}

		int res = 0;
		for(int i = 0;i < n;i++) {
			res += w[i];
			deg[i]--;
		}
		vector<int> id(n);
		iota(all(id), 0);
		sort(all(id), [&w](int v1, int v2) {return w[v1] > w[v2];});

		int _id = 0;
		cout << res << " ";
		for(int i = 1;i < n - 1;i++) {
			while(deg[id[_id]] == 0) _id++;
			res += w[id[_id]];
			deg[id[_id]]--;
			cout << res << " ";
		}
		cout << endl;
	}    
}