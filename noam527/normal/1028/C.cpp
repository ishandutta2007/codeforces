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

int n;
vector<vector<int>> a;
vector<pair<int, int>> r;
pair<int, int> x, y;

pair<int, int> rx() {
	pair<int, int> rtn = { -inf, inf };
	for (auto &i : r) {
		rtn.first = max(rtn.first, i.first);
		rtn.second = min(rtn.second, i.second);
	}
	return rtn;
}

int main() {
	fast;
	cin >> n;
	a.resize(n, vector<int>(4));
	for (auto &i : a) cin >> i[0] >> i[1] >> i[2] >> i[3];
	r.resize(n);
	for (int i = 0; i < n; i++)
		r[i] = { a[i][0], a[i][2] };
	x = rx();
	for (int i = 0; i < n; i++)
		r[i] = { a[i][1], a[i][3] };
	y = rx();
	if (x.first <= x.second && y.first <= y.second) {
		cout << x.first << " " << y.first << endl;
		return 0;
	}
	int at[2];
	int pos;
	if (x.first > x.second) {
		pos = 0;
		for (int i = 1; i < n; i++)
			if (a[i][0] > a[pos][0]) pos = i;
		at[0] = pos;
		pos = 0;
		for (int i = 1; i < n; i++)
			if (a[i][2] < a[pos][2]) pos = i;
		at[1] = pos;
	}
	else {
		pos = 0;
		for (int i = 1; i < n; i++)
			if (a[i][1] > a[pos][1]) pos = i;
		at[0] = pos;
		pos = 0;
		for (int i = 1; i < n; i++)
			if (a[i][3] < a[pos][3]) pos = i;
		at[1] = pos;
	}
	r.pop_back();
	int nxt = 0;
	for (int i = 0; i < n; i++)
		if (i != at[0])
			r[nxt++] = { a[i][0], a[i][2] };
	x = rx();
	nxt = 0;
	for (int i = 0; i < n; i++)
		if (i != at[0])
			r[nxt++] = { a[i][1], a[i][3] };
	y = rx();
	if (x.first <= x.second && y.first <= y.second) {
		cout << x.first << " " << y.first << endl;
		return 0;
	}

	nxt = 0;
	for (int i = 0; i < n; i++)
		if (i != at[1])
			r[nxt++] = { a[i][0], a[i][2] };
	x = rx();
	nxt = 0;
	for (int i = 0; i < n; i++)
		if (i != at[1])
			r[nxt++] = { a[i][1], a[i][3] };
	y = rx();
	if (x.first <= x.second && y.first <= y.second) {
		cout << x.first << " " << y.first << endl;
		return 0;
	}
}