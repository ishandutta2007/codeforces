#include <bits/stdc++.h>
using namespace std;
bool a[10][10][10],f;
struct node{
	int x,y,p;
};
queue<node> q;
int fxi[9]={0,-1,-1,-1,0,0,1,1,1};
int fxj[9]={-1,-1,0,1,1,0,-1,0,1};
void bfs(){
	node cur,cur1;
	cur.x=8;cur.y=1;cur.p=0;
	q.push(cur);
	int x1,y1;
	while(!q.empty()){
		cur=q.front();q.pop();
		if(cur.p==8){
			f=1;return ;
		}
		for(int i=0;i<9;i++){
			x1=cur.x+fxi[i];
			y1=cur.y+fxj[i];
			if(x1<9&&x1>0&&y1<9&&y1>0){
				if(a[cur.p][x1][y1]==0
					&&a[cur.p+1][x1][y1]==0){
					cur1.x=x1;cur1.y=y1;
					cur1.p=cur.p+1;
					q.push(cur1);
				}
			}
		}
	}
}
int main(){
	char c;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cin>>c;
			if(c=='S')a[0][i][j]=1;
		}
	}
	for(int k=1;k<=8;k++){
		for(int i=k+1;i<=8;i++){
			for(int j=1;j<=8;j++){
				a[k][i][j]=a[k-1][i-1][j];
			}
		}
	}
	bfs();
	if(f){
		cout<<"WIN";
	}else cout<<"LOSE";
	return 0;
}