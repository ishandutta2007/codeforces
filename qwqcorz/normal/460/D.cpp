#include<bits/stdc++.h>
#define int long long
using namespace std;

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
int ans=1e12;
vector<int>a,b;
void dfs(int l,int r,int k,int x)
{
	if (l>r)
	{
		if (b.empty()) return;
		if (x<ans) ans=x,a=b;
		return;
	}
	dfs(l+1,r,k,x);
	if (k==(int)b.size()) return;
	b.push_back(l);
	dfs(l+1,r,k,x^l);
	b.pop_back();
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int l=read(),r=read(),k=read();
	if (r-l+1>=7&&k>=4)
	{
		for (int i=l;i<=r-3;i++) if (i%4==0)
		{
			puts("0\n4");
			print(i,' '),print(i+1,' '),print(i+2,' '),print(i+3);
			return 0;
		}
		assert(false);
	}
	else if (k==1)
	{
		print(l);
		puts("1");
		print(l);
	}
	else if (r-l<=6)
	{
		dfs(l,r,k,0);
		print(ans);
		print(a.size());
		for (int i:a) print(i,' ');
	}
	else if (k==2)
	{
		for (int i=l;i<=r;i++) if (i%2==0)
		{
			puts("1\n2");
			print(i,' '),print(i+1,' ');
			return 0;
		}
		assert(false);
	}
	else if (k==3)
	{
		for (int i=1;i<=50;i++)
		{
			int x=(1LL<<i)-1,y=(1LL<<i)+(1LL<<i-1);
			if (l<=x&&y<=r)
			{
				puts("0\n3");
				print(x,' '),print(y-1,' '),print(y);
				return 0;
			}
		}
		for (int i=l;i<=r;i++) if (i%2==0)
		{
			puts("1\n2");
			print(i,' '),print(i+1,' ');
			return 0;
		}
		assert(false);
	}
	
	return 0;
}