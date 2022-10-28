#include "bits/stdc++.h"
using namespace std;
const int N = 15;
int n;
int arr[N];
int main(){
	clock_t timer = clock();
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	while(1.0 * (clock() - timer) / CLOCKS_PER_SEC <= 1.5){

	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}