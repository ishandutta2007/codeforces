#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , a , b;
int x , y;
int cur;
int main(){
	scanf("%d %d %d" , &n , &a , &b);
	x = -1;
	y = -1;
	for(int x = 0 ; x * a <= n ; ++x){
		int lft = n - x * a;
		if(lft % b){
			continue;
		}
		::x = x;
		::y = lft / b;
		break;
	}
	if(x == -1){
		printf("-1\n");
		return 0;
	}
	cur = 1;
	for(int i = 1 ; i <= x ; ++i){
		for(int j = 1 ; j < a ; ++j){
			printf("%d " , cur + j);
		}
		printf("%d " , cur);
		cur += a;
	}
	for(int i = 1 ; i <= y ; ++i){
		for(int j = 1 ; j < b ; ++j){
			printf("%d " , cur + j);
		}
		printf("%d " , cur);
		cur += b;
	}
	printf("\n");
}