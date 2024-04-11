#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n,m;

int t[N],fa[N],sz[N],ans,to[N];

vector<int>v[N];

int find(int x)
{
	return x==fa[x]?x:find(fa[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]),ans+=(t[i]!=t[i-1]);
	ans--;
	for(int i=1;i<=n;i++)
	{
		if(!to[t[i]])
			to[t[i]]=i;
		v[to[t[i]]].push_back(i);
		fa[i]=to[t[i]];
		sz[fa[i]]++;
	}
	printf("%d\n",ans); 
	for(int i=1;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(v[to[x]][0]),fy=find(v[to[y]][0]);
		if(sz[fx]<sz[fy])
			swap(fx,fy);
		sz[fx]+=sz[fy];
		for(int j=0;j<v[fy].size();j++)
			ans-=(find(v[fy][j]-1)==fx)+(find(v[fy][j]+1)==fx),v[fx].push_back(v[fy][j]);
		fa[fy]=fx;
		printf("%d\n",ans);
	}
}