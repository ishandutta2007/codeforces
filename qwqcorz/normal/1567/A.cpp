#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
char a[N];
void GunRose()
{
	int n=read();
	scanf("%s",a+1);
	for (int i=1;i<=n;i++)
	if (a[i]=='U') a[i]='D';
	else if (a[i]=='D') a[i]='U';
	puts(a+1);
}

signed main()
{
	int T=read();
	while (T--) GunRose();
	
	return 0;
}