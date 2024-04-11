#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 300030;

int n;
int a[N];
int ans[N];
int it[N * 8];
int lazy[N * 8];

void push(int x){
	if(lazy[x] != 0){
		it[x] += lazy[x];
		lazy[x + x] += lazy[x];
		lazy[x + x + 1] += lazy[x];
	}
	lazy[x] = 0;
}

void upd(int x, int l, int r, int u, int v, int val){
	push(x);
	if(l >= u && r <= v){
		lazy[x] += val;
		push(x);
		return;
	}
	if(l > v || r < u) return;

	upd(x + x, l, mid, u, v, val);
	upd(x + x + 1, mid + 1, r, u, v, val);

	it[x] = max(it[x + x], it[x + x + 1]);
}

void modify(int x, int l, int r, int pos){
	push(x);
	if(l > pos || r < pos) return;

	if(l == r){
		it[x] = -N;
		return;
	}

	modify(x + x, l, mid, pos);
	modify(x + x + 1, mid + 1, r, pos);
	it[x] = max(it[x + x], it[x + x + 1]);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	vector < int > lst;

	scanf("%d", &n); 
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		lst.push_back(a[i]);
	}

	sort(lst.begin(), lst.end());

	for(int i = 1; i <= n; ++i){
		a[i] = lower_bound(lst.begin(), lst.end(), a[i]) - lst.begin() + 1; 
	}

	ans[0] = ans[n] = 1;
	for(int i = 1; i < n; ++i){
		upd(1, 1, n, a[i] + 1, n, 1);
		modify(1, 1, n, a[i]);

		ans[i] = it[1] + 1;
	}

	for(int i = 0; i <= n; ++i){
		printf("%d ", ans[i]);
	}


	return 0;
}