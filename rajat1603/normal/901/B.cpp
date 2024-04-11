#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n;
int arr[N][N];
int main(){
	scanf("%d" , &n);
	memset(arr , 0 , sizeof(arr));
	arr[0][0] = 1;
	arr[1][1] = 1;
	for(int i = 2 ; i <= n ; ++i){
		arr[i][0] = arr[i - 2][0];
		for(int j = 1 ; j <= i ; ++j){
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 2][j]) & 1;
		}
	}
	printf("%d\n" , n);
	for(int i = 0 ; i <= n ; ++i){
		printf("%d " , arr[n][i]);
	}
	printf("\n");
	printf("%d\n" , n - 1);
	for(int i = 0 ; i < n ; ++i){
		printf("%d " , arr[n - 1][i]);
	}
	printf("\n");
}