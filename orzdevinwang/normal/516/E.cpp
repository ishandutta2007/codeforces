#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pil pair<int, lonf long>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
int n, m, gcd, lena, lenb, a[N], b[N], na[N], nb[N];
vector<int> A[N], B[N];
void exgcd(int a, int b, int &x, int &y) {
	if(b == 0) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= x * (a / b);
}
int getrk(int a, int len, int b) {
	int x, y; exgcd(a, b, x, y);
	return (x + len - 1) % len + 1;
}
map<int, int> mp;
int tot, ga, gb;
struct Node {
	int wz; ll val;
	bool isano;
} g[N];
ll ans;
void Min(ll &x, ll y) { if(x > y) x = y; }
void Max(ll &x, ll y) { if(x < y) x = y; }
#define nxt(i) ((i) % tot + 1)
void work(int x) {
	int la = A[x].size(), lb = B[x].size(); ll res = -1;
	if(la == 0 && lb == 0) puts("-1"), exit(0);
	sort(A[x].begin(), A[x].end());
	sort(B[x].begin(), B[x].end());

	tot = 0, mp.clear();
	L(i, 0, la - 1) ++tot, g[tot].wz = 1ll * gb * (A[x][i] - x) % n, g[tot].val = A[x][i], g[tot].isano = 0, mp[g[tot].wz] = 1;
	L(i, 0, lb - 1) if(!mp[1ll * gb * (B[x][i] - x) % n]) 
		++tot, g[tot].wz = 1ll * gb * (B[x][i] - x) % n, g[tot].val = B[x][i], g[tot].isano = 1, mp[g[tot].wz] = 1;
	sort(g + 1, g + tot + 1, [&](Node aa, Node bb) { return aa.wz < bb.wz; });
	L(t, 0, 2) L(i, 1, tot) Min(g[nxt(i)].val, g[i].val + 1ll * (g[nxt(i)].wz - g[i].wz + n) % n * m);
	L(i, 1, tot) {
		if((g[nxt(i)].wz - g[i].wz + n) % n != 1 && n != 1) Max(res, g[i].val + 1ll * (g[nxt(i)].wz - g[i].wz + n - 1) % n * m);
		if(g[i].isano) Max(res, g[i].val);
	}
	
	tot = 0, mp.clear();
	L(i, 0, lb - 1) ++tot, g[tot].wz = 1ll * ga * (B[x][i] - x) % m, g[tot].val = B[x][i], g[tot].isano = 0, mp[g[tot].wz] = 1;
	L(i, 0, la - 1) if(!mp[1ll * ga * (A[x][i] - x) % m])
		++tot, g[tot].wz = 1ll * ga * (A[x][i] - x) % m, g[tot].val = A[x][i], g[tot].isano = 1, mp[g[tot].wz] = 1;
	sort(g + 1, g + tot + 1, [&](Node aa, Node bb) { return aa.wz < bb.wz; });
	L(t, 0, 2) L(i, 1, tot) Min(g[nxt(i)].val, g[i].val + 1ll * (g[nxt(i)].wz - g[i].wz + m) % m * n);
	L(i, 1, tot) {
		if((g[nxt(i)].wz - g[i].wz + m) % m != 1 && m != 1) Max(res, g[i].val + 1ll * (g[nxt(i)].wz - g[i].wz + m - 1) % m * n);
		if(g[i].isano) Max(res, g[i].val);
	}
	Max(ans, 1ll * res * gcd + x);
}
int main() {
	scanf("%d%d", &n, &m), gcd = __gcd(n, m), n /= gcd, m /= gcd;
	exgcd(n, m, ga, gb), ga = (ga % m + m) % m, gb = (gb % n + n) % n;
	scanf("%d", &lena); L(i, 1, lena) scanf("%d", &a[i]); sort(a + 1, a + lena + 1);
	scanf("%d", &lenb); L(i, 1, lenb) scanf("%d", &b[i]); sort(b + 1, b + lenb + 1);
	if(lena + lenb < gcd) return puts("-1"), 0;
	L(i, 1, lena) A[a[i] % gcd].push_back(a[i] / gcd);
	L(i, 1, lenb) B[b[i] % gcd].push_back(b[i] / gcd);
	L(i, 0, gcd - 1) work(i);
	printf("%lld\n", ans);
	return 0;
}