#include<bits/stdc++.h>
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
int n,k;
int fix(int &x){if (!x) x=n;if (x>n) x-=n;return x;}
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int Ask(int x)
{
	printf("? %d\n",x),fflush(stdout);
	return read();
}
void Answer(int x)
{
	printf("! %d\n",x),fflush(stdout);
	exit(0);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),k=read();
	int step=sqrt(n),now=1,tmp;
	while (gcd(step,n)>1) step--;
	while ((tmp=Ask(now))==k) fix(now+=step);
	step=tmp>k?-1:1;
	while (Ask(fix(now+=step))!=k);
	Answer(now);
	
	return 0;
}