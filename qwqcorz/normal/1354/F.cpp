#include<bits/stdc++.h>
using namespace std;
const int N=80;

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
inline bool up(int &x,int y){if (x<y) return x=y,1;return 0;}
struct node
{
	int a,b,id;
	bool operator <(const node &x)const
	{
		return b<x.b;
	}
}a[N];
int b[N],dp[N][N][N],from[N][N][N],fromk[N][N][N],c[N];
void get(int i,int j,int k)
{
	if (!i) return;
	c[i]=from[i][j][k];
	get(i-1,j-c[i],fromk[i][j][k]);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=n;i++) b[i]=a[i].a=read(),a[i].b=read(),a[i].id=i;
		sort(b+1,b+1+n);
		int cnt=unique(b+1,b+1+n)-b-1;
		for (int i=1;i<=n;i++) a[i].a=lower_bound(b+1,b+1+cnt,a[i].a)-b;
		sort(a+1,a+1+n);
		memset(dp,0xc0,sizeof(dp));
		dp[0][0][0]=0;
		for (int i=1;i<=n;i++)
		for (int j=0;j<m;j++)
		for (int k=0;k<=cnt;k++)
		if (dp[i-1][j][k]>=0)
		{
			if (up(dp[i][j+1][k],dp[i-1][j][k]+b[a[i].a]+a[i].b*j))
			from[i][j+1][k]=1,fromk[i][j+1][k]=k;
			if (up(dp[i][j][max(k,a[i].a)],dp[i-1][j][k]+a[i].b*(m-1)))
			from[i][j][max(k,a[i].a)]=0,fromk[i][j][max(k,a[i].a)]=k;
		}
		int ans=-1,t=0;
		for (int k=0;k<=cnt;k++) if (up(ans,dp[n][m-1][k]+b[k])) t=k;
		get(n,m-1,t);
		vector<int>o,p;
		for (int i=1;i<=n;i++) if (c[i]) o.push_back(a[i].id);
		for (int i=1;i<=n;i++) if (!c[i]) p.push_back(i);
		sort(p.begin(),p.end(),[&](int x,int y){return a[x].a<a[y].a;});
		for (int i:p) o.push_back(a[i].id),o.push_back(-a[i].id);
		o.pop_back();
		print(o.size());
		for (int i:o) print(i,' ');
		puts("");
	}
	
	return 0;
}
//dp
//O(Tnm)