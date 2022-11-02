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
const int max_n = 1e5 + 3;

vector<int> gr[max_n];

int used[max_n];

bool dfs(int v) {
	if (used[v] == 2) return false;
	if (used[v] == 1) return true;
	used[v] = 1;
	for(int i : gr[v]) {
		if (dfs(i)) return true;
	}
	used[v] = 2;
	return false;
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;

    	for(int i = 0;i <= n;i++) {
    		gr[i].clear();
    		used[i] = 0;
    	}

    	vector<int> a, b;
    	vector<int> rev(n + 1);

    	for(int i = 0;i < m;i++) {
    		int x, y;
    		cin >> x >> y;
    		if (x == y) continue;
    		a.emplace_back(x);
    		b.emplace_back(y);
    		rev[y] = x;
    	}
    	for(int i = 0;i < sz(a);i++) {
    		if (rev[a[i]] != 0) {
    			gr[a[i]].emplace_back(rev[a[i]]);
    		}
    	}

    	int res = sz(a);
    	for(int i = 0;i <= n;i++) {
    		if (used[i] == 0 && dfs(i)) res++;
    	}
    	cout << res << endl;
    }
}