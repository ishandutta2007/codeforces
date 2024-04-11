#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int w[N],h[N];

signed main()
{
	h[0]=inf;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		w[i]=read();
		h[i]=read();
		if (max(w[i],h[i])<=h[i-1]) h[i]=max(w[i],h[i]);
							   else h[i]=min(w[i],h[i]);
		if (h[i]>h[i-1]) return puts("NO"),0;
	}
	puts("YES");

	return 0;
}