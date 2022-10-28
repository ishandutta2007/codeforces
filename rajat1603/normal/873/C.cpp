#include "bits/stdc++.h"
using namespace std;
const int N = 2e2 + 2;
int n , m , k;
int arr[N][N];
int ans;
int cnt;
int solve(int col){
	int score = 0;
	int count = 0;
	int cur = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i][col] == 1){
			int tot = 0;
			for(int j = i ; j < i + k && j <= n ; ++j){
				tot += arr[j][col];
			}
			if(tot > score){
				score = tot;
				count = cur;
			}
			++cur;
		}
	}
	ans += score;
	cnt += count;
}
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	for(int j = 1 ; j <= m ; ++j){
		solve(j);
	}
	printf("%d %d\n" , ans , cnt);
}