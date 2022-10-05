#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<int> a, b;
vector<ll> w;
set<int> pos;

void check(int ind) {
	if (ind < 0 || ind >= n - 1) return;
	if (pos.count(ind)) pos.erase(ind);
	if (!w[ind]) return;
	if (w[ind] > 0) {
		if (ind == 0 && a[ind] == 1) return;
		if (a[ind] && a[ind + 1]) pos.insert(ind);
	}
	else {
		if (a[ind] < 9 && a[ind + 1] < 9) pos.insert(ind);
	}
}

void work(int ind) {
	if (!w[ind]) return; // wtf?
	if (w[ind] > 0) {
		cout << ind + 1 << " -1\n";
		a[ind]--;
		a[ind + 1]--;
		w[ind]--;
	}
	else {
		cout << ind + 1 << " 1\n";
		a[ind]++;
		a[ind + 1]++;
		w[ind]++;
	}
	check(ind - 1);
	check(ind);
	check(ind + 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	w.resize(n - 1);
	char tmp;
	for (auto &i : a) cin >> tmp, i = tmp - '0';
	for (auto &i : b) cin >> tmp, i = tmp - '0';
	ll count = 0;
	w[0] = a[0] - b[0];
	count += abs(w[0]);
	for (int i = 1; i < n - 1; i++) {
		w[i] = a[i] - w[i - 1] - b[i];
		count += abs(w[i]);
	}
	if (a[n - 1] - w[n - 2] - b[n - 1] != 0) finish(-1);
	cout << count << '\n';
	count = min(count, 100000LL);
	for (int i = 0; i < n - 1; i++) check(i);
	while (count--) {
		if (!pos.size()) finish("wtf");
		work(*pos.begin());
	}
}