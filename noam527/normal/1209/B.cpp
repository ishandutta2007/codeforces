#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
string s;
int ans[1005] = {};

void add(int l, int r) {
	for (int i = l; i <= r; i++) ans[i]++;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int state = s[i] - '0', lst = 0;
		for (int j = b; j <= 1000; j += a) {
			if (state) add(lst, j - 1);
			state ^= 1;
			lst = j;
		}
		if (state) add(lst, 1000);
	}
	int mx = 0;
	for (int i = 0; i < 1005; i++) mx = max(mx, ans[i]);
	finish(mx);
}