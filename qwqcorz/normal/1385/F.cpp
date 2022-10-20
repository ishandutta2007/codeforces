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
set<int>e[N],e2[N];
int siz[N],q[N*20];
bool vis[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read(),k=read(),h=1,t=0,ans=0;
		for (int i=1;i<=n;i++)
			siz[i]=0,
			e[i].clear(),
			e2[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].insert(v);
			e[v].insert(u);
		}
		if (k==1)
		{
			print(n-1);
			continue;
		}
		for (int i=1;i<=n;i++)
		for (int j:e[i])
		if ((int)e[j].size()==1) siz[i]++;
							else e2[i].insert(j);
		for (int i=1;i<=n;i++) if (siz[i]>=k) vis[q[++t]=i]=1;
		while (h<=t)
		{
			int now=q[h++],tot=siz[now]-siz[now]%k;
			ans+=siz[now]/k;
			siz[now]-=tot;
			vis[now]=0;
			if (siz[now]==0&&(int)e2[now].size()==1)
			{
				int to=*e2[now].begin();
				e2[to].erase(now);
				siz[to]++;
				if (siz[to]>=k&&!vis[to]) q[++t]=to;
			} 
		}
		print(ans);
	}
	
	return 0;
}