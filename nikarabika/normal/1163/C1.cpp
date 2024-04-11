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

const int maxn = 1000 + 10;
int n;
pii a[maxn];
set<pair<pii, pll> > s;

pair<pii, pll> get_vector(pii a, pii b) {
	pii vec(a.L - b.L, a.R - b.R);
	if (vec.L < 0 or (vec.L == 0 and vec.R < 0)) {
		vec.L = -vec.L;
		vec.R = -vec.R;
	}
	int d = __gcd(vec.L, abs(vec.R));
	vec.L /= d;
	vec.R /= d;
	pll pnt;
	if (vec.L) {
		if (a.L > 0) {
			LL k = a.L / vec.L;
			pnt = pll(a.L - k * vec.L, a.R - k * vec.R);
		}
		else if (a.L == 0)
			pnt = a;
		else {
			LL k = (-a.L + vec.L - 1) / vec.L;
			pnt = pll(a.L + k * vec.L, a.R + k * vec.R);
		}
	}
	else {
		pnt = pll(a.L, 0);
	}
	return MP(vec, pnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].L >> a[i].R;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) {
			auto tmp = get_vector(a[i], a[j]);
			//cout << i << ' ' << j << ' ' << tmp.L.L << ' ' << tmp.L.R << ' ' << tmp.R.L << ' ' << tmp.R.R << endl;
			s.insert(tmp);
		}
	LL ans = 0;
	LL vis = 0;
	auto it = s.begin();
	while (vis < sz(s)) {
		LL cur = 0;
		pii curvec = it->L;
		while (it != s.end() and it->L == curvec)
			cur++, it++;
		ans += cur * vis;
		vis += cur;
	}
	cout << ans << endl;
	return 0;
}