#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
bool ans[N];
int p[N];
vector<int>a[N],b[N],c[N],d[N],e[N];
void solve(int n,int m)
{
	for (int i=0;i<n-1;i++)
	for (int j=0;j<m-1;j++)
	if (b[i][j]>c[i+1][j]&&d[i][j+1]<e[i+1][j+1])
	{
		puts("YES");
		for (int k=0;k<=i;k++) ans[p[k]]=1;
		for (int k=i+1;k<n;k++) ans[p[k]]=0;
		for (int k=0;k<n;k++) putchar("BR"[ans[k]]);
		putchar(' ');
		print(j+1);
		return;
	}
	puts("NO");
}
void Multi_test_no_horses()
{
	int n=read(),m=read();
	for (int i=0;i<n;i++) a[i].resize(m);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) a[i][j]=read();
	for (int i=0;i<n;i++) p[i]=i;
	sort(p,p+n,[&](int x,int y){return a[x][0]>a[y][0];});
	for (int i=0;i<n;i++) b[i]=c[i]=d[i]=e[i]=a[p[i]];
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if (i) b[i][j]=min(b[i][j],b[i-1][j]);
		if (j) b[i][j]=min(b[i][j],b[i][j-1]);
	}
	for (int i=n-1;i>=0;i--)
	for (int j=0;j<m;j++)
	{
		if (i<n-1) c[i][j]=max(c[i][j],c[i+1][j]);
		if (j) c[i][j]=max(c[i][j],c[i][j-1]);
	}
	for (int i=0;i<n;i++)
	for (int j=m-1;j>=0;j--)
	{
		if (i) d[i][j]=max(d[i][j],d[i-1][j]);
		if (j<m-1) d[i][j]=max(d[i][j],d[i][j+1]);
	}
	for (int i=n-1;i>=0;i--)
	for (int j=m-1;j>=0;j--)
	{
		if (i<n-1) e[i][j]=min(e[i][j],e[i+1][j]);
		if (j<m-1) e[i][j]=min(e[i][j],e[i][j+1]);
	}
	//bd
	//ce
	solve(n,m);
	for (int i=0;i<n;i++) a[i].clear(),b[i].clear(),c[i].clear(),d[i].clear(),e[i].clear();
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}