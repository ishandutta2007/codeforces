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
int p[N],n;
int Ask(int x,int y)
{
	putchar('?');
	putchar(' ');
	for (int i=1;i<n;i++) print(x,' ');
	print(y);
	fflush(stdout);
	return read();
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	p[n=read()]=1;
	for (int i=2;i<=n;i++) if (!Ask(1,i)){p[n]=n+2-i;break;}
	for (int i=1;i<=n;i++) if (i!=p[n]) p[Ask(p[n],i)]=i;
	putchar('!');
	for (int i=1;i<=n;i++) printf(" %d",p[i]);
	cout<<endl;
	
	return 0;
}