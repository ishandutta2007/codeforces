#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
char str[N];
int ans , cur;
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i < n ; ++i){
		scanf("%s" , str);
	}
	scanf("%s" , str + 1);
	ans = 0;
	cur = 0;
	for(int i = 1 ; i <= m ; ++i){
		if(str[i] == 'B'){
			cur = 1;
		}
		else{
			ans += cur;
			cur = 0;
		}
	}
	printf("%d\n" , ans + cur);
}