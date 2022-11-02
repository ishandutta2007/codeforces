#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=(int)1e9+7;
const int N=2010;
struct data
{
	int x,y,c;
	void scan(){scanf("%d%d%d",&x,&y,&c);}
	bool operator<(const data&a)const{return x<a.x;}
}a[N];
int tag[N<<2],ans[N<<2],mx[N<<2],C[N<<2];
set<int>s[N];
vector<int>g[N];
int cnt,b[N],n,k,L,f[N],num[N],CONUM,ANS,cnum[N][N];
void build(int p,int le,int ri)
{
	tag[p]=-1;
	if(le==ri)
	{
		ans[p]=1ll*(b[le+1]-b[le])*(b[f[le]]+1)%MOD;
		mx[p]=f[le];
		C[p]=b[le+1]-b[le];
		return;
	}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	ans[p]=(ans[p<<1]+ans[p<<1|1])%MOD;
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	C[p]=(C[p<<1]+C[p<<1|1])%MOD;
}
void push(int p)
{
	if(tag[p]==-1)return;
	ans[p<<1]=1ll*C[p<<1]*(b[tag[p]]+1)%MOD;
	ans[p<<1|1]=1ll*C[p<<1|1]*(b[tag[p]]+1)%MOD;
	mx[p<<1]=mx[p<<1|1]=tag[p];
	tag[p<<1]=tag[p<<1|1]=tag[p];
	tag[p]=-1;
}
int get(int p,int le,int ri,int k)
{
	if(le==ri)return le;
	push(p);
	int mid=(le+ri)>>1;
	if(mx[p<<1]>=k)return get(p<<1,le,mid,k);
	else return get(p<<1|1,mid+1,ri,k);
}
void cov(int p,int le,int ri,int ll,int rr,int x)
{
	if(ll<=le&&ri<=rr)
	{
		tag[p]=x;
		ans[p]=1ll*C[p]*(b[x]+1)%MOD;
		mx[p]=x;
		return;
	}
	push(p);
	int mid=(le+ri)>>1;
	if(ll<=mid)cov(p<<1,le,mid,ll,rr,x);
	if(rr>mid)cov(p<<1|1,mid+1,ri,ll,rr,x);
	ans[p]=(ans[p<<1]+ans[p<<1|1])%MOD;
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	C[p]=(C[p<<1]+C[p<<1|1])%MOD;
}
// void print(int p,int le,int ri)
// {
// 	if(le==ri){printf("%d ",mx[p]);return;}
// 	push(p);
// 	int mid=(le+ri)>>1;
// 	print(p<<1,le,mid);
// 	print(p<<1|1,mid+1,ri);
// }
void del(int y,int c)
{
	cnum[y][c]--;
	if(cnum[y][c])return;
	s[c].erase(y);
	auto it=s[c].lower_bound(y);
	int pre,nxt;
	if(it==s[c].end())nxt=n+1;else nxt=*it;
	if(it==s[c].begin())pre=0;else it--,pre=*it;pre++;
	if(mx[1]<pre)return;
	int pos=get(1,1,cnt,pre);
	if(pos>=nxt)return;
	cov(1,1,cnt,pos,nxt-1,pre-1);
}
int main()
{
	scanf("%d%d%d",&n,&k,&L);
	rep(i,n)
	{
		a[i].scan();
		b[i]=a[i].y;
	}
	sort(b+1,b+n+1);
	cnt=0;
	rep(i,n)if(i==1||b[i]!=b[i-1])b[++cnt]=b[i];
	b[0]=-1;b[cnt+1]=L;
	rep(i,n)a[i].y=lower_bound(b+1,b+cnt+1,a[i].y)-b;
	sort(a+1,a+n+1);a[0].x=-1;
	rep(i,n)
	{
		if(i!=1&&a[i].x==a[i-1].x)continue;
		rep(j,cnt)g[j].clear();
		rep(j,k)s[j].clear();
		for(int j=i;j<=n;j++)
		{
			s[a[j].c].insert(a[j].y);
			g[a[j].y].pb(a[j].c);
			cnum[a[j].y][a[j].c]++;
		}
		rep(j,k)num[j]=0;CONUM=0;
		int now=cnt;
		for(int j=cnt;j;j--)
		{
			for(;now&&CONUM<k;)
			{
				for(auto co:g[now])
				{
					if(!num[co])CONUM++;
					num[co]++;
				}
				now--;
			}
			if(CONUM<k)f[j]=0;else f[j]=now+1;
			for(auto co:g[j])
			{
				num[co]--;
				if(!num[co])CONUM--;
			}
		}
		build(1,1,cnt);
		// rep(j,cnt)printf("%d%c",f[j]," \n"[j==cnt]);
		// printf("%d\n",ans[1]);
		ANS=(ANS+1ll*ans[1]*(a[i].x-a[i-1].x)%MOD*(L-a[n].x))%MOD;
		for(int j=n;j>i;j--)
		{
			del(a[j].y,a[j].c);
			if(a[j].x!=a[j-1].x)ANS=(ANS+1ll*ans[1]*(a[i].x-a[i-1].x)%MOD*(a[j].x-a[j-1].x))%MOD;
			// if(a[j].x!=a[j-1].x){printf("* ");print(1,1,cnt);puts("");}
		}
		cnum[a[i].y][a[i].c]--;
	}
	printf("%d\n",ANS);
	return 0;
}