#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , q , m;
int arr[N];
int type[N] , l[N] , r[N];
int b[N];
int solve(int idx){
	for(int i = q ; i >= 1 ; --i){
		if(idx < l[i] || idx > r[i]){
			continue;
		}
		if(type[i] == 1){
			if(idx == l[i]){
				idx = r[i];
			}
			else{
				--idx;
			}
		}
		else{
			idx = l[i] + r[i] - idx;
		}
	}
	return arr[idx];
}
int main(){
	scanf("%d %d %d" , &n , &q , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d" , type + i , l + i , r + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d" , b + i);
		printf("%d%c" , solve(b[i]) , " \n"[i == m]);
	}
}