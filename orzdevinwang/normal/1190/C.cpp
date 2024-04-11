#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, k, f[N], las[2][N], nxt[2][N];
char s[N];
int sum(int l, int r) { return f[r] - f[l - 1]; }
int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	L(i, 1, n) f[i] = s[i] - '0' + f[i - 1], nxt[s[i] - '0'][i] = las[s[i] - '0'][i] = i;
	L(i, 1, n) (!nxt[0][i]) && (nxt[0][i] = nxt[0][i + 1]), (!nxt[1][i]) && (nxt[1][i] = nxt[1][i + 1]);
	R(i, n, 1) (!las[0][i]) && (las[0][i] = las[0][i - 1]), (!las[1][i]) && (las[1][i] = las[1][i - 1]);
	L(i, 0, n - k) if(sum(1, i) + sum(i + k + 1, n) == 0 || sum(1, i) + sum(i + k + 1, n) == n - k) return puts("tokitsukaze"), 0;
	L(i, 0, n - k) if(sum(1, i) && sum(i + k + 1, n)) return puts("once again"), 0;
	L(i, 0, n - k) if(sum(1, i) - i && sum(i + k + 1, n) - (n - i - k)) return puts("once again"), 0;
	if(las[0][n] - nxt[0][k + 1] >= k - 1) return puts("once again"), 0;
	if(las[1][n] - nxt[1][k + 1] >= k - 1) return puts("once again"), 0;
	if(las[0][n - k] - nxt[0][1] >= k - 1) return puts("once again"), 0;
	if(las[1][n - k] - nxt[1][1] >= k - 1) return puts("once again"), 0;
	puts("quailty");
	return 0;
}