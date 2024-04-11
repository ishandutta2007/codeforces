#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
struct point{
	long long x , y;
	point(long long _x = 0 , long long _y = 0){
		x = _x;
		y = _y;
	}
	point operator - (const point &o) const {
		return point(x - o.x , y - o.y);
	}
};
long long cross(point a , point b){
	return a.x * b.y - a.y * b.x;
}
bool convex(point a , point b , point c){
	return cross(b - a , c - a) <= 0;
}
point arr[N];
int stk[N];
int sz;
int nxt[LN][N];
int depth[N];
int q;
int a , b;
int lca(int a , int b){
	if(depth[a] < depth[b]){
		swap(a , b);
	}
	int dif = depth[a] - depth[b];
	for(int i = 0 ; i < LN ; ++i){
		if(dif & (1 << i)){
			a = nxt[i][a];
		}
	}
	if(a != b){
		for(int i = LN - 1 ; i >= 0 ; --i){
			if(nxt[i][a] != nxt[i][b]){
				a = nxt[i][a];
				b = nxt[i][b];
			}
		}
		a = nxt[0][a];
	}
	return a;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld %lld" , &arr[i].x , &arr[i].y);
	}
	nxt[0][n] = 0;
	depth[n] = 0;
	stk[sz = 1] = n;
	for(int i = n - 1 ; i >= 1 ; --i){
		while(sz >= 2 && !convex(arr[i] , arr[stk[sz]] , arr[stk[sz - 1]])){
			--sz;
		}
		nxt[0][i] = stk[sz];
		depth[i] = depth[stk[sz]] + 1;
		stk[++sz] = i;
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
		}
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d %d" , &a , &b);
		printf("%d%c" , lca(a , b) , " \n"[!q]);
	}
}