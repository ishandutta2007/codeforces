#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,x,y,b[N],a[N],vis[N],to[N];

vector<int>v[N];

bool chk(int w)
{
	int now=x;
	for(int i=1;i<=n+1;i++)
		if(vis[i]>w)	
		{
			now-=vis[i]-w;
			if(now<0)
				return 0;
		}
	return 1;
}

void solve(int w)
{
	int now=x;
	for(int i=1;i<=n+1;i++)
		if(vis[i]>w)
			for(int j=0;j<vis[i]-w;j++)
				a[v[i][j]]=b[v[i][j]],now--;
	for(int i=1;i<=n;i++)
		if(a[i]==-1&&now)
			a[i]=b[i],now--;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n+1;i++)
			vis[i]=0,v[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),vis[b[i]]++,v[b[i]].push_back(i),a[i]=-1;
		int pos=-1;
		for(int i=1;i<=n+1;i++)
			if(!vis[i])
				pos=i;
		y-=x;
		int l=-1,r=n;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(chk(mid))
				r=mid;
			else
				l=mid;
		}
		solve(r);
		for(int i=0;i<=n+1;i++)
			vis[i]=0;
		int mxv=0;
		for(int i=1;i<=n;i++)
			if(a[i]==-1)
			{
				vis[b[i]]++;
				if(vis[b[i]]==r)
					mxv=b[i];
			}
		int mx=r;
		if(mx*2<=n-x)
		{
			vector<pii>g;
			g.clear();
			int nowy=y;
			for(int i=1;i<=n;i++)
				if(a[i]==-1)
					g.push_back(mp(b[i],i));
			sort(g.begin(),g.end());
			for(int i=0;i<g.size();i++)
			{
				if(nowy)
				{
					nowy--;
					a[g[i].sd]=(i+mx>=g.size()?g[i+mx-g.size()].fs:g[i+mx].fs);
				}
				else
					a[g[i].sd]=pos;
			}
			puts("Yes");
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			puts("");
		}
		else
		{
			if(y>(n-x-mx)*2)
				puts("No");
			else
			{
				vector<pii>g;
				g.clear();
				int nowy=y;
				for(int i=1;i<=n;i++)
					if(a[i]==-1&&b[i]!=mxv)
						g.push_back(mp(b[i],i));
				sort(g.begin(),g.end());
				for(int i=0;i<g.size();i++)
				{
					if(nowy&&mx)
					{
						nowy--;
						mx--;
						a[g[i].sd]=mxv;
					}
					else
						a[g[i].sd]=pos;
				}
				int j=0;
				for(int i=1;i<=n;i++)
					if(a[i]==-1)
					{
						if(nowy)
							nowy--,a[i]=g[j].fs,j++;
						else
							a[i]=pos;
					}
				puts("Yes");
				for(int i=1;i<=n;i++)
					printf("%d ",a[i]);
				puts("");
			}
		}
	}
}