#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
void query(int *a,int *ans)
{
	int fl=0;
	for(int i=1;i<=n;i++)
		if(a[i]) fl=1;
	if(!fl)
	{
		for(int i=1;i<=n;i++)
			ans[i]=0;
		return;
	}
	printf("? ");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf(" %c",&ch);
		ans[i]=ch-'0';
	}
}
int d[100005],a[100005],A[100005],B[100005],vis[100005],lim,len;
int nans[15][100005],e[100005][2],t,C[100005],D[100005],E[100005];
vector<int> val[100005];
void add(int u,int v)
{
	e[++t][0]=u;
	e[t][1]=v;
}
void solve(int fl)
{
	for(int j=0;j<len;j++)
	{
		for(int i=1;i<=n;i++)
			a[i]=0;
		for(int i=fl;i<=n;i+=3)
		{
			int sz=val[i].size();
			for(int k=0;k<sz;k++)
				if(k&(1<<j)) a[val[i][k]]=1;
		}
		query(a,nans[j]);
	}
	for(int i=fl+1;i<=n;i+=3)
	{
		int sz=val[i].size();
		for(int k=0;k<sz;k++)
		{
			int v=val[i][k],nw=0;
			for(int j=0;j<len;j++)
				nw|=(nans[j][v]<<j);
			add(v,val[i-1][nw]);
		}
	}
}
#define getans(p,r,x) for(int j=1;j<=n;j++) \
						a[j]=0; \
					for(int j=1;j<=n;j++) \
						if(p) \
							a[j]=r; \
					query(a,x);
int main()
{
	memset(d,-1,sizeof(d));
	scanf("%d",&n);
	lim=1,len=0;
	while(lim<=n) lim<<=1,len++;
	d[1]=0;
	for(int i=len-1;i>=0;i--)
	{
		getans(d[j]!=-1,(1<<i)-1,A);
		int ffl=0;
		for(int j=2;j<=n;j++)
			if(!A[j]) ffl=1;
		if(!ffl) continue;
		getans(d[j]!=-1,(1<<i),B);
		for(int j=1;j<=n;j++)
			if(A[j]||d[j]!=-1) B[j]=0;
		getans(d[j]!=-1&&d[j]%(1<<(i+2))==0,(1<<i),C);
		for(int j=1;j<=n;j++)
			if(vis[j]%2==0&&!C[j]) B[j]=0;
		getans(B[j]&&vis[j]%2==0,(1<<i)-1,D);
		for(int j=1;j<=n;j++)
			D[j]&=!C[j];
		getans(d[j]!=-1&&d[j]%(1<<(i+2))!=0,(1<<i),C);
		for(int j=1;j<=n;j++)
			if(vis[j]%2&&!C[j]) B[j]=0;
		getans(B[j]&&vis[j]%2,(1<<i)-1,E);
		for(int j=1;j<=n;j++)
			E[j]&=!C[j];
		for(int j=1;j<=n;j++)
		{
			if(B[j]) d[j]=(1<<i)+(vis[j]<<(i+1));
			vis[j]=(vis[j]<<1)+(B[j]|D[j]|E[j]);
		}
	}
	for(int i=1;i<=n;i++)
		val[d[i]].push_back(i);
	for(int i=0;i<3;i++)
		solve(i);
	printf("!\n");
	for(int i=1;i<=t;i++)
		printf("%d %d\n",e[i][0],e[i][1]);
	return 0;
}