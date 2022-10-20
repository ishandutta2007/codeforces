#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=1e18;
vector<int>rub;
double x[N],y[N];
int p[4][N],t[4];
bool vis[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		double x1=read(),y1=read(),x2=read(),y2=read();
		x[i]=(x1+x2)/2,y[i]=(y1+y2)/2;
		for (int j=0;j<4;j++) p[j][i]=i;
	}
	sort(p[0]+1,p[0]+1+n,[&](int u,int v){return x[u]<x[v];});
	sort(p[1]+1,p[1]+1+n,[&](int u,int v){return x[u]>x[v];});
	sort(p[2]+1,p[2]+1+n,[&](int u,int v){return y[u]<y[v];});
	sort(p[3]+1,p[3]+1+n,[&](int u,int v){return y[u]>y[v];});
	for (t[0]=0;t[0]<=k;t[0]++)
	for (t[1]=0;t[0]+t[1]<=k;t[1]++)
	for (t[2]=0;t[0]+t[1]+t[2]<=k;t[2]++)
	{
		t[3]=k-t[0]-t[1]-t[2];
		for (int j=0;j<4;j++)
		for (int i=1,tot=0;i<=n&&tot<t[j];i++)
		if (!vis[p[j][i]])
		{
			tot++;
			vis[p[j][i]]=1;
			rub.push_back(p[j][i]);
		}
		int lx,rx,ly,ry;
		for (lx=1;lx<=n&&vis[p[0][lx]];lx++);
		for (rx=1;rx<=n&&vis[p[1][rx]];rx++);
		for (ly=1;ly<=n&&vis[p[2][ly]];ly++);
		for (ry=1;ry<=n&&vis[p[3][ry]];ry++);
		for (int i:rub) vis[i]=0;
		ans=min(ans,(ll)max(round(x[p[1][rx]]-x[p[0][lx]]),1.0)*(ll)max(round(y[p[3][ry]]-y[p[2][ly]]),1.0));
	}
	print(ans);
	
	return 0;
}