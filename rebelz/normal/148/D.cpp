#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n,m;
double d[1005][1005][2];

double dfs(double x,double y,int k){
	if(x<0||y<0)
		return 0;
	if(x==0)
		return d[(int)x][(int)y][k]=1.0*k;
	if(y==0)
		return d[(int)x][(int)y][k]=1.0;
	if(d[(int)x][(int)y][k]>=0)
		return d[(int)x][(int)y][k];
	if(k==0)
		d[(int)x][(int)y][k]=x/(x+y)+y/(x+y)*(1-dfs(x,y-1,k^1));
	else
		d[(int)x][(int)y][k]=x/(x+y)+y/(x+y)*(x/(x+y-1)*(1-dfs(x-1,y-1,k^1))+(y-1)/(x+y-1)*(1-dfs(x,y-2,k^1)));
	return d[(int)x][(int)y][k];
}

int main(){
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	printf("%.10lf\n",dfs(n,m,0));
	return 0;
}