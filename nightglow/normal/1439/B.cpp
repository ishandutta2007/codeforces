#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>
#include<vector>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 200005

using namespace std;

vector<int>v[N];

int vis[N],i,j,m,n,p,k,deg[N],Q[N],x[N],y[N];

void del(int x)
{
		int i;
		for (i=0;i<(int)v[x].size();++i)
		{
			deg[v[x][i]]--;
			if (deg[v[x][i]]==k-1) Q[++Q[0]]=v[x][i];
		}
}

vector<vector<int> >Clique; 

void Insert(int x)
{
		vector<int> tmp; tmp.pb(x);
		for (int i=0;i<(int)v[x].size();++i) if (!vis[v[x][i]]) tmp.pb(v[x][i]);
//		for (int i=0;i<(int)tmp.size();++i) printf("%d ",tmp[i]);
//		puts(""); 
		Clique.pb(tmp); 
}

vector<int>IfCheck[N];

int Num[N],Sum[N],w;

int Check()
{
	for (i=1;i<=n;++i) Num[i]=0,IfCheck[i].clear();
	for (i=0;i<(int)Clique.size();++i) Sum[i]=0; 
	for (i=0;i<(int)Clique.size();++i)
		for (j=0;j<(int)Clique[i].size();++j)
			IfCheck[Clique[i][j]].pb(i);
	for (i=1;i<=n;++i)
	{
		for (j=0;j<(int)v[i].size();++j) Num[v[i][j]]=i;
		Num[i]=i;
		for (j=0;j<(int)IfCheck[i].size();++j)
		{
			int p=IfCheck[i][j];
			for (w=0;w<(int)Clique[p].size();++w)
				if (Num[Clique[p][w]]!=i) break;
			if (w==Clique[p].size()) ++Sum[p];
		}
	}
	for (i=0;i<(int)Clique.size();++i)
		if (Sum[i]==k)
		{
			puts("2");
			for (j=0;j<(int)Clique[i].size();++j) printf("%d ",Clique[i][j]);
			puts("");
			return 1; 
		}
	return 0;
}

void Main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;++i) v[i].clear(),deg[i]=vis[i]=0;
	for (i=1;i<=m;++i) scanf("%d%d",&x[i],&y[i]),v[x[i]].pb(y[i]),v[y[i]].pb(x[i]),deg[x[i]]++,deg[y[i]]++;
	for (i=1,Q[0]=0;i<=n;++i) if (deg[i]<=k-1) Q[++Q[0]]=i;
	Clique.clear();
	for (int l=1;l<=Q[0];++l)
	{
		int p=Q[l]; vis[p]=1;
		if (deg[p]<k-1)  del(p);
		else Insert(p),del(p);
	}
	if (Q[0]!=n)
	{
		printf("1 "); int cnt=0;
		for (i=1;i<=n;++i) if (!vis[i]) ++cnt;
		printf("%d\n",cnt); 
		for (i=1;i<=n;++i) if (!vis[i]) printf("%d ",i);
		puts("");
	}
	else if (!Check()) puts("-1");
}

int main()
{
	int T; scanf("%d",&T);
	for (;T--;) Main(); 
}