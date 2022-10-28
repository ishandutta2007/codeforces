#include "bits/stdc++.h"
using namespace std;
int n , k;
int main(){
	scanf("%d %d" , &n , &k);
	if(k > n){
		printf("-1\n");
	}
	else if(k == 1){
		if(n == 1){
			printf("a");
		}
		else{
			printf("-1");
		}
	}
	else{
		int cur = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(cur + (n - i) >= k){
				if(i & 1){
					printf("a");
					cur = max(cur , 1);
				}
				else{
					printf("b");
					cur = max(cur , 2);
				}
			}
			else{
				printf("%c" , char('a' + cur));
				++cur;
			}
		}
	}
	printf("\n");
}