#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int it[N * 8];
int lazy[N * 8];

struct Data{
	int t;
	int p;
	int val;

	void read(){
		scanf("%d%d", &p, &t);
		if(t == 1){
			scanf("%d", &val);
		}
	}
}ask[N];

pair < int, int > x[N];

#define mid ((l + r) >> 1)

void push(int x){
	if(lazy[x] != 0){
		it[x] += lazy[x];
		lazy[x + x] += lazy[x];
		lazy[x + x + 1] += lazy[x];
	}
	lazy[x] = 0;
}

void update(int x, int l, int r, int u, int v, int val){
	push(x);
	if(l > v || r < u) return;

	if(l >= u && r <= v){
		lazy[x] += val;
		push(x);
		return;
	}

	update(x + x, l, mid, u, v, val);
	update(x + x + 1, mid + 1, r, u, v, val);
	it[x] = min(it[x + x], it[x + x + 1]);
}

int query(int x, int l, int r, int pos){
	if(l == r){
		return it[x] + lazy[x];
	}
	if(pos <= mid) return query(x + x, l, mid, pos) + lazy[x];
	return query(x + x + 1, mid + 1, r, pos) + lazy[x];
}

int fin(int x, int l, int r, int val){
	push(x);
	if(l == r) return r;



	push(x + x);
	push(x + x + 1);

	int ret = -1;
	if(it[x + x + 1] <= val) ret = fin(x + x + 1, mid + 1, r, val);
	else if(it[x + x] <= val) ret = fin(x + x, l, mid, val);


	it[x] = min(it[x + x], it[x + x + 1]);

	return ret;
}

int n;
int a[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	int l, r;

	for(int i = 1; i <= n; ++i){
		ask[i].read();
		if(ask[i].t == 1){
			a[ask[i].p] = ask[i].val;
		}

		if(ask[i].t == 0){
			update(1, 0, n, ask[i].p, n, -1);
		}
		else{
			update(1, 0, n, ask[i].p, n, 1);
		}

		int sum = query(1, 0, n, n);
		int ret = fin(1, 0, n, sum - 1);

		if(ret == -1) puts("-1");
		else printf("%d\n", a[ret + 1]);
	}


	return 0;
}