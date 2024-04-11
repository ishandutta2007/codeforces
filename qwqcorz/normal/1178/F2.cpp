#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e3+5;
const int M=1e6+5;
const int p=998244353;

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
pair<int,int>mn[N][N];
int a[M],b[M],l[M],r[M],f[N][N],nxt[M];
int solve(int l,int r)
{
	int n=0;
	vector<pair<int,int>>b,c;
	c.push_back(make_pair(0,0));
	for (int i=l;i<=r;i=nxt[i]+1) n++,b.push_back(make_pair(i,nxt[i]));
	for (auto k:b)
	{
		int L=k.first,R=k.second,j=L,now=1;
		for (int i=L+1;i<=R;i++) if (a[i]==a[L]) now=1LL*now*solve(j+1,i-1)%p,j=i;
		c.push_back(make_pair(a[L],now));
	}
	for (int i=1;i<=n;i++) mn[i][i]=mk(c[i].first,i);
	for (int i=0;i<=n+1;i++)
	for (int j=0;j<=n+1;j++) f[i][j]=1;
	for (int i=1;i<=n;i++) f[i][i]=c[i].second;
	for (int i=2;i<=n;i++)
	for (int j=1;i+j-1<=n;j++)
	{
		int l=j,r=j+i-1,le=0,ri=0;
		int x=(mn[l][r]=min(mn[l][r-1],mn[r][r])).se;
		for (int k=l;k<=x;k++) le=(le+1LL*f[l][k-1]*f[k][x-1])%p;
		for (int k=x;k<=r;k++) ri=(ri+1LL*f[x+1][k]*f[k+1][r])%p;
		f[l][r]=1LL*le*ri%p*f[x][x]%p;
	}
	return f[1][n];
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=m;i++) b[i]=read();
	int cnt=0;
	for (int i=1;i<=m;i++) if (b[i]==1||b[i-1]!=b[i]) a[++cnt]=b[i];
	m=cnt;
	for (int i=1;i<=m;i++) r[a[i]]=i;
	for (int i=m;i>=1;i--) l[a[i]]=i;
	for (int i=1;i<=n;i++)
	for (int j=l[i]+1;j<r[i];j++)
	if (a[j]<i) return puts("0"),0;
	for (int i=1;i<=n;i++) nxt[l[i]]=r[i];
	print(solve(1,m));
	
	return 0;
}