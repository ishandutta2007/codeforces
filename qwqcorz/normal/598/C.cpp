#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long double pi=acos(-1.0L);

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
long double ang[N],ans=pi*2;
int p[N],x,y;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		ang[i]=atan2(1.0L*y,1.0L*x),p[i]=i;
	}
	sort(p+1,p+1+n,[&](int x,int y){return ang[x]<ang[y];});
	for (int i=1;i<n;i++)
	if (ang[p[i+1]]-ang[p[i]]<ans)
	{
		ans=ang[p[i+1]]-ang[p[i]];
		x=p[i],y=p[i+1];
	}
	if (pi*2-ang[p[n]]+ang[p[1]]<ans) print(p[1],' '),print(p[n]);
	else print(x,' '),print(y);
	
	return 0;
}