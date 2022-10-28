#include "bits/stdc++.h"
using namespace std;
int k;
int main(){
	cin >> k;
	char cur = 'a';
	if(k == 0){
		printf("a\n");
		return 0;
	}
	while(k){
		int tmp = 0;
		while(tmp * (tmp + 1) <= k * 2){
			++tmp;
		}
		for(int j = 0 ; j < tmp ; ++j){
			printf("%c" , cur);
		}
		++cur;
		k -= (tmp * (tmp - 1)) / 2;
	}
	printf("\n");
}