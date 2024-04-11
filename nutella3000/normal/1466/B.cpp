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
		int res = 0;
		map<int, int> a;
		for(int i = 0;i < n;i++) {
			int v;
			cin >> v;
			a[v]++;
		}
		res = sz(a);
		bool pr = false;
		for(pii i : a) {
			if ((pr || i.se > 1) && !a.count(i.fi + 1)) res++;

			if (!a.count(i.fi + 1)) pr = false;
			else if (i.se > 1 || pr) pr = true;
		}
		cout << res << endl;
	}    
}