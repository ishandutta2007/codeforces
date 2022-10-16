#include<cstdio>
#include<iostream>
using namespace std;
int n;
char a[11][11],b[11][11][8];
void rot(int u){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j][u+1]=b[n-j+1][i][u];
}
void flip(int u){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j][u+4]=b[i][n-j+1][u];
}
bool cmp(int u){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]!=b[i][j][u]) return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>b[i][j][1];
	for(int i=1;i<=3;i++) rot(i);
	for(int i=1;i<=4;i++) flip(i);
	for(int i=1;i<=8;i++)
		if(cmp(i)){
			printf("Yes\n");return 0;
		}
	printf("No\n");
}