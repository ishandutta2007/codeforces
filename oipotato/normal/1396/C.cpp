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
const int N=1000010;
int a[N],r1,r2,r3,n,d;
long long f[N][3],inf;
void update(long long&x,long long y){if(y<x)x=y;}
int main()
{
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);r1=min(r1,r3);
	inf=(r2+2ll*d+r1)*n;
	rep(i,n)scanf("%d",&a[i]);
	f[0][0]=0;f[0][1]=f[0][2]=inf;rep(i,n)for(int j=0;j<=2;j++)f[i][j]=inf;
	rep(i,n)
	{
		long long cost=min(1ll*a[i]*r1+2*r1,0ll+r2+r1);
		update(f[i][0],f[i-1][0]+cost+2*d);
		if(i<n)update(f[i][1],f[i-1][0]+cost+1ll*(n-i)*d);
		update(f[i][2],f[i-1][0]+cost+2*d);
		update(f[i][1],f[i-1][1]+cost+(i==n?2*d:0));
		update(f[i][0],f[i-1][2]+cost);
		cost=1ll*a[i]*r1+r3;
		update(f[i][0],f[i-1][0]+cost);
		update(f[i][1],f[i-1][1]+cost);
		//for(int j=0;j<3;j++)printf("%d %d %lld\n",i,j,f[i][j]);
	}
	printf("%lld\n",min(f[n][0],f[n][1])+1ll*(n-1)*d);
	return 0;
}