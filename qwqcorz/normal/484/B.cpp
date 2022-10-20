#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int inf=INT_MAX;

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

int main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	a[n+1]=inf;
	for (int i=1;i<=n;i++)
	for (int j=2*a[i];j-a[i]<=a[n];j+=a[i])
	{
		int k=lower_bound(a+1,a+n+2,j)-a-1;
		ans=max(ans,a[k]%a[i]);
	}
	print(ans);

	return 0;
}