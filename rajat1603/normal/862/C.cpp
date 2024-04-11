#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , x;
int arr[N];
int main(){
	scanf("%d %d" , &n , &x);
	if(n == 2 && x == 0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n == 1){
		printf("%d\n" , x);
		return 0;
	}
	for(int i = 1 ; i < n ; ++i){
		arr[i] = i;
		x ^= i;
	}
	arr[n] = x;
	arr[n] ^= 1 << 18;
	for(int i = 1 ; i < n ; ++i){
		arr[i] ^= 1 << 18;
		if(arr[i] != arr[n]){
			break;
		}
		arr[i] ^= 1 << 18;
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}