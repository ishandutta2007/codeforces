#include<bits/stdc++.h>
using namespace std;

int L,R,l[100010],r[100010],n,m,x,y,idl[100010],idr[100010],fl,fr,mid,ans,col[100010];
vector<int> v1,v2;

namespace sat
{
	bool bo[600010];
	int n,hd[600010],cnt,bel[600010],dfn[600010],low[600010],sta[600010],tp,Hd[600010],d[600010],q[600010],l,r,x,col[600010],lim;
	struct node{int to,next;}e[6000010],E[6000010];
	vector<int> v[600010];
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

bool cmpl(int x,int y) {return l[x]<l[y];}
bool cmpr(int x,int y) {return r[x]<r[y];}

int main()
{
	scanf("%d%d%d%d",&L,&R,&n,&m),sat::init(6*n,2*n);
	for (int i=1; i<=n; i++) scanf("%d%d",&l[i],&r[i]),idl[i]=idr[i]=i;
	sort(idl+1,idl+1+n,cmpl),sort(idr+1,idr+1+n,cmpr);
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d",&x,&y);
		sat::addedge(2*x,2*y-1),sat::addedge(2*y-1,2*x);
		sat::addedge(2*x-1,2*y),sat::addedge(2*y,2*x-1);
	}
	for (int i=1; i<=n; i++)
	{
		sat::addedge(2*n+i,idr[i]*2-1);
		sat::addedge(3*n+i,idr[i]*2);
		if (i>1) 
		{
			sat::addedge(2*n+i,2*n+i-1);
			sat::addedge(3*n+i,3*n+i-1);
		}
	}
	for (int i=n; i; i--)
	{
		sat::addedge(4*n+i,idl[i]*2-1);
		sat::addedge(5*n+i,idl[i]*2);
		if (i<n)
		{
			sat::addedge(4*n+i,4*n+i+1);
			sat::addedge(5*n+i,5*n+i+1);
		}
	}
	for (int i=1; i<=n; i++)
	{
		fl=1,fr=n,ans=0;
		while (fl<=fr)
		{
			mid=(fl+fr)>>1;
			if (l[idl[mid]]>r[i]) ans=mid,fr=mid-1; else fl=mid+1;
		}
		if (ans) sat::addedge(2*i-1,5*n+ans),sat::addedge(2*i,4*n+ans);
		fl=1,fr=n,ans=0;
		while (fl<=fr)
		{
			mid=(fl+fr)>>1;
			if (r[idr[mid]]<l[i]) ans=mid,fl=mid+1; else fr=mid-1;
		}
		if (ans) sat::addedge(2*i-1,3*n+ans),sat::addedge(2*i,2*n+ans);
		fl=1,fr=n,ans=0;
		while (fl<=fr)
		{
			mid=(fl+fr)>>1;
			if (l[idl[mid]]>R-l[i]) ans=mid,fr=mid-1; else fl=mid+1;
		}
		if (ans) sat::addedge(2*i-1,4*n+ans),sat::addedge(2*i,5*n+ans);
		fl=1,fr=n,ans=0;
		while (fl<=fr)
		{
			mid=(fl+fr)>>1;
			if (r[idr[mid]]<L-r[i]) ans=mid,fl=mid+1; else fr=mid-1;
		}
		if (ans) sat::addedge(2*i-1,2*n+ans),sat::addedge(2*i,3*n+ans);
	}
	if (!sat::solve()) return puts("IMPOSSIBLE"),0;
	for (int i=1; i<=n; i++) 
		if (sat::col[sat::bel[2*i-1]]) v1.push_back(i);
		else v2.push_back(i);
	int l2=0,r2=1000000000,l1=0,r1=1000000000,ans1,ans2;
	for (int i=0,sz=v1.size(); i<sz; i++)
		l1=max(l[v1[i]],l1),r1=min(r[v1[i]],r1),col[v1[i]]=1;
	for (int i=0,sz=v2.size(); i<sz; i++)
		l2=max(l[v2[i]],l2),r2=min(r[v2[i]],r2),col[v2[i]]=2;
	if (L-l1<=r2&&L-l1>=l2) ans1=l1,ans2=L-l1; else
	if (R-l1<=r2&&R-l1>=l2) ans1=l1,ans2=R-l1; else
	if (L-r1<=r2&&L-r1>=l2) ans1=r1,ans2=L-r1; else
	if (R-r1<=r2&&R-r1>=l2) ans1=r1,ans2=R-r1; else
	if (L-l2<=r1&&L-l2>=l1) ans1=L-l2,ans2=l2; else
	if (R-l2<=r1&&R-l2>=l1) ans1=R-l2,ans2=l2; else
	if (L-r2<=r1&&L-r2>=l1) ans1=L-r2,ans2=r2; else
	if (R-r2<=r1&&R-r2>=l1) ans1=R-r2,ans2=r2; else
	if (l1+l2>=L&&l1+l2<=R) ans1=l1,ans2=l2; else
	if (l1+r2>=L&&l1+r2<=R) ans1=l1,ans2=r2; else
	if (r1+l2>=L&&r1+l2<=R) ans1=r1,ans2=l2; else
	if (r1+r2>=L&&r1+r2<=R) ans1=r1,ans2=r2; else
	return puts("IMPOSSIBLE"),0;
	puts("POSSIBLE");
	printf("%d %d\n",ans1,ans2);
	for (int i=1; i<=n; i++) printf("%d",col[i]);
	return puts(""),0;
}