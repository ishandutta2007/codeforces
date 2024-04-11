#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1007;
const int G = 19491001;
const int mod = 1019260817;
const int mxlen = 1001;
void Min(int &x, int y) { if(x > y) x = y; }
void Max(int &x, int y) { if(x < y) x = y; }
string s[N], now;
int n, len[N], Len, w[N], has[N][N], dp[N][N], p[N], Pow[N], hz[N], hv[N];
int get(int x, int l, int r) { return (has[x][r] - (l == 0 ? 0 : has[x][l - 1]) + mod) % mod; }
int D[N], arr[N], tot;
bool cmp(int x, int y) { return D[x] > D[y]; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> now >> n, Len = now.size(), reverse(now.begin(), now.end());
	Pow[0] = 1;
	L(i, 1, 1001) Pow[i] = (ll) Pow[i - 1] * G % mod;
	L(i, 1, n) cin >> s[i], len[i] = (int) s[i].size(), reverse(s[i].begin(), s[i].end()), p[i] = i;
	L(i, 0, 9) cin >> w[i];
	L(i, 1, n) {
		L(j, 0, len[i] - 1) {
			has[i][j] = (ll) s[i][j] * Pow[j] % mod;
			if(j) (has[i][j] += has[i][j - 1]) %= mod;
		}
	}
	L(i, 1, n) D[i] = 1;
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	L(i, 0, mxlen) {
		if(i) {
			tot = 0;
			L(j, 1, n) if(i <= len[j]) D[j] += (s[j][i - 1] - '0') * (n + 1);
			L(j, 1, n) arr[++tot] = D[j];
			sort(arr + 1, arr + tot + 1), tot = unique(arr + 1, arr + tot + 1) - arr - 1;
			L(j, 1, n) D[j] = lower_bound(arr + 1, arr + tot + 1, D[j]) - arr;
			sort(p + 1, p + n + 1, cmp);
		}
		int l = (i == Len - 1), r = 9;
		if((int) Len <= i) l = r = 0;
		else  if(now[i] != '?') l = r = now[i] - '0';
		L(d, l, r) {
			int now = 0, all = 0;
			R(j, n, 1) {
				int v = (i > len[p[j]] - 1 ? 0 : s[p[j]][i] - '0');
				hv[j] = hv[j + 1], hz[j] = hz[j + 1];
				if(v + d || i < max(len[p[j]], Len)) hv[j] += w[(v + d) % 10], hz[j] += (v + d) / 10;
			}
			L(j, 0, n) {
				if(j) {
					int v = (i > len[p[j]] - 1 ? 0 : s[p[j]][i] - '0');
					all += w[(v + d + 1) % 10];
					now += (v + d + 1) / 10;
				}
				Max(dp[i + 1][now + hz[j + 1]], dp[i][j] + all + hv[j + 1]);
			}
		}
	}
	cout << dp[mxlen + 1][0] << endl;
	return 0;
}