#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e5+1e3+7;

int n,m,q,p[N],a[N],pos[N],nxp[N],nxt[N][19],mn[N][19],LOG[N];

void pre()
{
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			mn[i][j]=0x7fffffff;
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
}

int query(int l,int r)
{
	int k=LOG[r-l+1];
	int val=min(mn[l][k-1],mn[r-(1<<(k-1))+1][k-1]);
	return val<=r&&val!=0;
}

int main()
{
	scanf("%d%d%d",&m,&n,&q);
	LOG[0]=0;
	for(int i=1;i<=n;i++)
		LOG[i]=LOG[i>>1]+1;
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		pos[p[i]]=i;
	for(int i=1;i<=n;i++)
		a[i]=pos[a[i]];
	for(int i=1;i<=m+1;i++)
		nxp[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		nxt[i][0]=nxp[a[i]%m+1];
		nxp[a[i]]=i;
	}
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n+1;i++)
			nxt[i][j]=n+1;
	nxt[n+1][0]=n+1;
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
	{
		int mnw=i;
		int spc=m-1;
		for(int j=18;j>=0;j--)
			if(spc>=(1<<j))
			{
				mnw=nxt[mnw][j];
				spc-=(1<<j);
			}
		mn[i][0]=mnw;
	}
	pre();
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d",query(l,r));
	}
}
/*
3 6 3
2 1 3
1 2 3 1 2 3
1 5
2 6
3 5
*/