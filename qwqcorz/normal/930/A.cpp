#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
int a[N],deep[N];

signed main()
{
	a[0]=1;
	int n=read(),ans=0;
	for (int i=2;i<=n;i++)
	{
		int fa=read();
		a[deep[i]=deep[fa]+1]++;
	}
	for (int i=0;i<n;i++) ans+=a[i]&1;
	print(ans);
	
	return 0;
}