#pragma GCC optimize(3)
#include <bits/stdc++.h>

#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for(int i = pos[x]; i; i = g[i].nex)

const long long N = 2005, M = 4000005, mod = 1073741824;
int A, B, C, mu[M], pri[M], pz, num[M], ab;
long long f[M], ans;
bool c[M];
inline void Pre (void) {
	mu[1] = 1;
	Rep(i, 2, C) {
		if (!c[i]) pri[++ pz] = i, mu[i] = -1;
		Rep(j, 1, pz) {
			int k = pri[j] * i;
			if (k > ab) break ;
			c[k] = 1, mu[k] = -mu[i];
			if (!(i % pri[j])) { mu[k] = 0; break; }
		}
	}
	Rep(e, 1, C) {
		long long k = 0;
		Rep(d, 1, C) k += C / (e * d);
		for (int g = e; g <= ab; g += e) f[g] += mu[e] * k;
	}
	Rep(g, 1, ab) f[g] %= mod;
}
int main (void) {
	scanf ("%d%d%d", &A, &B, &C);
	Rep(i, 1, A) Rep(j, 1, B) num[i * j] ++;
	ab = A * B;
	Pre();
	Rep(g, 1, ab) 
	    if (num[g]) {
		    long long k1 = 0;
	    	Rep(j, 1, ab / g) (k1 += num[j * g]) %= mod;
		    (ans += f[g] * k1) %= mod;
	    }
	printf("%lld", (ans + mod) % mod);
	return 0;
}