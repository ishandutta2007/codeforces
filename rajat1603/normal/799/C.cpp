#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , c , d;
int ans;
int val , cst;
char str[5];
int bit[2][N];
void update(int row , int idx , int val){
	while(idx < N){
		bit[row][idx] = max(bit[row][idx] , val);
		idx += idx & -idx;
	}
}
int query(int row , int idx){
	int res = 0;
	while(idx > 0){
		res = max(res , bit[row][idx]);
		idx -= idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d %d %d" , &n , &c , &d);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %s" , &val , &cst , str);
		if(str[0] == 'C'){
			if(cst <= c){
				int tmp1 = query(0 , d);
				int tmp2 = query(1 , c - cst);
				int tmp3 = max(tmp1 , tmp2);
				if(tmp3){
					ans = max(ans , tmp3 + val);
				}
			}
			update(1 , cst , val);
		}
		else{
			if(cst <= d){
				int tmp1 = query(0 , d - cst);
				int tmp2 = query(1 , c);
				int tmp3 = max(tmp1 , tmp2);
				if(tmp3){
					ans = max(ans , tmp3 + val);
				}
			}
			update(0 , cst , val);
		}
	}
	printf("%d\n" , ans);
}