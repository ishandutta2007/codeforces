#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
set<int>t[N];
int tot[N],fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++) t[read()].insert(i);
	for (int i=1;i<=m;i++)
	{
		auto j=t[i].begin(),k=j;
		k++;
		for (;k!=t[i].end();j++,k++) tot[i]+=*j+1==*k;
		ans+=tot[i];
	}
	for (int i=1;i<=m;i++) fa[i]=i;
	for (int i=1;i<m;i++)
	{
		print(n-1-ans);
		int x=find(read()),y=find(read());
		if (t[x].size()<t[y].size()) swap(x,y);
		fa[find(y)]=find(x);
		ans-=tot[x]+tot[y];
		for (int j:t[y])
		{
			auto tmp=t[x].lower_bound(j);
			if (tmp!=t[x].end()&&*tmp-1==j) tot[x]++;
			if (tmp!=t[x].begin())
			{
				tmp--;
				if (*tmp+1==j) tot[x]++;
			}
			t[x].insert(j);
		}
		ans+=tot[x];
//		for (int i:t[x]) print(i,',');puts("");
	}
	print(n-1-ans);
	
	return 0;
}