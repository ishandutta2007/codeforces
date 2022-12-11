#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = 1005;
int conf[N][N];
queue<pair<int,int>>pos;
void ini(){
	for(int i = 0;i<N;i++)
		for(int j = 0;j<N;j++)
			conf[i][j] = -1;
}

void bfs(){
	while(!pos.empty()){
		int cor1 = pos.front().fi,cor2 = pos.front().se;pos.pop();
		for(int i = cor1+1;i<N&&conf[i][cor2]>=conf[cor1][cor2]+1;i++){
			if(conf[i][cor2]==-1)break;
			if(conf[i][cor2]==INT_MAX){
				conf[i][cor2]=conf[cor1][cor2]+1;
				pos.push(mp(i,cor2));
			}
		}
		for(int j = cor1-1;j>0&&conf[j][cor2]>=conf[cor1][cor2]+1;j--){
			if(conf[j][cor2]==-1)break;
			if(conf[j][cor2]==INT_MAX){
				conf[j][cor2]=conf[cor1][cor2]+1;
				pos.push(mp(j,cor2));
			}
		}
		for(int i = cor2+1;i<N&&conf[cor1][i]>=conf[cor1][cor2]+1;i++){
			if(conf[cor1][i]==-1)break;
			if(conf[cor1][i]==INT_MAX){
				conf[cor1][i]=conf[cor1][cor2]+1;
				pos.push(mp(cor1,i));
			}
		}
		for(int j = cor2-1;j>0&&conf[cor1][j]>=conf[cor1][cor2]+1;j--){
			if(conf[cor1][j]==-1)break;
			if(conf[cor1][j]==INT_MAX){
				conf[cor1][j]=conf[cor1][cor2]+1;
				pos.push(mp(cor1,j));
			}
		}
	}
}

int main(){
	ini();
	int n,m;
	cin >> n >> m;	
	char c;
	int c1,c2,e1,e2;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> c;
			if(c=='.'){
				conf[i][j] = INT_MAX;
			}
			else if(c=='*'){
				conf[i][j] = -1;
			}
			else if(c=='S'){
				c1 = i;
				c2 = j;
			}
			else{
				conf[i][j] = INT_MAX;
				e1 = i;
				e2 = j;
			}
		}
	}
	conf[c1][c2] = 0;
	pos.push(mp(c1,c2));
	bfs();
	if(conf[e1][e2]<=3)puts("YES");
	else puts("NO");
	return 0;
}