#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 8005;
const int mod = 1019260817;
const int G = 19491001;
int n, f[N], val[N], g[N][N], Pow[N];
char s[N];
int has[N];
bool Isok(int x, int y, int len) {
	if(x > y) swap(x, y);
	return (ll) (has[x + len - 1] - has[x - 1] + mod) % mod * Pow[y - x] % mod == 
	(has[y + len - 1] - has[y - 1] + mod) % mod;
}
int used[N];
int main() {
	scanf("%s", s + 1);
	L(i, 0, 9) val[i] = 1;
	L(i, 10, 99) val[i] = 2;
	L(i, 100, 999) val[i] = 3;
	L(i, 1000, 8000) val[i] = 4;
	n = strlen(s + 1);
	L(i, 1, n) f[i] = 1e9;
	Pow[0] = 1;
	L(i, 1, n) Pow[i] = (ll) Pow[i - 1] * G % mod;
	L(i, 1, n) has[i] = (has[i - 1] + (ll) (s[i] - 'a' + 1) * Pow[i] % mod) % mod;
	L(len, 1, n) {
		R(i, n - len + 1, max(n - len * 2 + 2, 0)) g[i][len] = i + len - 1;
		R(i, n - len * 2 + 1, 1) 
			if(Isok(i, i + len, len)) g[i][len] = g[i + len][len];
			else g[i][len] = i + len - 1;
	}
	f[0] = 0;
	L(i, 1, n) {
		memset(used, 0, sizeof(used));
		L(len, 1, n) {
			for(int now = g[i][len]; !used[now] && now >= i; now -= len) {
				used[now] = len;
			}
		}
		L(j, i, n) f[j] = min(f[j], f[i - 1] + val[(j - i + 1) / used[j]] + used[j]);
	}
	printf("%d\n", f[n]);
	return 0;
}