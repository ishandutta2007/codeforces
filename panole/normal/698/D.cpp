#include<bits/stdc++.h>
using namespace std;

struct P
{
	int x,y;
	void in() {scanf("%d%d",&x,&y);}
	long long len() {return 1ll*x*x+1ll*y*y;}
	P operator -(P b) {return (P){x-b.x,y-b.y};}
	long long operator ^(P b) {return 1ll*x*b.y-1ll*y*b.x;}
}a[10],b[1010];

int n,k,bel[10][1010],nw,cnt,q[10],d[10],l,r,p[10],po[1010],pn;
vector<int> v[10][1010];
bool mat[10][10],bo[10];

bool cmp(int x,int y) {return (b[x]-a[nw]).len()<(b[y]-a[nw]).len();}
bool check(P a,P b,P c) {return ((b-a)^(b-c))==0&&(b.x>a.x)==(c.x>a.x)&&(b.y>a.y)==(c.y>a.y);}

bool check()
{
	for (int i=1; i<=pn; i++) d[i]=0;
	for (int i=1; i<=pn; i++)
		for (int j=1; j<=pn; j++) 
			if (mat[i][j]) d[j]++;
	l=1,r=0;
	for (int i=1; i<=pn; i++) if (!d[i]) q[++r]=i;
	while (l<=r)
	{
		int x=q[l++];
		for (int i=1; i<=pn; i++)
			if (mat[x][i]) {if (!(--d[i])) q[++r]=i;}
	}
	return r==pn;
}

bool dfs(int x)
{
	if (x==pn+1) return check();
	vector<int> V; int Pn=pn;
	for (int i=1; i<=k; i++) if (!bo[i])
	{
		V.clear();
		int nw=bel[i][p[x]];
		for (int j=0,sz=v[i][nw].size(); j<sz; j++)
		{
			if (v[i][nw][j]==p[x]) break;
			if (!po[v[i][nw][j]]) po[v[i][nw][j]]=(++pn),p[pn]=v[i][nw][j];
			mat[x][po[v[i][nw][j]]]=1,V.push_back(p[pn]);
			if (pn>k) break;
		}
		if (pn<=k)
		{
			bo[i]=1;
			if (dfs(x+1)) return 1;
			bo[i]=0;
		}
		for (int j=0,sz=V.size(); j<sz; j++)
		{
			 mat[x][po[V[j]]]=0;
			 if (po[V[j]]>Pn) po[V[j]]=0,pn--;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&k,&n),cnt=0;
	for (int i=1; i<=k; i++) a[i].in();
	for (int i=1; i<=n; i++) b[i].in();
	for (int i=1; i<=k; i++)
	{
		nw=i;
		for (int j=1; j<=n; j++) if (!bel[i][j])
		{
			bel[i][j]=j,v[i][j].push_back(j);
			for (int l=j+1; l<=n; l++) if (check(a[i],b[j],b[l])) bel[i][l]=j,v[i][j].push_back(l);
			sort(v[i][j].begin(),v[i][j].end(),cmp);
		}
	}
	for (int i=1; i<=n; i++) 
	{
		memset(p,0,sizeof(p));
		memset(po,0,sizeof(po));
		memset(bo,0,sizeof(bo));
		memset(mat,0,sizeof(mat));
		p[pn=1]=i,po[i]=1,cnt+=dfs(1);
	}
	return printf("%d\n",cnt),0;
}