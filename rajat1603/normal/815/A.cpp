#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int arr[N][N];
int row[N];
int col[N];
int who , how;
void solve(){
	for(int i = 1 ; i <= m ; ++i){
		col[i] = arr[1][i] - row[1];
		if(col[i] < 0){
			return;
		}
	}
	for(int i = 2 ; i <= n ; ++i){
		row[i] = arr[i][1] - col[1];
		if(row[i] < 0){
			return;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(row[i] + col[j] != arr[i][j]){
				return;
			}
		}
	}
	int tot = 0;
	for(int i = 1 ; i <= n ; ++i){
		tot += row[i];
	}
	for(int i = 1 ; i <= m ; ++i){
		tot += col[i];
	}
	if(tot < how){
		how = tot;
		who = row[1];
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	who = -1;
	how = 1e9 + 9;
	for(int i = 0 ; i <= 500 ; ++i){
		memset(row , 0 , sizeof(row));
		memset(col , 0 , sizeof(col));
		row[1] = i;
		solve();
	}
	if(who == -1){
		printf("-1\n");
		return 0;
	}
	row[1] = who;
	solve();
	printf("%d\n" , how);
	for(int i = 1 ; i <= n ; ++i){
		while(row[i]--){
			printf("row %d\n" , i);
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		while(col[i]--){
			printf("col %d\n" , i);
		}
	}
}