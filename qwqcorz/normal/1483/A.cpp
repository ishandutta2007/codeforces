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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>f[N];
bool used[N];
int tot[N],siz[N],cnt[N],out[N];
void clear(int n,int m)
{
	for (int i=1;i<=n;i++) tot[i]=cnt[i]=0;
	for (int i=1;i<=m;i++) used[i]=0;
	for (int i=1;i<=m;i++) f[i].clear();
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),mid=(m+1)/2;
		for (int i=1;i<=m;i++)
		{
			siz[i]=read();
			for (int j=0;j<siz[i];j++) f[i].push_back(read());
			for (int j=0;j<siz[i];j++) cnt[f[i][j]]++;
		}
		bool flag=0;
		for (int i=1;i<=m;i++)
		if (siz[i]==1)
		{
			if ((++tot[f[i][0]])>mid)
			{
				flag=1;
				puts("NO");
				clear(n,m);
				break;
			}
			used[i]=1;
			out[i]=f[i][0];
		}
		if (flag) continue;
		puts("YES");
		int Max=1;
		for (int i=2;i<=n;i++) if (cnt[i]>cnt[Max]) Max=i;
		for (int i=1;i<=m;i++)
		if (!used[i])
		{
			if (tot[Max]==mid) break;
			for (int j=0;j<siz[i];j++)
			if (f[i][j]==Max)
			{
				tot[Max]++;
				used[i]=1;
				out[i]=f[i][j];
				break;
			}
		}
		for (int i=1;i<=m;i++)
		if (used[i]) print(out[i],' ');
				else print(f[i][0]==Max?f[i][1]:f[i][0],' ');
		puts("");
		clear(n,m);
	}

	return 0;
}