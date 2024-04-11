#include<bits/stdc++.h>
#define int long long
using namespace std;

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
priority_queue<int>q;

signed main()
{
	int n=read(),ans=0;
	while (n--)
	{
		int x=read();
		q.push(x);
		if (q.top()!=x)
		{
			ans+=q.top()-x;
			q.push(x);
			q.pop();
		}
	}
	print(ans);

	return 0;
}