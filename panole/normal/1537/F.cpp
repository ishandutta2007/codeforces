#include<bits/stdc++.h>
using namespace std;

int T,n,m,x,y,col[200010];
long long val[200010];
vector<int> v[200010];

bool check(int x)
{
	for (int i=0,sz=v[x].size(); i<sz; i++)
		if (col[v[x][i]]==-1) 
		{
			col[v[x][i]]=col[x]^1;
			if (!check(v[x][i])) return 0;
		} else if (col[v[x][i]]==col[x]) return 0;
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++) scanf("%lld",&val[i]),v[i].clear();
		for (int i=1; i<=n; i++) scanf("%d",&x),val[i]=x-val[i];
		while (m--) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		for (int i=1; i<=n; i++) col[i]=-1;
		if (check(col[1]=1)) 
		{
			long long s[2]={0ll,0ll};
			for (int i=1; i<=n; i++) s[col[i]]+=val[i];
			puts(s[0]==s[1]?"YES":"NO");
		} else 
		{
			long long s=0;
			for (int i=1; i<=n; i++) s+=val[i];
			puts((s&1)?"NO":"YES");
		}
	}
	return 0;
}