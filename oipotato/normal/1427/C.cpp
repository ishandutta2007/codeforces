#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
int r,n,f[100010],x[100010],y[100010],t[100010],pre[100010];
int main()
{
	scanf("%d%d",&r,&n);
	rep(i,n)scanf("%d%d%d",&t[i],&x[i],&y[i]);
	rep(i,n)f[i]=-2*n;
	x[0]=1;y[0]=1;
	rep(i,n)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(t[i]-t[j]>2*r-2){f[i]=max(f[i],pre[j]+1);break;}
			else if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])f[i]=max(f[i],f[j]+1);
		}
		pre[i]=max(pre[i-1],f[i]);
	}
	printf("%d\n",pre[n]);
    return 0;
}