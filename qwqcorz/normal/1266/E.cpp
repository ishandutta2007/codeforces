#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

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
map<int,int>mp[N];
int a[N],b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) ans+=a[i]=read();
	int q=read();
	while (q--)
	{
		int s=read(),t=read(),u=read();
		if (mp[s].count(t))
		{
			int x=mp[s][t];
			ans+=--b[x]<a[x];
			mp[s].erase(t);
		}
		if (u)
		{
			mp[s][t]=u;
			ans-=++b[u]<=a[u];
		}
		print(ans);
	}
	
	return 0;
}