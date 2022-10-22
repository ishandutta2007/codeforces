#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e2+1e1+7;

int n,k,c[N],w[N],f[N][50001];

int d(int x)
{
	return x+20001;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]),c[i]=w[i]-c[i]*k;
	memset(f,-0x3f,sizeof(f));
	f[0][d(0)]=0;	
	for(int i=1;i<=n;i++)
		for(int j=20000;j>=-20000;j--)
			f[i][d(j)]=max(f[i-1][d(j)],f[i-1][d(j-c[i])]+w[i]);
	printf("%d",f[n][d(0)]==0?-1:f[n][d(0)]);
}