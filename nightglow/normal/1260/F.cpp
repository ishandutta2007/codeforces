#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 100005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 1000000007

using namespace std;

int i,j,m,n,p,k,l[N],r[N],st[N],ed[N],tot,size[N],fa[N],deep[N];

int sum[N*4],add[N*4],son[N],top[N];

vector<int>v[N];

void dfs(int x)
{
		int i;
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				if (fa[x]==p) continue;
				fa[p]=x;
				deep[p]=deep[x]+1;
				dfs(p);
				size[x]+=size[p];
				if (!son[x]||size[son[x]]<size[p]) son[x]=p;
		}
		size[x]++;
}

void Dfs(int x,int tp)
{
		st[x]=++tot;
		int i;
		top[x]=tp;
		if (son[x]) Dfs(son[x],tp);
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				if (fa[x]==p||son[x]==p) continue;
				Dfs(p,p);
		}
		ed[x]=tot; 
}

vector<int>str[N],End[N];

int inv[N];

void down(int t,int len)
{
		if (!add[t]) return;
		(add[ls]+=add[t])%=Mo;
		(add[rs]+=add[t])%=Mo;
		(sum[ls]+=1ll*add[t]*(len-(len>>1))%Mo)%=Mo;
		(sum[rs]+=1ll*add[t]*(len>>1)%Mo)%=Mo;
		add[t]=0;
}

int Ask(int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr) return sum[t];
		else
		{
				int S=0;
				down(t,r-l+1);
				if (ll<=mid) S+=Ask(ll,rr,l,mid,ls);
				if (rr>mid)  S+=Ask(ll,rr,mid+1,r,rs);
				return S%Mo; 
		}
}

int Work(int x)
{
		int s=0;
		for (;x;x=fa[top[x]])
		{
				if (st[x]!=1)
				(s+=Ask(max(2,st[top[x]]),st[x],1,n,1))%=Mo;
		}
		return s;
}

void Add(int ll,int rr,int c,int l,int r,int t)
{
		if (ll<=l&&r<=rr)
		{
				add[t]=(add[t]+c)%Mo;
				sum[t]=(sum[t]+1ll*(r-l+1)*c%Mo)%Mo;
		}
		else
		{
				down(t,r-l+1);
				if (ll<=mid) Add(ll,rr,c,l,mid,ls);
				if (rr>mid)  Add(ll,rr,c,mid+1,r,rs);
				sum[t]=(sum[ls]+sum[rs])%Mo;
		}
}

void insert(int x,int y)
{
		y=(y+Mo)%Mo;
		for (;x;x=fa[top[x]])
		{
				Add(st[top[x]],st[x],y,1,n,1);
		}
}

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo; 
		}
		return sum;
}

int val[N];

int main()
{
		scanf("%d",&n);
		int S=1;
		for (i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]),val[i]=r[i]-l[i]+1,S=1ll*S*val[i]%Mo;
		for (i=1;i<N;++i) inv[i]=power(i,Mo-2);
		for (i=1;i<n;++i)
		{
				int x,y;
				scanf("%d%d",&x,&y);
				v[x].pb(y);
				v[y].pb(x); 
		}
		dfs(1); Dfs(1,1);
		for (i=1;i<=n;++i) str[l[i]].pb(i);
		for (i=1;i<=n;++i) End[r[i]].pb(i);
		int Ans=0,WA=0,WB=0,ans=0;
		for (i=1;i<=100000;++i)
		{
				for (j=0;j<(int)str[i].size();++j)
				{
						int g=str[i][j];
						(Ans+=1ll*WA*inv[val[g]]%Mo)%=Mo;
						(Ans+=1ll*WB*inv[val[g]]%Mo*deep[g]%Mo)%=Mo;
						Ans=(Ans-2ll*Work(g)*inv[val[g]]%Mo+Mo)%Mo;
						insert(g,inv[val[g]]);
						(WA+=1ll*inv[val[g]]*deep[g]%Mo)%=Mo;
						(WB+=1ll*inv[val[g]]%Mo)%=Mo;
				}
				ans=(ans+Ans)%Mo;
				for (j=0;j<(int)End[i].size();++j)
				{
						int g=End[i][j];
						insert(g,-inv[val[g]]);
						(WA+=Mo-1ll*inv[val[g]]*deep[g]%Mo)%=Mo;
						(WB+=Mo-1ll*inv[val[g]]%Mo)%=Mo;
						(Ans+=Mo-1ll*WA*inv[val[g]]%Mo)%=Mo;
						(Ans+=Mo-1ll*WB*inv[val[g]]%Mo*deep[g]%Mo)%=Mo;
						Ans=(Ans+2ll*Work(g)*inv[val[g]]%Mo)%Mo;
				}
		}
		printf("%d\n",1ll*S*ans%Mo);
}