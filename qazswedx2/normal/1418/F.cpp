#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
int n,m,pn=2e5;
vector<int> a[200005];
ll L,R;
int sum[2000005];
void pushup(int x)
{
	sum[x]=sum[x*2]+sum[x*2+1];
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]+=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int query(int x,int l,int r,int qx)
{
	if(!sum[x]||qx>=r) return 0;
	if(l==r)
	{
		if(sum[x]) return l;
		return 0;
	}
	int mid=(l+r)/2;
	int q=query(x*2,l,mid,qx);
	if(q) return q;
	return query(x*2+1,mid+1,r,qx);
}
void ins(int x)
{
	int sz=a[x].size();
	for(int i=0;i<sz;i++)
		modify(1,1,m,a[x][i],1);
}
void del(int x)
{
	int sz=a[x].size();
	for(int i=0;i<sz;i++)
		modify(1,1,m,a[x][i],-1);
}
int main()
{
	//freopen("cf1418f.out","w",stdout);
	for(int i=1;i<=pn;i++)
		for(int j=i;j<=pn;j+=i)
			a[j].push_back(i);
	scanf("%d%d%lld%lld",&n,&m,&L,&R);
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		ll ql=max(1ll,(L+i-1)/i),qr=min(R/i,(ll)m);
		ql=min(ql,(ll)m+1);
		if(i==1)
		{
			l=ql,r=qr;
			for(int j=l;j<=r;j++)
				ins(j);
		}
		while(l>ql) ins(--l);
		while(r>qr) del(r--);
		int sz=a[i].size(),fl=0;
		for(int j=0;j<sz;j++)
		{
			int u=a[i][j],v,y,xx,yy;
			int q=query(1,1,m,u);
			if(!q) continue;
			v=q;
			if(1ll*i/u*v>n) continue;
			fl=1;
			xx=i/u*v;
			y=(l+v-1)/v*v;
			yy=y/v*u;
			printf("%d %d %d %d\n",i,y,xx,yy);
			break;
		}
		if(!fl) printf("-1\n");
	}
	return 0;
}