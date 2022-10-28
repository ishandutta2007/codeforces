#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod[2] = {int(1e9 + 7) , int(1e9 + 9)};
inline int add(int a , int b , int c){
	int res = a + b;
	if(res >= mod[c]){
		return res - mod[c];
	}
	return res;
}
inline int mult(int a , int b , int c){
	long long res = a;
	res *= b;
	if(res >= mod[c]){
		return res % mod[c];
	}
	return res;
}
inline int power(int a , int b , int c){
	int res = 1;
	while(b){
		if(b & 1){
			res = mult(res , a , c);
		}
		a = mult(a , a , c);
		b >>= 1;
	}
	return res;
}
int n , k;
int arr[N];
int sum[2];
int pw[N][2];
int inv[N][2];
int tmp[2];
const int inv2[2] = {power(2 , mod[0] - 2 , 0) , power(2 , mod[1] - 2 , 1)};
int ans;
int main(){
	scanf("%d %d" , &n , &k);
	for(int j = 0 ; j < 2 ; ++j){
		pw[0][j] = 1;
		inv[0][j] = 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ; j < 2 ; ++j){
			pw[i][j] = add(pw[i - 1][j] , pw[i - 1][j] , j);
			inv[i][j] = mult(inv[i - 1][j] , inv2[j] , j);
		}
	}
	for(int i = 0 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		for(int j = 0 ; j < 2 ; ++j){
			sum[j] = add(sum[j] , mult(add(arr[i] , mod[j] , j), pw[i][j] , j) , j);
		}
	}
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j < 2 ; ++j){
			tmp[j] = mult(add(sum[j] , mod[j] - mult(add(arr[i] , mod[j] , j) , pw[i][j] , j) , j) , inv[i][j] , j);
		}
		if(tmp[0] == tmp[1]){
			ans += (i == n) ? !!tmp[0] : (tmp[0] <= k);
		}
		else if(mod[0] - tmp[0] == mod[1] - tmp[1]){
			ans += (i == n) ? !!(mod[0] - tmp[0]) : (mod[0] - tmp[0] <= k);
		}
	}
	printf("%d\n" , ans);
}