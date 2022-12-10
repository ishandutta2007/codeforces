//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10;
const LL Mod = 998244353;
int deg[maxn],
	n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(deg, -1, sizeof deg);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		deg[fi]++;
		deg[se]++;
	}
	deg[0]++;
	LL ans = n;
	for (int i = 0; i < n; i++) {
		if (i and deg[i])
			ans = (ans * (1 + deg[i])) % Mod;
		for (int j = 1; j <= deg[i]; j++)
			ans = (ans * j) % Mod;
	}
	cout << ans << endl;
	return 0;
}