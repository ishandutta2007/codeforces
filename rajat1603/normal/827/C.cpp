#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 10;
const int K = 4;
int bit[K][M][M][N];
char str[N];
int n;
int q;
int type;
int idx;
int l , r;
char tmp[15];
inline int decode(char c){
	if(c == 'A'){
		return 0;
	}
	if(c == 'T'){
		return 1;
	}
	if(c == 'G'){
		return 2;
	}
	if(c == 'C'){
		return 3;
	}
}
void update(int d1 , int d2 , int d3 , int idx , int val){
	--d2;
	while(idx <= n){
		bit[d1][d2][d3][idx] += val;
		idx += idx & -idx;
	}
}
int query(int d1 , int d2 , int d3 , int idx){
	--d2;
	int res = 0;
	while(idx){
		res += bit[d1][d2][d3][idx];
		idx -= idx & -idx;
	}
	return res;
}
int query(int d1 , int d2 , int d3 , int l , int r){
	return query(d1 , d2 , d3 , r) - query(d1 , d2 , d3 , l - 1);
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= 10 ; ++j){
			update(decode(str[i]) , j , i % j , i , 1);
		}
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d" , &type);
		if(type == 1){
			scanf("%d" , &idx);
			for(int j = 1 ; j <= 10 ; ++j){
				update(decode(str[idx]) , j , idx % j , idx , -1);
			}
			scanf("%s" , tmp);
			str[idx] = tmp[0];
			for(int j = 1 ; j <= 10 ; ++j){
				update(decode(str[idx]) , j , idx % j , idx , 1);
			}
		}
		else{
			scanf("%d %d %s" , &l , &r , tmp);
			int sz = strlen(tmp);
			int ans = 0;
			for(int i = l ; i < l + sz && i <= r ; ++i){
				ans += query(decode(tmp[i - l]) , sz , i % sz , l , r);
			}
			printf("%d\n" , ans);
		}
	}
}