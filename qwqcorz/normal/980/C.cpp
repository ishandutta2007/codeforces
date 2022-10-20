#include<bits/stdc++.h>
using namespace std;
const int N=512;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];

signed main()
{
	int n=read(),k=read();
	for (int i=0;i<=256;i++) a[i]=i;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		int pre=x-k,nxt=x;
		while (nxt<256&&a[nxt+1]==a[x]) nxt++;
		pre=max(pre+nxt-x,-1);
		while (pre>=0&&pre<x&&a[pre]==a[pre+1]) pre++;
		pre++;
		for (int j=pre;j<=x;j++) a[j]=a[x];
		print(pre,' ');
	}

	return 0;
}