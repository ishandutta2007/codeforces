#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int n,m;
bool vis[505][505];
char a[505][505];
queue<node> q;
stack<node> s;
void bfs(int x1,int y1){
	node cur,cur1;
	cur.x=x1;cur.y=y1;
	q.push(cur);
	while(!q.empty()){
		cur=q.front();q.pop();
		int i=cur.x,j=cur.y;
		if(i<1||j<1||i>n||j>m)continue;
		if(a[i][j]!='.'||vis[i][j])continue;
		vis[i][j]=1;
		s.push(cur);
		cur1=cur;
		cur1.x++;
		q.push(cur1);
		cur1=cur;
		cur1.x--;
		q.push(cur1);
		cur1=cur;
		cur1.y++;
		q.push(cur1);
		cur1=cur;
		cur1.y--;
		q.push(cur1);
	}
}
int main(){
	int k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	bool f=1;
	for(int i=1;i<=n&&f;i++){
		for(int j=1;j<=m&&f;j++){
			if(a[i][j]=='.'){
				bfs(i,j);
				f=0;
			}
		}
	}
	node cur;
	for(int i=0;i<k;i++){
		cur=s.top();
		s.pop();
		a[cur.x][cur.y]='X';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<a[i][j];
		cout<<'\n';
	}
	return 0;
}