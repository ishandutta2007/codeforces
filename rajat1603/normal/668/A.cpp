#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int dummy = 1e9 + 7;
int n , m , q;
struct data{
	int row;
	int col;
	int val;
};
data arr[N][N];
int type , r , c , x;
int print[N][N];
int main(){
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			arr[i][j].row = i;
			arr[i][j].col = j;
			arr[i][j].val = dummy;
		}
	}
	for(int I = 1 ; I <= q ; ++I){
		scanf("%d" , &type);
		if(type == 1){
			scanf("%d" , &r);
			for(int i = 2 ; i <= m ; ++i){
				swap(arr[r][i - 1] , arr[r][i]);
			}
		}
		if(type == 2){
			scanf("%d" , &c);
			for(int j = 2 ; j <= n ; ++j){
				swap(arr[j - 1][c] , arr[j][c]);
			}
		}
		if(type == 3){
			scanf("%d %d %d" , &r , &c , &x);
			arr[r][c].val = x;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			print[arr[i][j].row][arr[i][j].col] = arr[i][j].val;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(print[i][j] == dummy){
				print[i][j] = 0;
			}
			printf("%d " , print[i][j]);
		}
		printf("\n");
	}
}