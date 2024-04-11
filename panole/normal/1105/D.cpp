#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
vector<pair<int,int> > v[10],t;
int n,m,p,s[10],a[1011][1101],ans[10],tn,d[4][2];
char str[1101];

bool bfs(int x)
{
	t.clear(),tn=v[x].size();
	for (int i=0; i<tn; i++) t.pb(v[x][i]);
	v[x].clear();
	for (int i=0; i<tn; i++)
	{
		int X=t[i].first,Y=t[i].second;
		for (int j=0; j<4; j++)
			if (a[X+d[j][0]][Y+d[j][1]]==0) 
				a[X+d[j][0]][Y+d[j][1]]=x,v[x].pb(mp(X+d[j][0],Y+d[j][1]));
	}
	if (!v[x].size()) return 0;
	return 1;
}

int main()
{
	for (int i=0; i<=1001; i++)
		for (int j=0; j<=1001; j++) a[i][j]=-1;
	d[0][0]=d[1][0]=d[2][1]=d[3][1]=0;
	d[0][1]=d[2][0]=1; d[1][1]=d[3][0]=-1;
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1; i<=p; i++) scanf("%d",&s[i]);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",str+1);
		for (int j=1; j<=m; j++)
			if (str[j]=='#') a[i][j]=-1; else
			if (str[j]=='.') a[i][j]=0; else
			a[i][j]=str[j]-'0',v[a[i][j]].pb(mp(i,j));
	}
	while (1)
	{
		bool bo=0;
		for (int i=1; i<=p; i++)
			for (int j=1; j<=s[i]; j++) 
				if (!bfs(i)) break; else bo=1;
		if (!bo) break;
	}
	memset(ans,0,sizeof(ans));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i][j]>0) ans[a[i][j]]++;
	for (int i=1; i<=p; i++) printf("%d ",ans[i]); puts("");
	return 0;
}