#include <bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;
const int MN = 300005;
const int INF = 0x3f3f3f3f;
const int Mod = 998244353;

inline int qPow(int b, int e)
{
	int a = 1;
	for (; e; b = (LL)b * b % Mod, e >>= 1)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int n, m, q, k;
int a[MN], B[MN], b[MN], c[MN];
inline void Add(int i, int x) { for (; i <= n; i += i & -i) B[i] += x; }
inline int Qur(int i) { int a = 0; for (; i; i -= i & -i) a += B[i]; return a; }

int Ans, Sum;

int main() {
	scanf("%d", &n);
	F(i,1,n) scanf("%d", &a[i]);
	int tot = 0;
	F(i,1,n) {
		if (~a[i]) {
			Ans = ((LL)Ans + Qur(n) - Qur(a[i]) + Mod) % Mod;
			Add(a[i], 1);
		}
		else ++tot;
	}
//	printf("%d\n", Ans);
	int xx = (LL)tot * (tot - 1) % Mod * 748683265 % Mod;
	Ans = (Ans + xx) % Mod;
//	printf("%d\n", Ans);
	F(i,1,n) if (~a[i]) c[a[i]] = 1;
	F(i,1,n) c[i] = c[i - 1] + (1 - c[i]);
	// c[i] : <i
	F(i,1,n) if (a[i]==-1) b[i] = 1;
//	F(i,1,n) printf("%d ",b[i]); puts("");
	F(i,1,n) b[i] += b[i - 1];
//	F(i,1,n) printf("%d ",b[i]); puts("");
	// b[i] : left
	F(i,1,n) if (~a[i]){
//		printf("%d : %d %d\n", a[i], b[i], c[a[i]]);
		Ans = (Ans + ((LL)(tot - c[a[i]]) * b[i] + (LL)c[a[i]] * (tot - b[i])) % Mod * qPow(tot, Mod - 2)) % Mod;
	}
	printf("%d\n", Ans);
	return 0;
}