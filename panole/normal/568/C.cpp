#include<bits/stdc++.h>
using namespace std;

bool bo[210][2][210][2],Bo[210][2];
int n,m,col[210],po,p1[200010],t1[200010],p2[200010],t2[200010],len,M;
char s[30],S[210],ans[210],c[5];

namespace sat
{
	bool bo[410];
	int n,hd[410],cnt,bel[600010],dfn[410],low[410],sta[410],tp,Hd[410],d[410],q[410],l,r,x,col[410],lim;
	struct node{int to,next;}e[600010],E[600010];
	vector<int> v[410];
	void init(int N,int Lim)
	{
		n=N,cnt=tp=0,lim=Lim;
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
			if (i<=lim) v[bel[i]].push_back(i);
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
		for (int i=1; i<=lim; i++) if (col[bel[inv(i)]]==col[bel[i]]) return 0;
		return 1;
	}
}

bool check()
{
	sat::init(2*n,2*n);
	for (int i=1; i<=n; i++)
		if (col[i]==0) {if (!Bo[i][0]) return 0; sat::addedge(i*2,i*2-1);} else
		if (col[i]==1) {if (!Bo[i][1]) return 0; sat::addedge(i*2-1,i*2);}
	for (int i=1; i<=m; i++)
		sat::addedge(p1[i]*2-(t1[i]==0),p2[i]*2-(t2[i]==0)),
		sat::addedge(p2[i]*2-t2[i],p1[i]*2-t1[i]);
	return sat::solve();
}

int main()
{
	scanf("%s",s),len=strlen(s);
	scanf("%d%d",&n,&m),M=0;
	for (int i=1; i<=m; i++)
	{
		M++;
		scanf("%d%s",&p1[M],c),t1[M]=(c[0]=='C');
		scanf("%d%s",&p2[M],c),t2[M]=(c[0]=='C');
		if (!bo[p1[M]][t1[M]][p2[M]][t2[M]])
			bo[p1[M]][t1[M]][p2[M]][t2[M]]=1,bo[p2[M]][t2[M]^1][p1[M]][t1[M]^1]=1; 
		else M--;
	}
	memset(Bo,1,sizeof(Bo));
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			for (int k=1; k<=n; k++)
				if (bo[i][j][k][0]&&bo[i][j][k][1]) {Bo[i][j]=0; break;}
	m=M,scanf("%s",S+1),po=-1;
	bool boo=1;
	for (int i=1; i<len; i++) if (s[i]!=s[i-1]) {boo=0; break;}
	if (boo)
	{
		for (int i=1; i<=n; i++) col[i]=(s[0]=='C');
		if (check()) puts(S+1); else puts("-1");
		return 0;
	}
	for (int i=1; i<=n; i++) col[i]=-1;
	if (!check()) return puts("-1"),0;
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=i; j++) col[j]=(s[S[j]-'a']=='C');
		if (i==n) 
		{
			if (check()) return puts(S+1),0;
			break;
		}
		if (S[i+1]-'a'==len-1) continue;
		bool bo0=0,bo1=0;
		for (int nw=S[i+1]-'a'+1; nw<len; nw++) 
			if (s[nw]=='V') bo0=1; else bo1=1;
		for (int j=i+2; j<=n; j++) col[j]=-1;
		if (bo0)
		{
			col[i+1]=0;
			if (check()) {po=i; continue;}
		}
		if (bo1)
		{
			col[i+1]=1;
			if (check()) {po=i; continue;}
		}
	}
	if (po==-1) return puts("-1"),0;
	for (int i=1; i<=po; i++) col[i]=(s[S[i]-'a']=='C'),ans[i-1]=S[i];
	for (int i=po+1; i<=n; i++) col[i]=-1;
	for (int i=po+1; i<=n; i++)
	{
		int p0=-1,p1=-1,mi=114514;
		for (int nw=(i==po+1?S[i]-'a'+1:0); nw<len; nw++) 
		{
			if (p0==-1&&s[nw]=='V') p0=nw;
			if (p1==-1&&s[nw]=='C') p1=nw;
		}
		if (p0!=-1) 
		{
			col[i]=0;
			if (check()) mi=min(mi,p0);
		}
		if (p1!=-1)
		{
			col[i]=1;
			if (check()) mi=min(mi,p1);
		}
		ans[i-1]=mi+'a',col[i]=(mi==p1);
	}
	puts(ans);
	return 0;
}