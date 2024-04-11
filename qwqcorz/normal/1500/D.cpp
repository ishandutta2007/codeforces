#include<bits/stdc++.h>
using namespace std;
const int N=1505;
const int Q=11;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool vis[N*N];
int a[N][N],ans[N],n,q,f;
int cl[2][N][Q],cu[2][N][Q],clu[2][N][Q];//color
int dl[2][N][Q],du[2][N][Q],dlu[2][N][Q];//distance
int tl[2][N],tu[2][N],tlu[2][N];//total
inline void up(int *c,int *d,int x)
{
	int tmpc=c[x],tmpd=d[x];
	for (int i=x;i>=1;i--) c[i]=c[i-1],d[i]=d[i-1];
	c[0]=tmpc;
	d[0]=tmpd;
}
inline void insert(int *c,int *d,int &t,int x)
{
	for (int i=0;i<t;i++) d[i]++;
	for (int i=0;i<t;i++) if (c[i]==x) return d[i]=0,up(c,d,i),void();
	if (t<=q) c[t]=x,d[t]=0,up(c,d,t),t++;
		 else c[t-1]=x,d[t-1]=0,up(c,d,t-1);
}
inline void merge(int *c1,int *d1,int &t1,int *c2,int *d2,int t2)
{
	static int c[Q],d[Q],i,j,k;
	for (i=0,j=0,k=0;i<t1&&j<t2&&k<=q;)
	if (d1[i]<d2[j])
	{
		if (!vis[c1[i]])
		{
			vis[c1[i]]=1;
			c[k]=c1[i];
			d[k]=d1[i];
			k++;
		}
		i++;
	}
	else
	{
		if (!vis[c2[j]])
		{
			vis[c2[j]]=1;
			c[k]=c2[j];
			d[k]=d2[j];
			k++;
		}
		j++;
	}
	while (i<t1&&k<=q)
	{
		if (!vis[c1[i]])
		{
			vis[c1[i]]=1;
			c[k]=c1[i];
			d[k]=d1[i];
			k++;
		}
		i++;
	}
	while (j<t2&&k<=q)
	{
		if (!vis[c2[j]])
		{
			vis[c2[j]]=1;
			c[k]=c2[j];
			d[k]=d2[j];
			k++;
		}
		j++;
	}
	for (i=0;i<k;i++) vis[c[i]]=0;
	memcpy(c1,c,sizeof(c));
	memcpy(d1,d,sizeof(d));
	t1=k;
}
//int de[N][N];

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[i][j]=read();
	for (int i=1,p=0;i<=n;i++,p^=1)
	for (int j=1;j<=n;j++)
	{
		/////////////////////////////////////////////row
		memcpy(cl[p][j],cl[p][j-1],sizeof(cl[p][j]));
		memcpy(dl[p][j],dl[p][j-1],sizeof(dl[p][j]));
		tl[p][j]=tl[p][j-1];
		insert(cl[p][j],dl[p][j],tl[p][j],a[i][j]);
		/////////////////////////////////////////////column
		memcpy(cu[p][j],cu[!p][j],sizeof(cu[p][j]));
		memcpy(du[p][j],du[!p][j],sizeof(du[p][j]));
		tu[p][j]=tu[!p][j];
		insert(cu[p][j],du[p][j],tu[p][j],a[i][j]);
		/////////////////////////////////////////////square
		memcpy(clu[p][j],clu[!p][j-1],sizeof(clu[p][j]));
		memcpy(dlu[p][j],dlu[!p][j-1],sizeof(dlu[p][j]));
		tlu[p][j]=tlu[!p][j-1];
		merge(clu[p][j],dlu[p][j],tlu[p][j],cl[p][j-1],dl[p][j-1],tl[p][j-1]);
		merge(clu[p][j],dlu[p][j],tlu[p][j],cu[!p][j],du[!p][j],tu[!p][j]);
		insert(clu[p][j],dlu[p][j],tlu[p][j],a[i][j]);
		/////////////////////////////////////////////calculate
		if (tlu[p][j]<=q) f=min(i,j);
					 else f=min(min(i,j),dlu[p][j][q]);
		ans[f]++;
//		print(tlu[p][j],j==n?'\n':' ');
//		print(tlu[p][j],':');
//		for (int k=0;k<tlu[p][j];k++) print(clu[p][j][k],' ');
//		putchar(',');
//		putchar(' ');
//		for (int k=0;k<tlu[p][j];k++) print(dlu[p][j][k],' ');
//		puts("");
//		de[i][j]=f;
	}
//	for (int i=1;i<=n;i++)
//	for (int j=1;j<=n;j++) print(de[i][j],j==n?'\n':' ');
	for (int i=n;i>=1;i--) ans[i]+=ans[i+1];
	for (int i=1;i<=n;i++) print(ans[i]);

	return 0;
}