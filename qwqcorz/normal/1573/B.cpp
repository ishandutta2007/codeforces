#include<bits/stdc++.h>
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
int p[N];
void gm()
{
	int n=read(),mn=n,ans=n*2;
	for (int i=1;i<=n;i++) p[read()]=i;
	for (int i=1;i<=n;i++) p[read()]=i;
	for (int i=n*2;i>=1;i--)
	if (i&1) ans=min(ans,p[i]-1+mn-1);
	else mn=min(mn,p[i]);
	print(ans);
}

signed main()
{
	int T=read();
	while (T--) gm();
	
	return 0;
}