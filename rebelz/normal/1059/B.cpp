#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,m;
char map[1005][1005],my[1005][1005];
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};

void judge(int i,int j){
	for(int k=0;k<8;k++)
		if(map[i+dir[k][0]][j+dir[k][1]]!='#')
			return;
	for(int k=0;k<8;k++)
		my[i+dir[k][0]][j+dir[k][1]]='#';
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map[i][j];
	for(int i=2;i<=n-1;i++)
		for(int j=2;j<=m-1;j++)
			judge(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]=='#'&&my[i][j]!='#'){
				cout<<"NO"<<endl;
				return 0;
			}
	cout<<"YES"<<endl;
	return 0;
}