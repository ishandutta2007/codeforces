#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
const int OO = 1;
using namespace std;

int n, q;
int s[5005], e[5005];
int a[5005] = {}, b[5005] = {};

void clear() {
	for (int i = 0; i < 5005; i++) a[i] = 0;
}
void color(int l, int r) {
	a[l]++, a[r + 1]--;
}
void ps() {
	for (int i = 1; i < 5005; i++) a[i] += a[i - 1];
}
void pre() {
	for (int i = 0; i < 5005; i++)
		b[i] = (a[i] == 1 ? 1 : 0);
	for (int i = 1; i < 5005; i++) b[i] += b[i - 1];
}
int query(int l, int r) {
	return b[r] - b[l - 1];
}
int best(int exc) {
	int rtn = 1e9;
	for (int i = 0; i < q; i++)
		if (i != exc)
			rtn = min(rtn, query(s[i], e[i]));
	return rtn;
}
int total() {
	int rtn = 0;
	for (int i = 0; i < 5005; i++)
		if (a[i] > 0) rtn++;
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < q; i++) cin >> s[i] >> e[i];

	int ans = -1;
	for (int i = 0; i < q; i++) {
		clear();
		for (int j = 0; j < q; j++)
			if (i != j) color(s[j], e[j]);
		ps();
		pre();
		ans = max(ans, total() - best(i));
	}
	finish(ans);
}