#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
const int inf = 1e8;
int n , m;
char str[N][N];
int sx , sy;
int tx , ty;
struct data{
	int up;
	int down;
	int rgt;
	int lft;
	data(){
		up = 0;
		down = 0;
		rgt = 0;
		lft = 0;
	}
	void rotate(){
		int _up = lft;
		int _rgt = up;
		int _down = rgt;
		int _lft = down;
		up = _up;
		rgt = _rgt;
		down = _down;
		lft = _lft;
	}
};
data mat[N][N];
queue < int > qx;
queue < int > qy;
queue < int > qr;
int dist[N][N][4];
inline void relax(int nx , int ny , int nr , int ndist){
	if(dist[nx][ny][nr] > ndist){
		dist[nx][ny][nr] = ndist;
		qx.push(nx);
		qy.push(ny);
		qr.push(nr);
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
			if(str[i][j] == '+'){
				mat[i][j].up = 1;
				mat[i][j].lft = 1;
				mat[i][j].rgt = 1;
				mat[i][j].down = 1;
			}
			if(str[i][j] == '-'){
				mat[i][j].up = 0;
				mat[i][j].lft = 1;
				mat[i][j].rgt = 1;
				mat[i][j].down = 0;
			}
			if(str[i][j] == '|'){
				mat[i][j].up = 1;
				mat[i][j].lft = 0;
				mat[i][j].rgt = 0;
				mat[i][j].down = 1;
			}
			if(str[i][j] == '^'){
				mat[i][j].up = 1;
				mat[i][j].lft = 0;
				mat[i][j].rgt = 0;
				mat[i][j].down = 0;
			}
			if(str[i][j] == '>'){
				mat[i][j].up = 0;
				mat[i][j].lft = 0;
				mat[i][j].rgt = 1;
				mat[i][j].down = 0;
			}
			if(str[i][j] == '<'){
				mat[i][j].up = 0;
				mat[i][j].lft = 1;
				mat[i][j].rgt = 0;
				mat[i][j].down = 0;
			}
			if(str[i][j] == 'v'){
				mat[i][j].up = 0;
				mat[i][j].lft = 0;
				mat[i][j].rgt = 0;
				mat[i][j].down = 1;
			}
			if(str[i][j] == 'L'){
				mat[i][j].up = 1;
				mat[i][j].lft = 0;
				mat[i][j].rgt = 1;
				mat[i][j].down = 1;
			}
			if(str[i][j] == 'R'){
				mat[i][j].up = 1;
				mat[i][j].lft = 1;
				mat[i][j].rgt = 0;
				mat[i][j].down = 1;
			}
			if(str[i][j] == 'U'){
				mat[i][j].up = 0;
				mat[i][j].lft = 1;
				mat[i][j].rgt = 1;
				mat[i][j].down = 1;
			}
			if(str[i][j] == 'D'){
				mat[i][j].up = 1;
				mat[i][j].lft = 1;
				mat[i][j].rgt = 1;
				mat[i][j].down = 0;
			}
			if(str[i][j] == '*'){
				mat[i][j].up = 0;
				mat[i][j].lft = 0;
				mat[i][j].rgt = 0;
				mat[i][j].down = 0;
			}
		}
	}
	scanf("%d %d" , &sx , &sy);
	scanf("%d %d" , &tx , &ty);
	for(int i = 0 ; i <= n + 1 ; ++i){
		for(int j = 0 ; j <= m + 1 ; ++j){
			for(int k = 0 ; k < 4 ; ++k){
				dist[i][j][k] = inf;
			}
		}
	}
	relax(sx , sy , 0 , 0);
	while(!qx.empty()){
		int x = qx.front();
		int y = qy.front();
		int r = qr.front();
		int d = dist[x][y][r];
		qx.pop();
		qy.pop();
		qr.pop();
		relax(x , y , (r + 1) & 3 , d + 1);
		data tmp = mat[x][y];
		data tmprgt = mat[x][y + 1];
		data tmpdown = mat[x + 1][y];
		data tmplft = mat[x][y - 1];
		data tmpup = mat[x - 1][y];
		for(int i = 0 ; i < r ; ++i){
			tmp.rotate();
			tmprgt.rotate();
			tmpdown.rotate();
			tmplft.rotate();
			tmpup.rotate();
		}
		if(tmp.rgt && tmprgt.lft){
			relax(x , y + 1 , r , d + 1);
		}
		if(tmp.lft && tmplft.rgt){
			relax(x , y - 1 , r , d + 1);
		}
		if(tmp.up && tmpup.down){
			relax(x - 1 , y , r , d + 1);
		}
		if(tmp.down && tmpdown.up){
			relax(x + 1 , y , r , d + 1);
		}
	}
	int ans = inf;
	for(int i = 0 ; i < 4 ; ++i){
		ans = min(ans , dist[tx][ty][i]);
	}
	if(ans >= inf){
		ans = -1;
	}
	printf("%d\n" , ans);
}