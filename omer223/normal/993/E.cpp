#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <numeric>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using cd = complex<ld>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
	int n = a.size();
	if (n == 1)
		return;

	vector<cd> a0(n / 2), a1(n / 2);
	for (int i = 0; 2 * i < n; i++) {
		a0[i] = a[2 * i];
		a1[i] = a[2 * i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	ld ang = 2 * PI / n * (invert ? -1 : 1);
	cd w(1), wn(cos(ang), sin(ang));
	for (int i = 0; 2 * i < n; i++) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) {
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++)
		fa[i] *= fb[i];
	fft(fa, true);

	vector<ll> result(n);
	for (int i = 0; i < n; i++)
		result[i] = round(fa[i].real());
	return result;
}

const int sz = 2e5;
bool p[sz];
int n;
vector<ll> poly;

void input() {
	int x, tmp;
	ll sm = 0, cur = 1;
	cin >> n >> x;
	foru(i, 0, n) {
		cin >> tmp;
		p[i] = (tmp < x);
		if (!p[i])cur++;
		else {
			poly.pb(cur);
			sm += ((cur)*(cur - 1)) / 2;
			cur = 1;
		}
	}
	poly.pb(cur);
	sm += ((cur)*(cur - 1)) / 2;
	cout << sm << ' ';
}

int main() {
	fast;
	input();
	vector<ll> revPoly = poly;
	int deg = revPoly.size() - 1;
	reverse(revPoly.begin(), revPoly.end());
	vector<ll> ret = multiply(poly, revPoly);
	int retSize = ret.size(), ind = deg + 1;
	while (ind - deg <= n) {
		if (ind >= retSize)cout << 0 << ' ';
		else cout << ret[ind] << ' ';
		ind++;
	}
	return 0;
}