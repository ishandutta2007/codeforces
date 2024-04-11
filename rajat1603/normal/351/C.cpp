#include "bits/stdc++.h"
using namespace std;
const int N = 20;
const int M = 1e7 + 7;
const int S = 31;
const int O = 15;
const unsigned inf = 2e9 + 9;
int n , m;
int a[N];
int b[N];
unsigned grid[S][S];
unsigned res[S][S];
unsigned c[S][S];
void mult(unsigned a[S][S] , unsigned b[S][S]){
	for(int i = 0 ; i < S ; ++i){
		for(int j = 0 ; j < S ; ++j){
			c[i][j] = inf;
		}
	}
	for(int i = -O ; i <= O ; ++i){
		for(int j = -O ; j <= O ; ++j){
			for(int k = max(0 , -j) - O ; k <= O ; ++k){
				for(int l = max(0 , -j) - O ; l <= O && j + l <= O ; ++l){
					c[min(i , k + j) + O][j + l + O] = min(c[min(i , k + j) + O][j + l + O] , a[i + O][j + O] + b[k + O][l + O]);
				}
			} 
		}
	}
	memcpy(a , c , sizeof(c));
}
void power(){
	for(int i = 0 ; i < S ; ++i){
		for(int j = 0 ; j < S ; ++j){
			res[i][j] = inf;
		}
	}
	res[O][O] = 0;
	while(m){
		if(m & 1){
			mult(res , grid);
		}
		mult(grid , grid);
		m >>= 1;
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 0 ; i < n ; ++i){
		scanf("%d" , b + i);
	}
	for(int i = 0 ; i < S ; ++i){
		for(int j = 0 ; j < S ; ++j){
			grid[i][j] = inf;
		}
	}
	for(int i = 0 ; i < (1 << n) ; ++i){
		int mn = 0;
		int sum = 0;
		unsigned cst = 0;
		for(int j = 0 ; j < n ; ++j){
			if((i >> j) & 1){
				++sum;
				cst += a[j];
			}
			else{
				--sum;
				cst += b[j];
			}
			mn = min(mn , sum);
		}
		grid[mn + O][sum + O] = min(grid[mn + O][sum + O] , cst);
	}
	power();
	printf("%u\n" , res[O][O]);
}