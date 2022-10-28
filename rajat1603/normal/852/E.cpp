#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int deg[N];
int a , b;
int pw2[N];
int main(){
	scanf("%d" , &n);
	if(n == 1){
		printf("1\n");
		return 0;
	}
	pw2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		pw2[i] = (pw2[i - 1] << 1) % mod;
	}
	int leaves = 0;
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		++deg[a];
		++deg[b];
	}
	for(int i = 1 ; i <= n ; ++i){
		leaves += deg[i] == 1;
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		leaves -= deg[i] == 1;
		ans = (ans + pw2[n - leaves]) % mod;
		leaves += deg[i] == 1;
	}
	printf("%d\n" , ans);
}