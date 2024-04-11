#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int inp;
int prv[N + N];
int ans;
int main(){
	scanf("%d" , &n);
	while(n--){
		scanf("%d" , &inp);
		prv[inp] = inp;
	}
	for(int i = 1 ; i < N + N ; ++i){
		prv[i] = max(prv[i - 1] , prv[i]);
	}
	for(int i = 1 ; i < N ; ++i){
		if(prv[i] == i){
			for(int j = i + i - 1 ; j < N + N ; j += i){
				ans = max(ans , prv[j] % i);
			}
		}
	}
	printf("%d\n" , ans);
}