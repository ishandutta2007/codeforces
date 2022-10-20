#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>a[2];
int x[N],y[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	for (int i=1;i<=n;i++)
		x[i]=read()+1e6,
		y[i]=read()+1e6;
	while (1)
	{
		a[0].clear(),a[1].clear();
		for (int i=1;i<=n;i++) a[(x[i]^y[i])&1].push_back(i);
		if (!a[0].empty()&&!a[1].empty())
		{
			print(a[0].size());
			for (int i:a[0]) print(i,' ');
			break;
		}
		a[0].clear(),a[1].clear();
		for (int i=1;i<=n;i++) a[x[i]&1].push_back(i);
		if (!a[0].empty()&&!a[1].empty())
		{
			print(a[0].size());
			for (int i:a[0]) print(i,' ');
			break;
		}
		for (int i=1;i<=n;i++) x[i]/=2,y[i]/=2;
	}
	
	return 0;
}