#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, l;
int ans = 0, a[100005];

int main() {
	fast;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] <= l && a[i] > l) ans++;
	}

	int par[3];
	while (m--) {
		cin >> par[0];
		if (par[0] == 0) cout << ans << endl;
		else {
			cin >> par[1] >> par[2];
			if (a[par[1]] <= l) {
				a[par[1]] += par[2];
				if (a[par[1]] > l) {
					if (a[par[1] - 1] <= l) {
						if (a[par[1] + 1] <= l) {
							ans++;
						}
					}
					else {
						if (a[par[1] + 1] > l) ans--;
					}
				}
			}
		}
	}
}