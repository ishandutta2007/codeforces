#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int d[N];

int n;
int a[N];

#define mid ((l + r) >> 1)

int T[N << 2];
long long S[N << 2];

void recalc(int x){
	T[x] = max(T[x + x], T[x + x + 1]);
	S[x] = S[x + x] + S[x + x + 1];
}

void build(int x, int l, int r){
	if(l == r){
		S[x] = T[x] = a[r];
		return;
	}
	build(x + x, l, mid);
	build(x + x + 1, mid + 1, r);
	recalc(x);
}

void upd(int x, int l, int r, int u, int v){
	if(T[x] <= 2) return;
	if(l > v || r < u) return;

	if(l == r) {
		S[x] = T[x] = d[T[x]];
		return;
	}	

	upd(x + x, l, mid, u, v);
	upd(x + x + 1, mid + 1, r, u, v);	

	recalc(x);

	return;
}

long long query(int x, int l, int r, int u, int v){
	if(l >= u && r <= v) return S[x];
	if(l > v || r < u) return 0;
	return query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
}

int main(){

	for(int i = 1; i < N; ++i){
		for(int j = i; j < N; j += i){
			++d[j];
		}
	}

	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	build(1, 1, n);

	while(m--){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);

		if(t == 1){
			upd(1, 1, n, l, r);
		}
		else{
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}

	return 0;
}