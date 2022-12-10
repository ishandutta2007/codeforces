//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) x = min(x, y)

const int maxn = 1e5 + 10;
LL gco[maxn],
   cst[maxn];
string str[maxn];
int n, k, m;
map<string, LL> mp;

int main() {
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = 0; i < n; i++)
		cin >> cst[i];
	for (int i = 0; i < k; i++) {
		gco[i] = 1e9 + 10;
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x, x--;
			mp[str[x]] = i;
			smin(gco[i], cst[x]);
		}
	}
	LL ans = 0;
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		ans += gco[mp[tmp]];
	}
	cout << ans << endl;
	return 0;
}