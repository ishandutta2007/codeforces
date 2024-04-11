#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int inf = 1e6 + 6;
int n , m , k;
char str[N][N];
set < int > row[N];
set < int > col[N];
int startx , starty;
int finishx , finishy;
int dist[N][N];
int lft[N][N];
int rgt[N][N];
int up[N][N];
int dwn[N][N];
pair < int , int > que[N * N];
int ql , qr;
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			dist[i][j] = inf;
			if(str[i][j] != '#'){
				row[i].insert(j);
				col[j].insert(i);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			up[i][j] = i;
			lft[i][j] = j;
			if(str[i - 1][j] == '.'){
				up[i][j] = up[i - 1][j];
			}
			if(str[i][j - 1] == '.'){
				lft[i][j] = lft[i][j - 1];
			}
		}
	}
	for(int i = n ; i >= 1 ; --i){
		for(int j = m ; j >= 1 ; --j){
			rgt[i][j] = j;
			dwn[i][j] = i;
			if(str[i + 1][j] == '.'){
				dwn[i][j] = dwn[i + 1][j];
			}
			if(str[i][j + 1] == '.'){
				rgt[i][j] = rgt[i][j + 1];
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			up[i][j] = max(up[i][j] , i - k);
			dwn[i][j] = min(dwn[i][j] , i + k);
			lft[i][j] = max(lft[i][j] , j - k);
			rgt[i][j] = min(rgt[i][j] , j + k);
		}
	}
	scanf("%d %d" , &startx , &starty);
	scanf("%d %d" , &finishx , &finishy);
	dist[startx][starty] = 0;
	row[startx].erase(starty);
	col[starty].erase(startx);
	que[qr++] = make_pair(startx , starty);
	while(ql < qr){
		int x = que[ql].first;
		int y = que[ql].second;
		++ql;
		auto it = row[x].lower_bound(lft[x][y]);
		while(it != row[x].end() && *it <= rgt[x][y]){
			int nx = x;
			int ny = *it;
			dist[nx][ny] = dist[x][y] + 1;
			que[qr++] = make_pair(nx , ny);
			row[nx].erase(ny);
			col[ny].erase(nx);
			it = row[x].lower_bound(lft[x][y]);
		}
		it = col[y].lower_bound(up[x][y]);
		while(it != col[y].end() && *it <= dwn[x][y]){
			int ny = y;
			int nx = *it;
			dist[nx][ny] = dist[x][y] + 1;
			que[qr++] = make_pair(nx , ny);
			col[ny].erase(nx);
			row[nx].erase(ny);
			it = col[y].lower_bound(up[x][y]);
		}
	}
	if(dist[finishx][finishy] >= inf){
		printf("-1\n");
	}
	else{
		printf("%d\n" , dist[finishx][finishy]);
	}
}