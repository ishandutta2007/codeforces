#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int M = 1e3 + 3;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int n , m;
char str[N][N];
int sx , sy;
int ex , ey;
char arr[M];
int k;
int tmp[4];
int ans;
void check(){
	int x = sx;
	int y = sy;
	for(int i = 1 ; i <= k ; ++i){
		int idx = tmp[arr[i] - '0'];
		x += dx[idx];
		y += dy[idx];
		if(str[x][y] == '#'){
			return;
		}
		if(x == ex && y == ey){
			++ans;
			return;
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
	}
	scanf("%s" , arr + 1);
	k = strlen(arr + 1);
	for(int i = 0 ; i < 4 ; ++i){
		tmp[i] = i;
	}
	for(int i = 0 ; i <= n + 1 ; ++i){
		str[i][0] = str[i][m + 1] = '#';
	}
	for(int i = 1 ; i <= m ; ++i){
		str[0][i] = str[n + 1][i] = '#';
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(str[i][j] == 'S'){
				sx = i;
				sy = j;
				str[i][j] = '.';
			}
			if(str[i][j] == 'E'){
				ex = i;
				ey = j;
				str[i][j] = '.';
			}
		}
	}
	do{
		check();
	}
	while(next_permutation(tmp , tmp + 4));
	printf("%d\n" , ans);
}