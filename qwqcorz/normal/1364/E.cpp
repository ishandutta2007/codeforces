#include<bits/stdc++.h>
using namespace std;
const int N=5e3;

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
int Ask(int i,int j)
{
	printf("? %d %d\n",i,j);
	fflush(stdout);
	return read();
}
mt19937 rnd(time(0));
int ans[N],n,x,val;
int get(int x)
{
	int ret=2047;
	for (int i=1;i<=15;i++)
	{
		int y=rnd()%n+1;
		while (y==x) y=rnd()%n+1;
		ret&=Ask(x,y);
	}
	return ret;
}

signed main()
{
	n=read(),x=rnd()%n+1,val=get(x);
	for (int i=1;i<=n;i++) if (i!=x&&Ask(i,x)==val) x=i,val=get(x);
	for (int i=1;i<=n;i++) if (i!=x) ans[i]=Ask(i,x);
	printf("! ");
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	fflush(stdout);
	
	return 0;
}