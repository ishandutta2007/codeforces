#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 2e4 + 7;
int n, cnt[N];
char s[N];
bool ts[N][N];
bool ok[N], qwq[N], vis[N], okr[N];
int tor[N];
void chk(char a, char b) {
	L(i, 1, n + 2) tor[i] = i;
	R(i, n, 1) if(s[i] == a && s[i + 1] == b) tor[i] = tor[i + 2];
	L(i, 1, n) tor[i] -= i;
	for(int d = 1; d <= n; d += 2) L(i, 1, n - d + 1) if(tor[i] > d) ts[d][i + d] = true;
}
bool tmp[N]; 
int spin[N]; 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	chk('D', 'U');
	chk('R', 'L');
	L(d, 2, n / 2) {
		int wl = 0;
		L(i, 1, n) {
			cnt[i] = 
				(i > d && s[i - d] == 'D') + 
				(s[i - 1] == 'R') + 
				(s[i + 1] == 'L') + 
				(i <= n - d && s[i + d] == 'U'), 
			ok[i] = cnt[i] >= 1;
			if(i <= n - d && cnt[i] == (s[i + d] == 'U')) wl = i;
			if(i >= d * 2) 
				okr[i] = i - d >= wl 
					&& (s[i - 1] == 'R' || s[i - d] == 'D') 
					&& (s[i - d + 2] == 'L' || s[i - d * 2 + 1] == 'D');
		}
		int xr = n + 1;
		int mr = n + 1;
		R(i, n, 1) {
			if(i >= d) 
				qwq[i] = (cnt[i] != (s[i + 1] == 'L')) && 
					(cnt[i - d + 1] != (s[i - d] == 'R'));
			spin[i] = (i >= n - d + 1) ? i + d - 1 : qwq[i + d - 1] ? spin[i + d] : i + d - 1;
		}
		R(i, n, 1) {
			if(!ok[i]) xr = i;
			if(i > d && cnt[i] == (s[i - d] == 'D')) mr = i;
			if(i + d <= mr && i + d * 2 - 1 <= xr) {
				if(s[i + 1] != 'L' && s[i + d] != 'U') {
					spin[i] = 0;
					continue;
				}
				if(s[i + d - 2] != 'R' && s[i + d * 2 - 1] != 'U') {
					spin[i] = 0;
					continue;
				}
				spin[i] = min(xr - 1, spin[i]);
			} else spin[i] = i;
			spin[i] = spin[i] - i;
		}
		for(int g = d * 2 - 1; g <= n; g += d) if(g & 1) {
			L(i, 1, n - g) if(spin[i] >= g) ts[g][i + g] |= okr[i + g];
		}
	}
	int ns = 0;
	for(int d = 1; d <= n; d += 2) L(i, d, n) ns += ts[d][i];
	cout << ns << '\n';
	return 0;
}