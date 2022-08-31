#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7;
vi a[N];
int n, m, x[N];
bool vis[N];
void solve (int o) {
	if (o == n + 1) {
		cout << "Yes\n";
		L(i, 1, m) cout << x[i] << ' ';
		cout << '\n';
		exit (0);
	}
	vi neq, valx, valy;
	L(i, 1, m) if(x[i] != a[o][i]) neq.push_back(i), valx.push_back(x[i]), valy.push_back(a[o][i]);
	if (sz(neq) >= 5) return ;
	if (sz(neq) >= 3) {
		int u = sz(neq);
		L(i, 1, (1 << u) - 1) {
			int r = __builtin_popcount (i);
			bool ok = true;
			L(j, 0, sz(neq) - 1) if((i >> j & 1) && vis[neq[j]]) ok = false;
			if(!ok) continue;
			L(j, 0, sz(neq) - 1) if(i >> j & 1) vis[neq[j]] = true;
			if(sz(neq) - r <= 2) {
				L(j, 0, sz(neq) - 1) if(i >> j & 1)
					x[neq[j]] = valy[j];
				solve (1);
				L(j, 0, sz(neq) - 1) if(i >> j & 1) 
					x[neq[j]] = valx[j];
			}
			L(j, 0, sz(neq) - 1) if(i >> j & 1) vis[neq[j]] = false;
		}
	}
	else solve (o + 1);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) {
		a[i].resize (m + 1);
		L(j, 1, m) cin >> a[i][j];
	}
	L(i, 1, m) x[i] = a[1][i];
	solve (1);
	cout << "No\n";
	return 0;
}