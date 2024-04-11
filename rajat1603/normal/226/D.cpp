#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int arr[N][N];
int row[N];
int col[N];
bool ok;
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	do{
		ok = 0;
		for(int i = 1 ; i <= n ; ++i){
			int sum = 0;
			for(int j = 1 ; j <= m ; ++j){
				sum += arr[i][j];
			}
			if(sum < 0){
				row[i] ^= 1;
				for(int j = 1 ; j <= m ; ++j){
					arr[i][j] *= -1;
				}
				ok = 1;
			}
		}
		for(int i = 1 ; i <= m ; ++i){
			int sum = 0;
			for(int j = 1 ; j <= n ; ++j){
				sum += arr[j][i];
			}
			if(sum < 0){
				col[i] ^= 1;
				for(int j = 1 ; j <= n ; ++j){
					arr[j][i] *= -1;
				}
				ok = 1;
			}
		}
	}while(ok);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		ans += row[i];
	}
	printf("%d" , ans);
	for(int i = 1 ; i <= n ; ++i){
		if(row[i]){
			printf(" %d" , i);
		}
	}
	printf("\n");
	ans = 0;
	for(int i = 1 ; i <= m ; ++i){
		ans += col[i];
	}
	printf("%d" , ans);
	for(int i = 1 ; i <= m ; ++i){
		if(col[i]){
			printf(" %d" , i);
		}
	}
	printf("\n");
}