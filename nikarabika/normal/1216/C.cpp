//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<pll, pll> rect;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

rect get() {
	rect res;
	cin >> res.L.L >> res.R.L >> res.L.R >> res.R.R;
	return res;
}

pll inter(pll s1, pll s2) {
	pll res;
	res.L = max(s1.L, s2.L);
	res.R = min(s1.R, s2.R);
	if (res.R < res.L)
		res.R = res.L;
	return res;
}

rect inter(rect r1, rect r2) {
	return MP(inter(r1.L, r2.L), inter(r1.R, r2.R));
}

LL s(rect r) {
	return 1LL * (r.L.R - r.L.L) * (r.R.R - r.R.L);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	auto w = get();
	auto b1 = get(),
		 b2 = get();
	b1 = inter(w, b1);
	b2 = inter(w, b2);
	auto b3 = inter(b1, b2);
	if (s(w) == s(b1) + s(b2) - s(b3))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}