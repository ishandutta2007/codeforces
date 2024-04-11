#include <bits/stdc++.h>
using namespace std;

vector<int> operator*(vector<int> a, vector<int> b) {
	int n = size(a);
	vector<int> c(n);
	for (int i = 0; i < n; i++) c[i] = b[a[i]];
	return c;
}

vector<int> power(vector<int> a, int k) {
	int n = size(a);
	vector<int> res(n);
	iota(begin(res), end(res), 0);
	for (; k > 0; k /= 2) {
		if (k%2 == 1) res = res*a;
		a = a*a;
	}
	return res;
}

int main() {
	int n; cin >> n;
	vector<int> p(n), a(n);
	for (int &x: p) cin >> x, x--;
	for (int &x: a) cin >> x, x--;

	set<int> s(begin(p), end(p));
	int deaths_per_round = n - ssize(s);
	int count = *max_element(begin(a), end(a)) + 1;
	int rounds = (count - n) / deaths_per_round;

	vector<int> q = power(p, rounds);
	set<int> avail;
	for (int i = 0; i < n; i++) avail.insert(i);
	for (int i: a) avail.erase(i);

	vector<int> last(n,-1);

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int j = q[i];

		if (last[j] == -1) {
			b[i] = a[j];
		} else {
			int k = *avail.lower_bound(last[j]);
			b[i] = k;
			avail.erase(k);
		}
		last[j] = b[i];

		cout << b[i]+1 << " \n"[i+1==n];
	}
}