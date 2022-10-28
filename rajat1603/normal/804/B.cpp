#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
char str[N];
int n;
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	int b = 0;
	int ans = 0;
	for(int i = n ; i >= 1 ; --i){
		if(str[i] == 'a'){
			ans = (ans + b) % mod;
			b = (b + b) % mod;
		}
		else{
			b = (b + 1) % mod;
		}
	}
	printf("%d\n" , ans);
}