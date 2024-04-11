#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 5005;

vector<int> x;

void gen() {
	x.resize(N);
	for (int i = 3; i < N; i++)
		x[i] = (i - 2) + x[i - 2];
}

int st = 900000000;

int n, m;
vector<int> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	if (n <= 2) {
		if (m != 0) finish(-1);
		for (int i = 1; i <= n; i++) cout << i << " "; cout << '\n';
		return 0;
	}
	ans = { 1, 2 };
	for (int i = 3; i <= n; i++) {
		if (m == 0) {
			ans.push_back(st);
			st += 10000;
		}
		else {
			int cur = (i - 1) / 2;
			if (cur <= m) {
				m -= cur;
				ans.push_back(i);
			}
			else {
				cur = i;
				while (m < (i - 1) / 2)
					cur += 2, m++;
				ans.push_back(cur);
				m = 0;
			}
		}
	}
	if (m > 0) finish(-1);
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}