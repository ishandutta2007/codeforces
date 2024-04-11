#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10 , K = 60; 

vector <int> t[N << 2];
struct T {int c , x , z;}; 

stack <T> S;

int n , m , k , q;
int fa[K][N << 1] , dep[K][N << 1] , u[N] , v[N] , a[N] , c[N] , g[N];

int find(int c , int x) {
	while(x ^ fa[c][x]) x = fa[c][x];
	return x;
}

void con(int c , int x , int y) {
	if(x == y) return;
	if(dep[c][x] > dep[c][y]) swap(x , y);
	int z = dep[c][x] == dep[c][y];
	S.push((T) {c , x , z}) , fa[c][x] = y , dep[c][y] += z;
}

void add(int p , int l , int r , int tl , int tr , int x) {
	if(tl <= l && r <= tr) return (void) (t[p].push_back(x));
	int mid = (l + r) >> 1;
	if(tl <= mid) add(p << 1 , l , mid , tl , tr , x);
	if(tr > mid) add(p << 1 | 1 , mid + 1 , r , tl , tr , x);
}

void query(int p , int l , int r) {
	int o = S.size();
	for(auto i : t[p]) {
		int col = c[i] , x = u[a[i]] , y = v[a[i]];
		if(col) con(col , find(col , x) , find(col , y + n)) , con(col , find(col , x + n) , find(col , y));
	}
	if(l == r) {
		int &col = c[l] , x = u[a[l]] , y = v[a[l]];
		if(find(col , x) == find(col , y)) printf("NO\n") , col = g[a[l]];
		else printf("YES\n") , g[a[l]] = col;
		return;
	}
	int mid = (l + r) >> 1;
	query(p << 1 , l , mid) , query(p << 1 | 1 , mid + 1 , r);
	while(S.size() > o) {
		int c = S.top().c , x = S.top().x , z = S.top().z;
		dep[c][fa[c][x]] -= z , fa[c][x] = x , S.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d%d%d" , &n , &m , &k , &q); 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
			fa[j][i] = i , fa[j][i + n] = i + n;
	for(int i = 1; i <= m; i++) scanf("%d%d" , &u[i] , &v[i]) , g[i] = q + 1;
	for(int i = 1; i <= q; i++) scanf("%d%d" , &a[i] , &c[i]);
	for(int i = q; i >= 1; i--) {
		if(i + 1 <= g[a[i]] - 1) add(1 , 1 , q , i + 1 , g[a[i]] - 1 , i);
		g[a[i]] = i;
	}
	for(int i = 1; i <= m; i++) g[i] = 0;
	query(1 , 1 , q);
	return 0;
}