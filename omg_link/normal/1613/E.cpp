#include <stdio.h>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<char>> c(n,vector<char>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %c",&c[i][j]);
	auto isFree = [&](int x,int y)->bool{
		if(x<0||x>=n||y<0||y>=m) return false;
		return c[x][y]=='.';
	};
	auto calc = [&](int x,int y)->int{
		if(c[x][y]!='.') return 23333;
		return isFree(x-1,y)+isFree(x+1,y)+isFree(x,y-1)+isFree(x,y+1);
	};
	int sx=-1,sy=-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(c[i][j]=='L'){
				sx = i;
				sy = j;
			}
		}
	using Pos = struct{
		int x,y;
	};
	queue<Pos> q;
	q.push({sx,sy});
	auto upd = [&](int x,int y)->void{
		if(!isFree(x,y)) return;
		if(calc(x,y)<=1){
			c[x][y] = '+';
			q.push({x,y});
		}
	};
	while(!q.empty()){
		Pos p = q.front();
		q.pop();
		upd(p.x-1,p.y);
		upd(p.x+1,p.y);
		upd(p.x,p.y-1);
		upd(p.x,p.y+1);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%c",c[i][j]);
		puts("");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}