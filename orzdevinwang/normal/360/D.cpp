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
int n, m, mod, a[N], b[N], gcd;
int qpow(int x, int y, int p = mod) { int res = 1; for(; y; x = 1ll * x * x % p, y >>= 1) if(y & 1) res = 1ll * res * x % p; return res; }
int ny(int x) { return qpow(x, mod - 2); }
int p[N], tot, tmp;
int sum[N], all;
int main() {
	scanf("%d%d%d", &n, &m, &mod), gcd = tmp = mod - 1;
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, m) scanf("%d", &b[i]), gcd = __gcd(gcd, b[i]);
	tot = 0; 
	L(i, 1, sqrt(tmp)) if(tmp % i == 0) p[++tot] = i, (i != tmp / i) && (p[++tot] = tmp / i); 
	sort(p + 1, p + tot + 1);
	L(i, 1, n) {
		a[i] = qpow(a[i], gcd);
		L(j, 1, tot) if(qpow(a[i], p[j]) == 1) {
			a[i] = __gcd(tmp / p[j], tmp);
			break;
		}
	}
	R(i, tot, 1) {
		bool flag = 0;
		L(j, 1, n) if(p[i] % a[j] == 0) flag = 1;
		if(flag) {
			sum[i] = tmp / p[i];
			L(j, i + 1, tot) if(p[j] % p[i] == 0) sum[i] -= sum[j];
			all += sum[i];
		}
	}
	printf("%d\n", all);
	return 0;
}