#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int S=500;
vector<int> v[300001];
vector<pair<int,int> > V[300001];
int T,n,q,k,x,po[300001],p[300001];

void solve()
{
	scanf("%d%d",&n,&q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d",&k); v[i].clear();
		for (int j=0; j<k; j++) scanf("%d",&x),v[i].push_back(x);
	}
	for (int i=1; i<=q; i++)
		if (v[i].size()>=S)
		{
			int k=v[i].size();
			for (int j=0; j<k; j++) po[v[i][j]]=j+1;
			for (int j=1,siz,l; j<=q; j++)
				if (i!=j)
				{
					int mi=(po[v[j][0]]?po[v[j][0]]:(1e9));
					for (l=1,siz=v[j].size(); l<siz; l++)
						if (po[v[j][l]])
						{
							if (mi<po[v[j][l]]&&!po[v[j][l-1]]||po[v[j][l-1]]&&po[v[j][l-1]]<po[v[j][l]]-1) 
							{
								for (int j=0; j<k; j++) po[v[i][j]]=0;
								puts("Human"); return;
							}
							mi=(mi>po[v[j][l]]?po[v[j][l]]:mi);
						}
				}
			for (int j=0; j<k; j++) po[v[i][j]]=0;
		}
	for (int i=1; i<=n; i++) V[i].clear();
	for (int i=1,siz,j; i<=q; i++)
		if (v[i].size()<S)
			for (j=0,siz=v[i].size(); j<siz; j++) V[v[i][j]].push_back(make_pair(i,j));
	for (int i=1,siz,j; i<=n; i++)
	{
		for (j=0,siz=V[i].size(); j<siz; j++)
		{
			int p1=V[i][j].first,p2=V[i][j].second,s=v[p1].size();
			for (int k=p2+1,K; k<s; k++)
			{
				K=v[p1][k];
				if (!po[K]) po[K]=p1,p[K]=k;
				else if (v[po[K]][p[K]-1]!=v[p1][k-1]) 
				{
					for (j=0,siz=V[i].size(); j<siz; j++)
					{
						int p1=V[i][j].first,p2=V[i][j].second,s=v[p1].size();
						for (int k=p2+1; k<s; k++) po[v[p1][k]]=0;
					}
					puts("Human"); return;
				}
			}
		}
		for (j=0,siz=V[i].size(); j<siz; j++)
		{
			int p1=V[i][j].first,p2=V[i][j].second,s=v[p1].size();
			for (int k=p2+1; k<s; k++) po[v[p1][k]]=0;
		}
	}
	puts("Robot");
}

int main()
{
	scanf("%d",&T);
	memset(po,0,sizeof(po));
	while (T--) solve();
	return 0;
}