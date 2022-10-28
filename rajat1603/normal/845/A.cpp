#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n + n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n + n);
	if(arr[n] < arr[n + 1]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}