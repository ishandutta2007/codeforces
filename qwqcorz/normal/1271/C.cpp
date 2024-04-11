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

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),sx=read(),sy=read(),ans1=0,ans2=0,ans3=0,ans4=0;
	for (int i=1;i<=n;i++)
	{
		int x=read()-sx,y=read()-sy;
		if (y<0) ans1++;
		if (x<0) ans2++;
		if (y>0) ans3++;
		if (x>0) ans4++;
	}
	int ans=max(max(ans1,ans2),max(ans3,ans4));
	print(ans);
	if (ans1==ans) return print(sx,' '),print(sy-1),0;
	if (ans2==ans) return print(sx-1,' '),print(sy),0;
	if (ans3==ans) return print(sx,' '),print(sy+1),0;
	if (ans4==ans) return print(sx+1,' '),print(sy),0;
	
	return 0;
}