#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int inp;
int cnt[N];
int main(){
	scanf("%d" , &n);
	while(n--){
		scanf("%d" , &inp);
		cnt[inp] ^= 1;
	}
	for(int i = 0 ; i < N ; ++i){
		if(cnt[i]){
			printf("Conan\n");
			return 0;
		}
	}
	printf("Agasa\n");
}