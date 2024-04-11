#include<bits/stdc++.h>
using namespace std;

pair<int,int> t[2][110],tx[110],ty[110];
int N,n,dfn[300010],tp[300010],fa[300010],cnt,hd[300010],Hd[600010],X,Y,siz[300010],sum[26],rnk[600010],h[600010],f[20][600010],lo[600010],po[600010],q,nw[2],x[2],y[2],tn[2],tnx,tny,ans,p[2],len[2],qaq;
struct node{int to,next;}e[600010],E[600010];
struct suf{int rk1,rk2,ord;}rk[600010],Rk[600010];
char s[600010],S[300010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

void dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	dfn[x]=(++cnt),s[cnt]=S[x]; int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (!ma) return;
	tp[maa]=tp[x],Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to);
}

int lcp(int x,int y)
{
	if (x==y) return N-max(x,y)+1;
	x=rnk[x],y=rnk[y];
	if (x>y) swap(x,y);
	int len=lo[y-x];
	return min(f[len][x],f[len][y-(1<<len)]);
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=600000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d%s",&n,S+1),cnt=0,N=(n<<1);
	for (int i=1; i<n; i++) scanf("%d%d",&X,&Y),addedge(X,Y);
	fa[1]=0,dfs(1),cnt=0,tp[1]=1,Dfs(1);
	for (int i=1; i<=n; i++) s[2*n-i+1]=s[i],sum[s[i]-'a']=1;
	for (int i=1; i<26; i++) sum[i]+=sum[i-1];
	for (int i=1; i<=2*n; i++) rk[i].rk1=sum[s[i]-'a'];
	for (int len=1; len<N; len<<=1)
	{
		for (int i=1; i<=N-len; i++) rk[i].rk2=rk[i+len].rk1,rk[i].ord=i;
		for (int i=N-len+1; i<=N; i++) rk[i].rk2=0,rk[i].ord=i;
		memset(Hd,0,(N+1)<<2),cnt=0;
		for (int i=N; i; i--) E[++cnt]=(node){i,Hd[rk[i].rk2]},Hd[rk[i].rk2]=cnt;
		cnt=0;
		for (int i=0; i<=N; i++)
			for (int j=Hd[i]; j; j=E[j].next) Rk[++cnt]=rk[E[j].to];
		memset(Hd,0,(N+1)<<2),cnt=0;
		for (int i=N; i; i--) E[++cnt]=(node){i,Hd[Rk[i].rk1]},Hd[Rk[i].rk1]=cnt;
		cnt=0;
		for (int i=0; i<=N; i++)
			for (int j=Hd[i]; j; j=E[j].next) rk[++cnt]=Rk[E[j].to];
		cnt=0;
		for (int i=1; i<=N; i++) 
		{
			if (i==1||rk[i].rk1!=rk[i-1].rk1||rk[i].rk2!=rk[i-1].rk2) cnt++;
			rnk[rk[i].ord]=cnt;
		}
		for (int i=1; i<=N; i++) rk[i].rk1=rnk[i];
	}
	for (int i=1; i<=N; i++) po[rnk[i]]=i;
	for (int i=1; i<=N; i++) if (rnk[i]!=N)
	{
		if (h[i-1]) h[i]=h[i-1]-1;
		int j=po[rnk[i]+1];
		while (i+h[i]<=N&&j+h[i]<=N&&s[i+h[i]]==s[j+h[i]]) h[i]++;
		f[0][rnk[i]]=h[i];
	}
	for (int j=1; j<=19; j++)
		for (int i=1; i+(1<<j)-1<N; i++)
			f[j][i]=min(f[j-1][i],f[j-1][i+(1<<j-1)]);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
		for (int ovo=0; ovo<2; ovo++)
		{
			tn[ovo]=tnx=tny=0;
			while (tp[x[ovo]]!=tp[y[ovo]])
			{
				if (dfn[x[ovo]]>dfn[y[ovo]])
				{
					tx[++tnx]=make_pair(dfn[x[ovo]],dfn[tp[x[ovo]]]);
					x[ovo]=fa[tp[x[ovo]]];
				} else
				{
					ty[++tny]=make_pair(dfn[tp[y[ovo]]],dfn[y[ovo]]);
					y[ovo]=fa[tp[y[ovo]]];
				}
			}
			tx[++tnx]=make_pair(dfn[x[ovo]],dfn[y[ovo]]);
			for (int i=1; i<=tnx; i++) t[ovo][++tn[ovo]]=tx[i];
			for (int i=tny; i; i--) t[ovo][++tn[ovo]]=ty[i];
		}
		nw[0]=nw[1]=1,ans=0;
		while (nw[0]<=tn[0]&&nw[1]<=tn[1])
		{
			for (int ovo=0; ovo<2; ovo++)
				p[ovo]=(t[ovo][nw[ovo]].first<=t[ovo][nw[ovo]].second?t[ovo][nw[ovo]].first:N-t[ovo][nw[ovo]].first+1),
				len[ovo]=t[ovo][nw[ovo]].first-t[ovo][nw[ovo]].second,len[ovo]=(len[ovo]<0?-len[ovo]:len[ovo]),len[ovo]++;
			qaq=lcp(p[0],p[1]);
			if (qaq<len[0]&&qaq<len[1]) {ans+=qaq; break;}
			ans+=min(len[0],len[1]);
			if (len[0]<=len[1]) nw[0]++; else t[0][nw[0]].first+=(t[0][nw[0]].first<t[0][nw[0]].second?1:-1)*len[1];
			if (len[1]<=len[0]) nw[1]++; else t[1][nw[1]].first+=(t[1][nw[1]].first<t[1][nw[1]].second?1:-1)*len[0];
		}
		printf("%d\n",ans);
	}
	return 0;
}