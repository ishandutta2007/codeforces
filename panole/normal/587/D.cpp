#include<bits/stdc++.h>
using namespace std;

int n,m,x,ansn,e[50010][3],ans[50010],l,r,mid,an;
vector<pair<int,int> >v[50010]; 

namespace sat
{
	bool bo[500010];
	int n,hd[500010],cnt,bel[500010],dfn[500010],low[500010],sta[500010],tp,Hd[500010],d[500010],q[500010],l,r,x,col[500010];
	struct node{int to,next;}e[5000010],E[5000010];
	vector<int> v[500010];
	void init(int N)
	{
		n=N,cnt=tp=0;
		for (int i=1; i<=n; i++) hd[i]=dfn[i]=low[i]=Hd[i]=d[i]=0,bo[i]=0,col[i]=-1,v[i].clear();
	}
	int inv(int x) {return (x&1)?(x+1):(x-1);}
	void addedge(int x,int y) {e[++cnt]=(node){y,hd[x]},hd[x]=cnt;}
	void Addedge(int x,int y) {E[++cnt]=(node){y,Hd[x]},Hd[x]=cnt;}
	void tarjan(int x)
	{
		sta[++tp]=x,bo[x]=1,dfn[x]=low[x]=(++cnt);
		for (int i=hd[x]; i; i=e[i].next)
			if (!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
			else if (bo[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
		if (dfn[x]==low[x])
		{
			bel[x]=x,bo[x]=0;
			while (sta[tp]!=x) bel[sta[tp]]=x,bo[sta[tp]]=0,tp--;
			tp--;
		}
	}
	bool solve()
	{
		cnt=0;
		for (int i=1; i<=n; i++) if (!dfn[i]) tarjan(i);
		cnt=0;
		for (int i=1; i<=n; i++)
		{
			if (i<=2*m) v[bel[i]].push_back(i);
			for (int j=hd[i]; j; j=e[j].next)
				if (bel[e[j].to]!=bel[i]) Addedge(bel[e[j].to],bel[i]),d[bel[i]]++;
		}
		l=1,r=0;
		for (int i=1; i<=n; i++)
			if (bel[i]==i&&d[i]==0) q[++r]=i;
		while (l<=r)
		{
			x=q[l++];
			if (!col[x])
			{
				for (int i=Hd[x]; i; i=E[i].next)
				{
					if (col[E[i].to]==1) return 0;
					col[E[i].to]=0;
				}
			} else
			{
				col[x]=1;
				for (int i=0,sz=v[x].size(); i<sz; i++)
				{
					if (col[bel[inv(v[x][i])]]==1) return 0;
					col[bel[inv(v[x][i])]]=0;
				}
			}
			for (int i=Hd[x]; i; i=E[i].next)
			{
				d[E[i].to]--;
				if (!d[E[i].to]) q[++r]=E[i].to;
			}
		}
		for (int i=1; i<=2*m; i++) if (col[bel[inv(i)]]==col[bel[i]]) return 0;
		return 1;
	}
}

bool check(int lim)
{
	sat::init(6*m);
	int cnt=2*m;
	for (int i=1; i<=m; i++) if (e[i][2]>lim) sat::addedge(2*i-1,2*i);
	for (int i=1; i<=n; i++)
	{
		for (int j=0,sz=v[i].size(); j<sz-1; j++)
			if (v[i][j].first==v[i][j+1].first) 
				sat::addedge(2*v[i][j].second,2*v[i][j+1].second-1),
				sat::addedge(2*v[i][j+1].second,2*v[i][j].second-1);
		for (int j=0,sz=v[i].size(); j<sz; j++)
		{
			cnt++;
			sat::addedge(cnt,v[i][j].second*2);
			if (j!=0) 
			{
				sat::addedge(cnt,cnt-1);
				sat::addedge(v[i][j].second*2-1,cnt-1);
			}
		}
		for (int sz=v[i].size(),j=sz-1; j>=0; j--)
		{
			cnt++;
			sat::addedge(cnt,v[i][j].second*2);
			if (j!=sz-1)
			{
				sat::addedge(cnt,cnt-1);
				sat::addedge(v[i][j].second*2-1,cnt-1);
			}
		}
	}
	return sat::solve();
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d%d%d",&e[i][0],&e[i][1],&x,&e[i][2]);
		v[e[i][0]].push_back(make_pair(x,i));
		v[e[i][1]].push_back(make_pair(x,i));
	}
	for (int i=1; i<=n; i++) 
	{
		sort(v[i].begin(),v[i].end());
		for (int j=0,sz=v[i].size(); j<sz-2; j++)
			if (v[i][j].first==v[i][j+1].first&&v[i][j].first==v[i][j+2].first) return puts("No"),0;
	}
	l=0,r=1000000000,an=-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) an=mid,r=mid-1; else l=mid+1;
	}
	if (an==-1) return puts("No"),0;
	puts("Yes"),check(an),ansn=0;
	for (int i=1; i<=m; i++)
		if (sat::col[sat::bel[2*i-1]]==1) ans[++ansn]=i;
	printf("%d %d\n",an,ansn);
	for (int i=1; i<=ansn; i++) printf("%d ",ans[i]);
	return puts(""),0;
}