#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int n,m,x,y,s,e,q,v,d[30];
double ABCDEFGHIJKLMNOPQRSTUVWXYZ[30][30],ABCDEFGHIJKLMNOPQRSTUVWXY[485][485],u;
int main()
{
	cin>>n>>m>>s>>e,--s,--e,q=n*n;
	rep(i,m)
		cin>>x>>y,d[--x]++,d[--y]++,ABCDEFGHIJKLMNOPQRSTUVWXYZ[x][y]=ABCDEFGHIJKLMNOPQRSTUVWXYZ[y][x]=1;
	rep(i,n)
		cin>>ABCDEFGHIJKLMNOPQRSTUVWXYZ[i][i];
	rep(i,n)
		rep(j,n)
			if(i!=j)
				ABCDEFGHIJKLMNOPQRSTUVWXYZ[i][j]*=(1-ABCDEFGHIJKLMNOPQRSTUVWXYZ[i][i])/d[i];
	rep(i,n)
		rep(j,n)
		{
			ABCDEFGHIJKLMNOPQRSTUVWXY[i*n+j][i*n+j]=-1;
			if(i!=j)
				rep(k,n)
					rep(l,n)
						ABCDEFGHIJKLMNOPQRSTUVWXY[k*n+l][i*n+j]+=ABCDEFGHIJKLMNOPQRSTUVWXYZ[i][k]*ABCDEFGHIJKLMNOPQRSTUVWXYZ[j][l];
		}
	ABCDEFGHIJKLMNOPQRSTUVWXY[s*n+e][q]=-1;
	rep(i,q)
	{
		for(int j=v=i;j<q;j++)
			if(fabs(ABCDEFGHIJKLMNOPQRSTUVWXY[j][i])>fabs(ABCDEFGHIJKLMNOPQRSTUVWXY[v][i]))
				v=j;
		rep(k,q+1)
			swap(ABCDEFGHIJKLMNOPQRSTUVWXY[v][k],ABCDEFGHIJKLMNOPQRSTUVWXY[i][k]);
		u=ABCDEFGHIJKLMNOPQRSTUVWXY[i][i];
		rep(k,q+1)
			ABCDEFGHIJKLMNOPQRSTUVWXY[i][k]/=u;
		rep(j,q)
			if(u=ABCDEFGHIJKLMNOPQRSTUVWXY[j][i],i!=j)
				rep(k,q+1)
					ABCDEFGHIJKLMNOPQRSTUVWXY[j][k]-=u*ABCDEFGHIJKLMNOPQRSTUVWXY[i][k];
	}
	rep(i,n)
		printf("%.9f ",ABCDEFGHIJKLMNOPQRSTUVWXY[i*n+i][q]);
}