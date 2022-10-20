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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[5];
vector<int>b[5];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),ans;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[x]++;
		b[x].push_back(i);
	}
	print(ans=min(min(a[1],a[2]),a[3]));
	for (int i=0;i<ans;i++)
	{
		print(b[1][i],' ');
		print(b[2][i],' ');
		print(b[3][i]);
	}
	
	return 0;
}