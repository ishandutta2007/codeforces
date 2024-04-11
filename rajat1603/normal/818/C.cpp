#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int garbage;
int a[N] , b[N] , c[N] , d[N];
int lft[N];
int rgt[N];
int top[N];
int bot[N];
void update(int bit[] , int idx){
	while(idx < N){
		++bit[idx];
		idx += idx & -idx;
	}
}
int query(int bit[] , int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d" , &n);
	scanf("%d %d" , &garbage , &garbage);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d %d" , a + i , b + i , c + i , d + i);
		update(lft , min(a[i] , c[i]));
		update(rgt , max(a[i] , c[i]));
		update(top , min(b[i] , d[i]));
		update(bot , max(b[i] , d[i]));
	}
	scanf("%d %d %d %d" , lft , rgt , top , bot);
	for(int i = 1 ; i <= n ; ++i){
		if(query(lft , max(a[i] , c[i]) - 1) - (a[i] != c[i]) == lft[0] && n - query(rgt , min(a[i] , c[i])) - (a[i] != c[i]) == rgt[0] && query(top , max(b[i] , d[i]) - 1) - (b[i] != d[i]) == top[0] && n - query(bot , min(b[i] , d[i])) - (b[i] != d[i]) == bot[0]){
			printf("%d\n" , i);
			return 0;
		}
	}
	printf("-1\n");
}