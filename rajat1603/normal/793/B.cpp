#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
const int inf = 3;
int n , m;
char str[N][N];
int dist[N][N][4];
pair < pair < int , int > , int > que[N * N * 10];
int ql , qr;
inline int relax(int x , int y , int dir , int dis){
	if(dist[x][y][dir] > dis){
		dist[x][y][dir] = dis;
		que[qr++] = {{x , y} , dir};
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
	}
	for(int i = 0 ; i <= m + 1 ; ++i){
		str[0][i] = '*';
		str[n + 1][i] = '*';
	}
	for(int i = 0 ; i <= n + 1 ; ++i){
		str[i][0] = '*';
		str[i][m + 1] = '*';
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			for(int k = 0 ; k < 4 ; ++k){
				dist[i][j][k] = inf;
			}
		}
	}
	ql = 0;
	qr = 0;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(str[i][j] == 'S'){
				relax(i , j , 0 , 0);
				relax(i , j , 1 , 0);
				relax(i , j , 2 , 0);
				relax(i , j , 3 , 0);
			}
		}
	}
	while(ql < qr){
		auto node = que[ql++];
		int x = node.first.first;
		int y = node.first.second;
		int dir = node.second;
		int cst = dist[x][y][dir];
		for(int i = 0 ; i < 4 ; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int d = cst + (i != dir);
			if(str[nx][ny] != '*'){
				relax(nx , ny , i , d);
			}
		}
	}
	int ans = inf;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(str[i][j] == 'T'){
				for(int k = 0 ; k < 4 ; ++k){
					ans = min(ans , dist[i][j][k]);
				}
			}
		}
	}
	if(ans <= 2){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}