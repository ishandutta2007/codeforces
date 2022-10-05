#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

typedef complex<double> cd;

vector<cd> fft(const vector<cd> &a, int c) {
	int n = a.size();
	vector<cd> roots(n);
	for (int i = 0; i < n; i++)
		roots[i] = cd(cos(c * 2 * pi * i / n), sin(c * 2 * pi * i / n));

	vector<cd> rtn = a, tmp;
	for (int i = n / 2; i >= 1; i /= 2) {
		tmp.resize(n / i);
		for (int j = 0; j < i; j++) {
			for (int k = j, k2 = j; k < n; k += i, k2 = (k2 + 2 * i) % n) {
				tmp[k / i] = rtn[k2] + roots[k - j] * rtn[k2 + i];
			}
			for (int k = j; k < n; k += i)
				rtn[k] = tmp[k / i];
		}
	}
	return rtn;
}

vector<ll> mult(const vector<ll> a, const vector<ll> b) {
	vector<cd> p1, p2;
	ll n = a.size() + b.size();
	while (n != (n & -n)) n += (n & -n);
	for (auto &i : a) p1.push_back(cd(i, 0));
	for (auto &i : b) p2.push_back(cd(i, 0));
	while (p1.size() < n) p1.push_back(cd(0, 0));
	while (p2.size() < n) p2.push_back(cd(0, 0));

	vector<cd> f1 = fft(p1, 1), f2 = fft(p2, 1), f3(n);
	for (int i = 0; i < n; i++)
		f3[i] = f1[i] * f2[i];
	f3 = fft(f3, -1);
	vector<ll> rtn(n);
	for (int i = 0; i < n; i++) rtn[i] = round(f3[i].real() / n);
	while (rtn.size() && rtn.back() == 0) rtn.pop_back();
	return rtn;
}

int n, x;
vector<ll> a, c, d;

int main() {
	fast;
	cin >> n >> x;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		if (i < x) i = 1;
		else i = 0;
	}
	a.insert(a.begin(), 0);
	n++;
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	c.resize(n, 0);
	for (auto &i : a) c[i]++;
	d = c;

	reverse(d.begin(), d.end());
	vector<ll> rtn = mult(c, d);
	while (rtn.size() > n) rtn.pop_back();
	reverse(rtn.begin(), rtn.end());

	ll first = 0;
	for (const auto &i : c) first += (i * (i - 1) / 2);
	cout << first << " ";
	for (int i = 1; i < rtn.size(); i++) cout << rtn[i] << " "; cout << endl;
}