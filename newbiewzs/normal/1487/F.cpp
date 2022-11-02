#include<bits/stdc++.h>
using namespace std;
char v[55];
int a[55];
int n;
int f[55][55][505][2];
int bc,bx;
int dfs(int pos,int c,int x,int flag){
	if(pos==n){
		if(c)return  1e9+7;
		else return 0;
	}
	if(pos==3 and c==0 and x==0 and flag==1){
		new char;
	}
	if(x<-bx || x>bx || c<-bc || c>bc)return 1e9+7;
	if(f[pos][c+bc][x+bx][flag==1]!=-1)return f[pos][c+bc][x+bx][flag==1];
	f[pos][c+bc][x+bx][flag==1]=min(dfs(pos,c,x+flag,flag)+n-pos,min(dfs(pos+1,c*10+a[pos+1]-x,x,-1),dfs(pos+1,c*10+a[pos+1]-x,x,1)));
	return f[pos][c+bc][x+bx][flag==1];
}
int main(){
	scanf("%s",v+2);
	n=strlen(v+2);
	a[1]=0;
	bc=25;
	bx=250;
	n++;
	memset(f,-1,sizeof(f));
	for(int i=2;i<=n;i++){
		a[i]=(v[i]^48);
	}
	cout<<dfs(0,0,0,1)<<endl;
	//cout<<f[3][0+bc][0+bx][1]<<endl;
	return 0;
}