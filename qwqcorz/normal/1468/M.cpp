#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int B=40;

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
int b[N],tmp[N],cnt;
vector<int>a[N];
unordered_map<int,int>pa[N];
pair<int,int>find(int n,int sum)
{
	for (int i=1;i<=n;i++)
	if ((int)a[i].size()>B)
	{
		for (int k:a[i]) b[k]=1;
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			int cnt=0;
			for (int k:a[j]) cnt+=b[k];
			if (cnt>=2) return mk(i,j);
		}
		for (int k:a[i]) b[k]=0;
	}
	else
	{
		for (int j=0;j<(int)a[i].size();j++)
		for (int k=j+1;k<(int)a[i].size();k++)
		{
			int x=min(a[i][j],a[i][k]),y=max(a[i][j],a[i][k]);
			if (pa[x][y]) return mk(pa[x][y],i);
			pa[x][y]=i;
		}
	}
	return mk(0,0);
}
void clear(int n)
{
	for (int i=1;i<=cnt;i++) b[i]=0;
	for (int i=1;i<=cnt;i++) pa[i].clear();
	for (int i=1;i<=n;i++) a[i].clear();
	cnt=0;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read(),sum=0;
		for (int i=1;i<=n;i++)
		{
			int m=read();
			sum+=m;
			for (int j=1;j<=m;j++) a[i].push_back(tmp[++cnt]=read());
		}
		sort(tmp+1,tmp+1+cnt);
		cnt=unique(tmp+1,tmp+1+cnt)-tmp-1;
		for (int i=1;i<=n;i++)
		for (int j=0;j<(int)a[i].size();j++)
		a[i][j]=lower_bound(tmp+1,tmp+1+cnt,a[i][j])-tmp;
		pair<int,int>ans=find(n,sum);
		if (ans==mk(0,0)) puts("-1");
					 else print(ans.fi,' '),print(ans.se);
		clear(n);
	}
	
	return 0;
}