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
LL a[maxn],
   quer[maxn],
   ans[maxn];
int ord[maxn],
	n, q;
set<pll> s;

bool cmp(int i, int j) {
	return quer[i] < quer[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	cin >> q;
	for (int i = 0; i < q; i++) {
		LL fi, se;
		cin >> fi >> se;
		quer[i] = se - fi;
	}
	iota(ord, ord + q, 0);
	sort(ord, ord + q, cmp);

	for (int i = 1; i < n; i++)
		s.insert(MP(a[i] - a[i - 1] - 1, i - 1));

	LL cur = n;
	LL prv = 0;
	for (int i = 0; i < q; i++) {
		int id = ord[i];
		while (sz(s) and s.begin()->L <= quer[id]) {
			cur += s.begin()->L - prv;
			s.erase(s.begin());
		}
		cur += (quer[id] - prv) * (1LL + sz(s));
		ans[id] = cur;
		prv = quer[id];
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}