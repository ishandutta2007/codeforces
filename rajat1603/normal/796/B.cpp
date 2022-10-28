#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , m , k;
int mark[N];
int a , b;
int cur;
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		mark[i] = 0;
	}
	cur = 1;
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d" , &a);
		mark[a] = 1;
	}
	if(mark[1]){
		printf("1\n");
		return 0;
	}
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d %d" , &a , &b);
		if(cur == a){
			cur = b;
		}
		else if(cur == b){
			cur = a;
		}
		if(mark[cur]){
			printf("%d\n" , cur);
			return 0;
		}
	}
	printf("%d\n" , cur);
}