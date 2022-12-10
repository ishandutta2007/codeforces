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

const int maxn = 1e5 + 10;
LL s[maxn],
   mnval[maxn],
   chcnt[maxn];
int n,par[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	par[0] = -1;
	cin >> n;
	LL ans = 0;
	for (int i = 1; i < n; i++) {
		cin >> par[i], par[i]--;
		chcnt[par[i]]++;
	}
	memset(mnval, 63, sizeof mnval);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i] == -1)
			continue;
		if (i and s[par[par[i]]] > s[i])
			return cout << -1 << endl, 0;
		ans += s[i] - (i ? s[par[par[i]]] : 0);
		if (i)
			smin(mnval[par[i]], s[i]);
	}
	for (int i = 0; i < n; i++)
		if (s[i] == -1)
			ans -= (mnval[i] - s[par[i]]) * max(0LL, (chcnt[i] - 1));
	cout << ans << endl;
	return 0;
}