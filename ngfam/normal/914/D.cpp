#include <bits/stdc++.h>

using namespace std;

const int N = 500500;

int n, a[N], q;
int it[N << 2];

#define mid ((l + r) >> 1)

void build(int x, int l, int r){
	if(l == r) {
		it[x] = a[r];
		return;
	}
	build(x + x, l, mid);
	build(x + x + 1, mid + 1, r);
	it[x] = __gcd(it[x + x], it[x + x + 1]);
}

int fin(int x, int l, int r, int u, int v, int val){
	if(u > v) return 0;
	if(l > v || r < u) return 0;
	if(it[x] % val == 0) return 0;

	if(l == r){
		return r;
	}
	int k = fin(x + x, l, mid, u, v, val);
	if(k != 0) return k;
	return fin(x + x + 1, mid + 1, r, u, v, val);
}

void modify(int x, int l, int r, int u, int val){
	if(l > u  || r < u) return;
	if(l == r){
		it[x] = val;
		return;
	}
	modify(x + x, l, mid, u, val);
	modify(x + x + 1, mid + 1, r, u, val);
	it[x] = __gcd(it[x + x], it[x + x + 1]);	
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	build(1, 1, n);

	scanf("%d", &q);
	while(q--){
		int t;
		scanf("%d", &t);

		if(t == 1){
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);

			int now = fin(1, 1, n, l, r, x);
			if(now == 0) {
				puts("YES");
				continue;
			}
			int nxt = fin(1, 1, n, now + 1, r, x);

			if(nxt == 0){
				puts("YES");
				continue;
			}
			puts("NO");
		}
		else{
			int u, x;
			scanf("%d%d", &u, &x);
			modify(1, 1, n, u, x);
		}
	}

	return 0;
}