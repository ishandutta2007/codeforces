#include<bits/stdc++.h>
using namespace std;
const int N=205;

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
int XOR[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),sum=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) XOR[i+j]^=read();
		for (int i=2;i<=n+m;i++) sum+=XOR[i],XOR[i]=0;
		puts(sum?"Ashish":"Jeel");
	}
	
	return 0;
}