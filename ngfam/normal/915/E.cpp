#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

struct data{
	int l, r, k;
	void read(){
		scanf("%d%d%d", &l, &r, &k);
	}
}a[N];

int n, m;
int val[N];

int sum[N];
int it[N << 2];
int lazy[N << 3];

vector < int > num;

void push(int x, int l, int r){
	if(lazy[x] != 0){
		lazy[x + x] = lazy[x];
		lazy[x + x + 1] = lazy[x];

		if(lazy[x] == 1){
			it[x] = 0;
		}
		else{
			it[x] = num[r] - num[l - 1];
		}
	}
	lazy[x] = 0;
}

void recalc(int x){
	it[x] = it[x + x] + it[x + x + 1];
}

#define mid ((l + r) >> 1)

void build(int x, int l, int r){
	if(l == r){
		it[x] = num[r] - num[l - 1];
		return;
	}
	build(x + x, l, mid);
	build(x + x + 1, mid + 1, r);
	recalc(x);
}

void upd(int x, int l, int r, int u, int v, int t){
	push(x, l, r);
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		lazy[x] = t;
		push(x, l, r);
		return;
	}
	upd(x + x, l, mid, u, v, t);
	upd(x + x + 1, mid + 1, r, u, v, t);
	recalc(x);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}


	scanf("%d%d", &n, &m);

	num.push_back(0);
	num.push_back(n);

	for(int i = 1; i <= m; ++i){
		a[i].read();
		num.push_back(a[i].r);
		num.push_back(a[i].l - 1);
	}

	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());

	int sz = num.size() - 1;

	build(1, 1, sz);

	for(int i = 1; i <= m; ++i){
		a[i].l = upper_bound(num.begin(), num.end(), a[i].l - 1) - num.begin();
		a[i].r = lower_bound(num.begin(), num.end(), a[i].r) - num.begin();		
		upd(1, 1, sz, a[i].l, a[i].r, a[i].k);
		printf("%d\n", it[1]);
	}

	return 0;
}