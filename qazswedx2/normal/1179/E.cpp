#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
mt19937 rnd(111);
typedef long long ll;
ll m;
#ifdef DEBUG
int pn,g[105][105];
ll query(int x,ll y)
{
	if(y>pn) return m;
	return g[x][y];
}
#else
ll query(int x,ll y)
{
	printf("? %d %lld\n",x,y);
	fflush(stdout);
	ll ans;
	scanf("%lld",&ans);
	return ans;
}
#endif
ll tans[100005][2],f[100005];
int c[100005],vis[100005];
int cmp(const int x,const int y)
{
	return f[x]<f[y];
}
ll getans(int x,ll l,ll r,ll val)
{
	ll mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		ll q=query(x,mid);
	//	printf("l=%lld,r=%lld,q=%lld,val=%lld\n",l,r,q,val);
		if(q<val) l=mid+1;
		else if(q>val) r=mid-1;
		else return mid;
	}
	return -1;
}
ll check(vector<int> &a,ll l,ll r,ll smid,ll val)
{
//	printf("check\n");
	int sz=a.size();
	int cl=0,cr=sz-1;
	for(int i=0;i<sz;i++)
		swap(a[i],a[rnd()%(i+1)]),vis[i]=0;
	while(cl<=cr)
	{
		int x,ct0=0,ct1=0;
		for(int i=0;i<sz;i++)
			if(!vis[i]) x=a[i];
		ll q=getans(x,l,r,val);
		for(int i=0;i<sz;i++)
		{
			if(vis[i]) continue;
			f[i]=query(a[i],q);
			if(f[i]<val) ct0++;
			if(f[i]<=val) ct1++;
	//		printf("i=%d,a=%d,f=%lld,val=%lld\n",i,a[i],f[i],val);
		}
	//	printf("smid=%lld,q=%lld,cl=%d,cr=%d,ct0=%d,ct1=%d\n",smid,q,cl,cr,ct0,ct1); 
		if(cl+ct1<=smid)
		{
			for(int i=0;i<sz;i++)
				if(!vis[i]&&f[i]<=val)
				{
					vis[i]=1;
					c[cl++]=i;
				}
		}
		else if(cl+ct0>smid)
		{
			for(int i=0;i<sz;i++)
				if(!vis[i]&&f[i]>=val)
				{
					vis[i]=1;
					c[cr--]=i;
				}
		}
		else
		{
			int nw=cl;
			for(int i=0;i<sz;i++)
				if(!vis[i])
					c[nw++]=i;
			sort(c+cl,c+cr+1,cmp);
	//		printf("~check\n");
	//		for(int i=0;i<sz;i++)
	//			printf("%d ",a[c[i]]);
	//		printf("\n");
			return q;
		}
	}
	return -1;
}
void solve(vector<int> a,ll l,ll r,ll ql,ll qr,ll k)
{
	int sz=a.size();
/*	printf("solve:l=%lld,r=%lld,ql=%lld,qr=%lld,k=%lld,a=",l,r,ql,qr,k);
	for(int i=0;i<sz;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	if(sz==1)
	{
		tans[a[0]][0]=l;
		tans[a[0]][1]=r;
		return;
	}
	ll mid,mmid=(ql+qr)/2;
	int smid=(sz-1)/2;
	mid=check(a,l,r,smid,mmid*k);
	vector<int> ls,rs;
	for(int i=0;i<=smid;i++)
		rs.push_back(a[c[i]]);
	for(int i=smid+1;i<sz;i++)
		ls.push_back(a[c[i]]);
	solve(ls,l,mid,ql,mmid,k);
	solve(rs,mid,r,mmid,qr,k);
}
int n;
int main()
{
	scanf("%d%lld",&n,&m);
#ifdef DEBUG
	scanf("%d",&pn);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=pn;j++)
			scanf("%d",&g[i][j]);
#endif
	vector<int> a;
	for(int i=1;i<=n;i++)
		a.push_back(i);
	solve(a,0,1e18,0,n,m/n);
/*#ifdef DEBUG
	for(int i=1;i<=n;i++)
		if(query(i,tans[i][1])-query(i,tans[i][0])<m/n)
		{
			fprintf(stderr,"i=%d,error\n",i);
			return 1;
		}
#endif*/
	printf("!\n");
	for(int i=1;i<=n;i++)
		printf("%lld %lld\n",tans[i][0],tans[i][1]);
	return 0;
}