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
map<int,int>A;
map<pair<int,int>,int>B;

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),k=read(),b=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read(),vx=read(),vy=read(),tmp=vy-k*vx;
		ans+=A[tmp]-B[make_pair(vx,vy)];
		A[tmp]++,B[make_pair(vx,vy)]++;
	}
	print(ans*2);
	
	return 0;
}