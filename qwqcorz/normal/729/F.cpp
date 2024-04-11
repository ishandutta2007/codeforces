#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5;
const int inf=1e9+7;

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
int a[N];
const int M=1e8+7;
struct hash_table
{
	int t[M];
	hash_table(){memset(t,0x3f,sizeof(t));}
	int hash(int x,int y,int z,int w)
	{
		unsigned long long ret=x;
		ret=ret*4005+y;
		ret=ret*2+z;
		ret=ret*4005+w;
		ret%=M;
		return ret;
	}
	bool count(int x,int y,int z,int w){return t[hash(x,y,z,w)]<inf;}
	int &a(int x,int y,int z,int w){return t[hash(x,y,z,w)];}
}dp;
int dfs(int l,int r,int w,int k)
{
	if (k>r-l+1) return 0;
	if (k==r-l+1) return (w==0?1:-1)*(a[r]-a[l-1]);
	if (dp.count(l,r,w,k)) return dp.a(l,r,w,k);
	if (w==0)
	{
		int ret=-inf;
		for (int i=k;i<=k+1;i++) ret=max(ret,a[l+i-1]-a[l-1]+dfs(l+i,r,1,i));
		return dp.a(l,r,w,k)=ret;
	}
	else
	{
		int ret=inf;
		for (int i=k;i<=k+1;i++) ret=min(ret,-a[r]+a[r-i]+dfs(l,r-i,0,i));
		return dp.a(l,r,w,k)=ret;
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=a[i-1]+read();
	print(dfs(1,n,0,1));
	
	return 0;
}