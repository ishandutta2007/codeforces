#include <cstdio>
#include <cstring>

typedef long long LL;

const int N = 300000;
const int MOD = 1000000009;

int fibo[N + 2];

struct SegmentTree {
	LL sum[N << 2];
	LL lazy1[N << 2];
	LL lazy2[N << 2];
	
	void propagate (int node, int l, int r) {
		
		int mid = l + r >> 1;
				
		lazy1[2 * node + 1] += lazy1[node];
		lazy2[2 * node + 1] += lazy2[node];
		lazy1[2 * node + 1] %= MOD;
		lazy2[2 * node + 1] %= MOD;
		sum  [2 * node + 1] += (lazy1[node] * fibo[mid - l + 1 + 1] + lazy2[node] * fibo[mid - l + 1]) - (lazy1[node]) + MOD;
		sum  [2 * node + 1] %= MOD;
		
		LL tmp1 = lazy1[node] * fibo[mid - l + 2] + lazy2[node] * fibo[mid - l + 1];
		LL tmp2 = lazy1[node] * fibo[mid - l + 1] + lazy2[node] * fibo[mid - l + 0];
		lazy1[node] = tmp1 % MOD;
		lazy2[node] = tmp2 % MOD;		
		
		lazy1[2 * node + 2] += lazy1[node];
		lazy2[2 * node + 2] += lazy2[node];
		
		lazy1[2 * node + 2] %= MOD;
		lazy2[2 * node + 2] %= MOD;
		sum  [2 * node + 2] += (lazy1[node] * fibo[r - mid + 1] + lazy2[node] * fibo[r - mid]) - (lazy1[node]) + MOD;
		sum  [2 * node + 2] %= MOD;
		
		lazy1[node] = lazy2[node] = 0;
		
		return;
	}
	
	void update (int node, int l, int r, int a, int b) {
		if (l > b || r < a) return;
		if (l >= a && r <= b) {
			
			lazy1[node] += fibo[l - a + 2];
			lazy2[node] += fibo[l - a + 1];
			lazy1[node] %= MOD;
			lazy2[node] %= MOD;
						
			sum[node] += ((LL) fibo[l - a + 2] * fibo[r - l + 1 + 1] + (LL) fibo[l - a + 1] * fibo[r - l + 1]) - (fibo[l - a + 2]) + MOD;
			sum[node] %= MOD;
			return;
		}
		
		propagate (node, l, r);
		
		int mid = l + r >> 1;
		update (2 * node + 1, l, mid + 0, a, b);
		update (2 * node + 2, mid + 1, r, a, b);
		sum[node] = (sum[2 * node + 1] + sum[2 * node + 2]) % MOD;
		return;
	}
	
	LL query (int node, int l, int r, int a, int b) {
		if (l > b || r < a) return 0;
		if (l >= a && r <= b) return sum[node];
		
		propagate (node, l, r);
		
		int mid = l + r >> 1;
		return (query (2 * node + 1, l, mid + 0, a, b) + 
			    query (2 * node + 2, mid + 1, r, a, b)) % MOD;
	}
	
} segmentTree;

int n, m;
int a[N];

int main () {
	fibo[1] = 1;
	for (int i=2; i<N+2; i++) fibo[i] = fibo[i - 1] + fibo[i - 2], fibo[i] %= MOD;

	scanf ("%d %d", &n, &m);
		
	for (int i=0; i<n; i++) scanf ("%d", a + i), a[i] += a[i-1], a[i] %= MOD;
	
	int type, l, r;
	while (m--) {
		scanf ("%d %d %d", &type, &l, &r);
		l--, r--;
				
		if (type == 1) segmentTree.update (0, 0, n - 1, l, r);
		else if (type == 2) printf ("%I64d\n", (segmentTree.query(0, 0, n - 1, l, r) + a[r] - a[l - 1] + MOD) % MOD);
		
		// for (int i=0; i<n; i++) printf ("%I64d ", segmentTree.query (0, 0, n - 1, i, i) + a[i] - a[i - 1]); printf ("\n");
	}
	return 0;
}