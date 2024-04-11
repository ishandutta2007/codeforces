#include<bits/stdc++.h>
using namespace std;

int oN,o[21],f[1010][1010],g[1010][1010][10][10],fh[1010][1010][10],fl[1010][1010][10],lo[1010],xl,xr,yl,yr,n,m,a[1010][1010],q,ans,cnt,l,r,mid;

int getmax(int a,int b) {return a>b?a:b;}
int getmin(int a,int b) {return a<b?a:b;}

int getans(int xl,int yl,int xr,int yr)
{
	int l1=lo[xr-xl+1],l2=lo[yr-yl+1];
	return getmax(g[xl][yl][l1][l2],getmax(g[xl][yr-(1<<l2)+1][l1][l2],getmax(g[xr-(1<<l1)+1][yl][l1][l2],g[xr-(1<<l1)+1][yr-(1<<l2)+1][l1][l2])));
}

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

void print(int x)
{
	if (!x) putchar('0'); else
	{
		oN=0;
		while (x) o[++oN]=x%10,x/=10;
		for (int i=oN; i; i--) putchar(o[i]+48);
	}
	putchar('\n');
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=1000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) a[i][j]=read();
	for (int i=n; i; i--)
		for (int j=m; j; j--)
			if (!a[i][j]) f[i][j]=0; else
			{
				f[i][j]=min(f[i+1][j],f[i][j+1]);
				if (f[i+1][j]==f[i][j+1]) f[i][j]+=a[i+f[i][j]][j+f[i][j]];
				else f[i][j]++;
			}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++) g[i][j][0][0]=f[i][j];
		for (int k=1; k<10; k++)
			for (int j=1; j+(1<<k)-1<=m; j++)
				g[i][j][0][k]=getmax(g[i][j][0][k-1],g[i][j+(1<<k-1)][0][k-1]);
	}
	for (int j=1; j<10; j++)
		for (int k=0; k<10; k++)
			for (int i=1; i+(1<<j)-1<=n; i++)
				for (int l=1; l+(1<<k)-1<=m; l++)
					g[i][l][j][k]=getmax(g[i][l][j-1][k],g[i+(1<<j-1)][l][j-1][k]);
	q=read();
	while (q--)
	{
		xl=read(),yl=read(),xr=read(),yr=read();
		l=1,r=getmin(xr-xl+1,yr-yl+1),ans=0;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (getans(xl,yl,xr-mid+1,yr-mid+1)>=mid) ans=mid,l=mid+1; else r=mid-1;
		}
		if (ans!=getmin(xr-xl+1,yr-yl+1)) ans=getmax(ans,getans(xl,yl,xr-ans,yr-ans));
		print(ans);
	}
	return 0;
}