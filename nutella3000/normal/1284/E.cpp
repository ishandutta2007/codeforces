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
const int max_n = 3e3 + 3;

int cross(pii v1, pii v2) {
	return v1.fi * v2.se - v1.se * v2.fi;
}

void solve() {
	int n;
	cin >> n;
	vector<pii> a(n);
	for(int i = 0;i < n;i++)
		cin >> a[i].fi >> a[i].se;
	int res = 0;
	for(int i = 0;i < n;i++) {
		vector<pii> v;
		for(int j = 0;j < n;j++) {
			if (i != j) v.emplace_back(a[j].fi - a[i].fi, a[j].se - a[i].se);
		}

		--n;

		stable_sort(all(v), [](auto v1, auto v2) {
			bool t1 = v1 < pii(0, 0);
			bool t2 = v2 < pii(0, 0);
			if (t1 != t2) return t1 < t2;
			return cross(v1, v2) > 0;
		});


		int id = 0;
		for(int k = 0;k < n;k++) {
			while(id < n + k && cross(v[k], v[id % n]) >= 0) {
				id++;
			}
			int num = (n + k - id);
			res += num * (num - 1) * (num - 2) / 2 / 3;
		}

		++n;
	}
	cout << n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 2 / 3 / 4 - res << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}