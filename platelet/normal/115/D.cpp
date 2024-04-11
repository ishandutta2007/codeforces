#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int P = 1e6 + 3;

int n, m, p[1005], id[2005], f[2005][1005];
uint64_t tmp[1005];
char s[2005], t[2005];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	for(auto i = s; *i; i++) if(!isdigit(*i) || i == s || !isdigit(i[-1]))
		t[++n] = *i == '+' || *i == '-' ? 1 : *i == '*' || *i == '/' ? 2 : 0;
	if(t[n]) cout << 0, exit(0);
	rep(i, 1, n) if(!t[i]) f[i][++m] = 1, p[m] = i, id[i] = m;
	per(l, n, 1) if(t[l] < 2) {
		int idx = upper_bound(p + 1, p + m + 1, l) - p;
		if(t[l] == 1) rep(r, idx, m) tmp[r] = f[l + 1][r];
		rep(k, l + 1, n) if(t[k]) {
			int j = id[k - 1];
			uint64_t x = f[l][j];
			if(!x) continue;
			auto a = &tmp[j + 1];
			for(auto i = &f[k + 1][j + 1], end = &f[k + 1][m]; i <= end; i += 8, a += 8) {
				a[0] += x * i[0];
				a[1] += x * i[1];
				a[2] += x * i[2];
				a[3] += x * i[3];
				a[4] += x * i[4];
				a[5] += x * i[5];
				a[6] += x * i[6];
				a[7] += x * i[7];
			}
		} else {
			int i = id[k];
			f[l][i] = tmp[i] % P, tmp[i] = 0;
		}
	}
	cout << f[1][m];
}