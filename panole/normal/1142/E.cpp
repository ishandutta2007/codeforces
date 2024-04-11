#include<bits/stdc++.h>
using namespace std;

bool bo[100001];
vector<int> v[100001];
int siz[100001],po,n,m,x,y,hd[100001],dfn[100001],low[100001],sta[100001],tp,cnt,nw[100001],bel[100001],d[100001],q[100001],l,r;
struct node{int fro,to,next;}e[100001];

void tarjan(int x)
{
	sta[++tp]=x,dfn[x]=low[x]=(++cnt),bo[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if (bo[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if (low[x]==dfn[x])
	{
		v[x].clear();
		while (sta[tp]!=x) bel[sta[tp]]=x,bo[sta[tp]]=0,v[x].push_back(sta[tp]),tp--;
		bel[x]=x,bo[x]=0,v[x].push_back(x),tp--;
	}
}

int ask(int x,int y)
{
	printf("? %d %d\n",x,y),fflush(stdout);
	scanf("%d",&x); return x;
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=m; i++)
		scanf("%d%d",&x,&y),e[i]=(node){x,y,hd[x]},hd[x]=i;
	memset(bo,0,sizeof(bo));
	memset(dfn,0,sizeof(dfn)),cnt=0;
	for (int i=1; i<=n; i++) if (!dfn[i]) tarjan(i);
	memset(d,0,sizeof(d));
	for (int i=1; i<=m; i++) 
		if (bel[e[i].fro]!=bel[e[i].to]) d[bel[e[i].to]]++;
	l=2,r=0;
	for (int i=1; i<=n; i++) if (bel[i]==i&&!d[i]) q[++r]=i;
	for (int i=1; i<=n; i++) if (bel[i]==i) nw[i]=0,siz[i]=v[i].size();
	po=q[1];
	while (l<=r)
	{
		int nw1=nw[po],nw2=0;
		while (nw1<siz[po]&&nw2<siz[q[l]])
		{
			while (nw2<siz[q[l]]&&ask(v[po][nw1],v[q[l]][nw2])) nw2++;
			if (nw2==siz[q[l]]) break; nw1++;
			while (nw1<siz[po]&&ask(v[q[l]][nw2],v[po][nw1])) nw1++;
		}
		if (nw1==siz[po])
		{
			nw[q[l]]=nw2;
			for (int j=0,x; j<siz[po]; j++)
				for (int i=hd[x=v[po][j]]; i; i=e[i].next)
					if (bel[e[i].to]!=po)
					{
						d[bel[e[i].to]]--;
						if (!d[bel[e[i].to]]) q[++r]=bel[e[i].to];
					}
			po=q[l];
		} else
		{
			nw[po]=max(nw[po],nw1);
			for (int j=0,x; j<siz[q[l]]; j++)
				for (int i=hd[x=v[q[l]][j]]; i; i=e[i].next)
					if (bel[e[i].to]!=q[l])
					{
						d[bel[e[i].to]]--;
						if (!d[bel[e[i].to]]) q[++r]=bel[e[i].to];
					}
		}
		l++;
	}
	printf("! %d\n",v[po][nw[po]]),fflush(stdout);
	return 0;
}