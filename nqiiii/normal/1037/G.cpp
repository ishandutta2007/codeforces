#pragma GCC optimize("Ofast", "inline", "unroll-loops", "no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
map<int, int> sg[maxn + 10];
vector<pair<int, int> > sgg[maxn + 10];
char s[maxn + 10];
int b[maxn + 10], q, n;
int pre[maxn + 10][26], nxt[maxn + 10][26], xo[maxn + 10], cnt;
int f[2][maxn + 10], nowl, nowr;

void read(int &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = x * 10 + c - '0'; c = getchar();
	}		
}

int mex(int *a) {
	for (int i = 0; i < 26; ++i) b[a[i]] = 1;
	int ans = 0;
	while (b[ans]) ++ans;
	for (int i = 0; i < 26; ++i) b[a[i]] = 0;
	return ans;
}

int getsg(int l, int r) {
	if (l > r) return 0;
	map<int, int>::iterator it = sg[l].find(r);
	if (it != sg[l].end()) return it -> second;
	int lst[26], val[26], ans;
	for (int i = 0; i < 26; ++i) {
		lst[i] = l - 1; val[i] = 0;
	}
	for (int i = l; i <= r; ++i) {
		int c = s[i] - 'a';
		val[c] ^= getsg(lst[c] + 1, i - 1); lst[c] = i;
	}
	for (int i = 0; i < 26; ++i) {
		if (lst[i] >= l) val[i] ^= getsg(lst[i] + 1, r);
		else val[i] = 27;
	}
	sg[l].insert(make_pair(r, ans = mex(val)));
	return ans;
}

int gettruesg(int l, int r) {
	if (l > r) return 0;
	if (l != nowl && r != nowr) return lower_bound(sgg[l].begin(), sgg[l].end(), make_pair(r, 0)) -> second ;
	int &ans = l == nowl ? f[0][r] : f[1][l];
	if (ans != -1) return ans;
	int val[26];
	for (int i = 0; i < 26; ++i)
		if (pre[r][i] >= l) val[i] = gettruesg(l, nxt[l][i] - 1) ^ gettruesg(pre[r][i] + 1, r) ^ xo[nxt[l][i]] ^ xo[pre[r][i]];
		else val[i] = 27;
	return ans = mex(val);
}

int main() {
	scanf("%s", s + 1); read(q); n = strlen(s + 1);
	getsg(1, n);
	for (int i = 1; i <= n; ++i)
		for (auto j: sg[i]) sgg[i].push_back(j);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 26; ++j)
			pre[i][j] = s[i] == j + 'a' ? i : pre[i - 1][j];
	for (int i = n; i >= 1; --i)
		for (int j = 0; j < 26; ++j)
			nxt[i][j] = s[i] == j + 'a' ? i : nxt[i + 1][j];
	for (int i = 1; i <= n; ++i)
		xo[i] = xo[pre[i - 1][s[i] - 'a']] ^ getsg(pre[i - 1][s[i] - 'a'] + 1, i - 1);
	while (q--) {
		read(nowl); read(nowr);
		for (int i = 0; i < 26; ++i) {
			if (nxt[nowl][i]) f[0][nxt[nowl][i] - 1] = -1;
			if (pre[nowr][i]) f[1][pre[nowr][i] + 1] = -1;
		}
		f[0][nowr] = -1;
		puts(gettruesg(nowl, nowr) ? "Alice" : "Bob");
	}
}