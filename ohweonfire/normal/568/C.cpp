#include<bits/stdc++.h>
using namespace std;
char s[30],t[405];
int sl,n,m,rev[405],qx[160013],qy[160013],minc[30],minv[30];
struct graph
{
	vector<int> g[405];
	int low[405],dfu[405],mark[405];
	int st[405],top,cmp[405];
	bool use[405];
	void add(int x,int y)
	{
		g[x].push_back(y);
		g[rev[y]].push_back(rev[x]);
	}
	void clear()
	{
		for(int i=0;i<405;i++)g[i].clear();
	}
	int k,scc;
	void dfs(int x)
	{
		low[x]=dfu[x]=++k;
		st[top++]=x;
		mark[x]=true;
		use[x]=true;
		for(int i=0;i<g[x].size();i++)
		{
			if(!use[g[x][i]])
			{
				dfs(g[x][i]);
				low[x]=min(low[x],low[g[x][i]]);
			}
			else if(dfu[g[x][i]]<dfu[x]&&mark[g[x][i]])
				low[x]=min(low[x],dfu[g[x][i]]);
		}
		if(low[x]==dfu[x])
		{
			scc++;
			do
			{
				cmp[st[--top]]=scc;
				mark[st[top]]=false;
			}while(st[top]!=x);
		}
	}
	bool SAT()
	{
		memset(use,0,sizeof(use));
		memset(mark,0,sizeof(mark));
		for(int i=1; i<=(n<<1); i++)if(!use[i])dfs(i);
		for(int i=1; i<=n; i++)if(cmp[i]==cmp[rev[i]])return false;
		return true;
	}
} g;
int main()
{
	scanf("%s%d%d",s+1,&n,&m);
	sl=strlen(s+1);
	for(int i=1; i<=n; i++)
	{
		rev[i]=i+n;
		rev[i+n]=i;
	}
	minc[sl+1]=minv[sl+1]=1613;
	for(int i=sl; i; i--)
	{
		minc[i]=minc[i+1];
		minv[i]=minv[i+1];
		if(s[i]=='V')minv[i]=i;
		else minc[i]=i;
	}
	for(int i=1; i<=m; i++)
	{
		char tmp[5];
		scanf("%d%s",&qx[i],tmp);
		qx[i]+=(tmp[0]=='C')*n;
		scanf("%d%s",&qy[i],tmp);
		qy[i]+=(tmp[0]=='C')*n;
	}
	scanf("%s",t+1);
	for(int _=n; _>=0; _--)
	{
		g.clear();
		for(int i=1; i<=m; i++)g.add(qx[i],qy[i]);
		for(int i=1; i<=_; i++)
		{
			if(s[t[i]-'a'+1]=='V')g.add(rev[i],i);
			else g.add(i,rev[i]);
		}
		if(_!=n&&minv[t[_+1]-'a'+2]==1613)g.add(_+1,rev[_+1]);
		if(_!=n&&minc[t[_+1]-'a'+2]==1613)g.add(rev[_+1],_+1);
		for(int i=_+2; i<=n; i++)
		{
			if(minv[1]==1613)g.add(i,rev[i]);
			if(minc[1]==1613)g.add(rev[i],i);
		}
		if(g.SAT())
		{
			for(int i=_+1,vv,cc; i<=n; i++)
			{
				if(i==_+1)
				{
					vv=minv[t[_+1]-'a'+2];
					cc=minc[t[_+1]-'a'+2];
				}
				else
				{
					vv=minv[1];
					cc=minc[1];
				}
				if(vv<cc)
				{
					g.clear();
					for(int j=1; j<=m; j++)g.add(qx[j],qy[j]);
					for(int j=1; j<i; j++)
					{
						if(s[t[j]-'a'+1]=='V')g.add(rev[j],j);
						else g.add(j,rev[j]);
					}
					for(int j=i+1; j<=n; j++)
					{
						if(minv[1]==1613)g.add(i,rev[i]);
						if(minc[1]==1613)g.add(rev[i],i);
					}
					g.add(rev[i],i);
					if(g.SAT())t[i]=(vv+'a'-1);
					else t[i]=(cc+'a'-1);
				}
				else
				{
					g.clear();
					for(int j=1; j<=m; j++)g.add(qx[j],qy[j]);
					for(int j=1; j<i; j++)
					{
						if(s[t[j]-'a'+1]=='V')g.add(rev[j],j);
						else g.add(j,rev[j]);
					}
					for(int j=i+1; j<=n; j++)
					{
						if(minv[1]==1613)g.add(i,rev[i]);
						if(minc[1]==1613)g.add(rev[i],i);
					}
					g.add(i,rev[i]);
					if(g.SAT())t[i]=(cc+'a'-1);
					else t[i]=(vv+'a'-1);
				}
			}
			printf("%s\n",t+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}