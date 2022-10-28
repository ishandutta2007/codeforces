#include "bits/stdc++.h"
using namespace std;
int n , x;
int arr;
int main(){
	scanf("%d %d" , &n , &x);
	long long sum = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr);
		sum += arr;
	}
	sum += n - 1;
	if(sum == x){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}