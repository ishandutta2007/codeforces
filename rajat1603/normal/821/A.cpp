#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n;
int arr[N][N];
bool check(int x , int y){
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(arr[x][y] == arr[x][i] + arr[j][y]){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(arr[i][j] > 1){
				if(!check(i , j)){
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
}