#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
char str[N];
int n;
int cnt;
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	for(int i = 1 ; i <= n ; ++i){
		cnt += str[i] == '0';
	}
	for(int i = 1 ; i <= n ; ++i){
		if(str[i] == '1' && cnt >= 6){
			printf("yes\n");
			return 0;
		}
		if(str[i] == '0'){
			--cnt;
		}
	}
	printf("no\n");
}