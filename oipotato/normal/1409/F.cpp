#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int f[210][210][210];
char s[210],t[10];
void update(int&x,int y){if(y>x)x=y;}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s%s",s+1,t+1);
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int d=0;d<=k;d++)f[i][j][d]=-1000000000;
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<=i;j++)
	for(int d=0;d<=k;d++)
	{
		update(f[i+1][j+(s[i+1]==t[1])][d],f[i][j][d]+(s[i+1]==t[2])*j);
		if(d<k)
		{
			update(f[i+1][j][d+1],f[i][j][d]);
			update(f[i+1][j+1][d+1],f[i][j][d]);
			update(f[i+1][j][d+1],f[i][j][d]+j);
			if(t[1]==t[2])update(f[i+1][j+1][d+1],f[i][j][d]+j);
		}
	}
	int ans=0;
	rep(j,n+1)update(ans,f[n][j-1][k]);
	printf("%d\n",ans);
	return 0;
}