#include <bits/stdc++.h>

using namespace std;

const int N = 123456, maxval = (1 << 30) - 1;

int n, a[N], it[N * 4], l[N], r[N], q[N], m, calc[N], sum[N], d, c;

void build(int i, int l, int r){
	if(l == r){
		it[i] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);
	it[i] = it[i * 2] & it[i * 2 + 1];
}

int ask(int i, int l, int r){
	if(l > c || d > r) return maxval;
	if(l >= d && r <= c) return it[i];
	int mid = (l + r) >> 1;
	return ask(i * 2, l, mid) & ask(i * 2 + 1, mid + 1, r);
}

int query(int l, int r){
	d = l; c = r;
	return ask(1, 1, n);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("sol.inp", "r", stdin);
		freopen("sol.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d", l + i);
		scanf("%d", r + i);
		scanf("%d", q + i);
	}

	for(int bit = 0; bit < 30; ++bit){
		memset(calc, 0, sizeof calc);
		for(int i = 1; i <= m; ++i){
			if(q[i] & (1 << bit)){
				++calc[l[i]];
				--calc[r[i] + 1];
			}	
		}
		
		for(int i = 1; i <= n; ++i){
			sum[i] = sum[i - 1] + calc[i];
		}
		
		for(int i = 1; i <= n; ++i){
			if(sum[i] > 0){
				a[i] |= (1 << bit);
			}
		}
	}

	build(1, 1, n);

	for(int i = 1; i <= m; ++i){
		if(query(l[i], r[i]) != q[i]){
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}

	return 0;
}