#include<bits/stdc++.h>
using namespace std;

const int inf=2000000000;
typedef set<pair<int,int> >::iterator IT;
int n,x,y,d[100010],v,rt,tn[1010],t[1010][1010],fa[100010],ans[1010][1010],nw[1010][1010];
int Ans[1000010][3],Ansn;
set<pair<int,int> > s[100010];

void addedge(int x,int y,int val)
{
	s[x].insert(make_pair(y,val));
	s[y].insert(make_pair(x,val));
}

void add(int x,int y)
{
	if (!fa[x]) return;
	IT it=s[x].lower_bound(make_pair(fa[x],-inf));
	int nw=(*it).second;
	s[x].erase(it),s[x].insert(make_pair(fa[x],nw-y));
	s[fa[x]].erase(make_pair(x,nw)),s[fa[x]].insert(make_pair(x,nw-y));
	add(fa[x],y);
}

void dfs(int x)
{
	if (x!=rt&&d[x]==1) return;
	tn[x]=0;
	for (IT it=s[x].begin(); it!=s[x].end(); it++) t[x][++tn[x]]=(*it).first;
	for (int i=1; i<=tn[x]; i++) if (t[x][i]!=fa[x]) fa[t[x][i]]=x,dfs(t[x][i]);
	tn[x]=0;
	int NW=0;
	for (IT it=s[x].begin(); it!=s[x].end(); it++) 
		if ((*it).first!=fa[x])t[x][++tn[x]]=(*it).first,nw[x][tn[x]]=(*it).second;
		else NW=(*it).second;
	if (x==rt) ans[x][t[x][1]]+=nw[x][1]; else
	{
		for (int i=3; i<=tn[x]; i++)
		{
			ans[t[x][i]][rt]+=nw[x][i];
			add(x,nw[x][i]),NW-=nw[x][i];
		}
		int a=nw[x][1],b=nw[x][2],c=NW;
		ans[t[x][1]][rt]+=c-b+(a-(c-b))/2,add(x,c-b+(a-(c-b))/2);
		ans[t[x][2]][t[x][1]]+=(a-(c-b))/2;
		s[fa[x]].erase(make_pair(x,NW-(c-b+(a-(c-b))/2)));
		s[fa[x]].insert(make_pair(t[x][2],NW-(c-b+(a-(c-b))/2)));
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++) scanf("%d%d%d",&x,&y,&v),addedge(x,y,v),d[x]++,d[y]++;
	for (int i=1; i<=n; i++) if (d[i]==2) 
	{
		x=(*s[i].begin()).first,v=(*s[i].begin()).second;
		if (v!=(*(++s[i].begin())).second) return puts("NO"),0;
		y=(*(++s[i].begin())).first;
		s[x].erase(make_pair(i,v)),s[y].erase(make_pair(i,v));
		addedge(x,y,v);
	}
	puts("YES");
	for (int i=1; i<=n; i++) if (d[i]==1) {rt=i; break;}
	fa[rt]=0,dfs(rt);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++) if (ans[i][j]+ans[j][i]!=0)
			Ans[++Ansn][0]=i,Ans[Ansn][1]=j,Ans[Ansn][2]=ans[i][j]+ans[j][i];
	printf("%d\n",Ansn);
	for (int i=1; i<=Ansn; i++) printf("%d %d %d\n",Ans[i][0],Ans[i][1],Ans[i][2]);
	return 0;
}