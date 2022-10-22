#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define ll long long
ll n,m;
ll a[N],s[N],pre[N];
const ll inf=5000000008,INF=1000000000000000;
inline ll read()
{
    ll F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
struct point
{
	ll c,v;
	bool operator < (const point &x) const
	{
		if (v==x.v) return c<x.c;
		return v<x.v;
	}
};
point dp[N],w[N],b[N];
int kp[N];
struct stmin
{
	int sum[N];
	void build(int u,int l,int r)
	{
		for (int i=1;i<=n;i++) sum[i]=n+1;
	}
	void update(int u,int l,int r,int x,int y)
	{
		for (;x<=n;x+=(x&(-x))) sum[x]=min(sum[x],y);
	}
	ll ask(int u,int L,int R,int l,int r)
	{
		int res=n+1;
		for (;r;r-=(r&(-r))) res=min(res,sum[r]);
		return res;
	}
}D;
struct st
{
	ll sum[N];
	void build(int u,int l,int r)
	{
		for (int i=1;i<=n;i++) sum[i]=0;
	}
	void update(int u,int l,int r,int x,ll y)
	{
		for (;x<=n;x+=(x&(-x))) sum[x]+=y;
	}
	ll ask(int u,int L,int R,int l,int r)
	{
		ll res=0;
		for (;r;r-=(r&(-r))) res+=sum[r];
		return res;
	}
}A,B;
struct stmax
{
	point sum[N*4];
	inline void push_up(int u)
	{
		sum[u]=max(sum[u*2],sum[u*2+1]);
	}
	void build(int u,int l,int r)
	{
		sum[u].v=-INF,sum[u].c=0;
		if (l==r) return;
		int mid=(l+r)>>1;
		build(u*2,l,mid),build(u*2+1,mid+1,r);
	}
	void update(int u,int l,int r,int x,point y)
	{
		if (l==r)
		{
			sum[u]=y;
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) update(u*2,l,mid,x,y);
		else update(u*2+1,mid+1,r,x,y);
		push_up(u);
	}
	point ask(int u,int L,int R,int l,int r)
	{
		if (l<=L&&R<=r) return sum[u];
		int mid=(L+R)>>1;
		point res;
		res.c=0,res.v=-INF;
		if (l<=mid) res=max(res,ask(u*2,L,mid,l,r));
		if (mid<r) res=max(res,ask(u*2+1,mid+1,R,l,r));
		return res;
	}
}C;
point check(ll c)
{
	dp[0].c=0,dp[0].v=0;
	w[0]=dp[0];
	A.build(1,1,n),B.build(1,1,n),C.build(1,1,n),D.build(1,1,n);
	for (int i=1;i<=n;i++) b[i].v=s[i],b[i].c=i;
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) kp[b[i].c]=i;
	point Y;
	Y.c=0,Y.v=0;
	for (int i=1;i<=n;i++)
	{
		ll res=0,p=i,cnt=0;
		dp[i].v=-INF;
		point J;
		J.c=INF,J.v=s[i]-c;
		int u=upper_bound(b+1,b+n+1,J)-b-1;
		//cout << b[u].v << " " << J.v << endl;
		if (u>0) cnt=A.ask(1,1,n,1,u),res=B.ask(1,1,n,1,u)+cnt*(s[i]-c),p=D.ask(1,1,n,1,u);
		// for (int j=1;j<i;j++)
		// {
			// if (s[j]<=s[i]-c)
			// {
				// assert(kp[j]<=u+1);
				// res+=s[i]-s[j]-c;
				// cnt++;
				// p=min(p,1ll*j);
			// }
		// }
		if (s[0]<=s[i]-c)
		{
			res+=s[i]-s[0]-c;
			cnt++;
			p=min(p,0ll);
		}
		A.update(1,1,n,kp[i],1);
		B.update(1,1,n,kp[i],-s[i]);
		D.update(1,1,n,kp[i],i);
		p=min(p,1ll*i);
		//cout << cnt << " " << res << " " << p << endl;
		
		p++;
		if (p-1==0) 
		{
			dp[i]=max(dp[i],dp[0]);
			if (p<=i-1) dp[i]=max(dp[i],C.ask(1,1,n,p,i-1));
		}
		else
		{
			if (p-1<=i-1) dp[i]=max(dp[i],C.ask(1,1,n,p-1,i-1));
		}
		if (p!=1)
		{
			point v=w[p-2];
			v.c++,v.v+=s[i]-c;
			dp[i]=max(dp[i],v);
		}
		Y.c+=cnt,Y.v+=res;
		point U=dp[i];
		U.v-=pre[i];
		w[i]=max(w[i-1],U);
		C.update(1,1,n,i,dp[i]);
	}
	dp[n].c+=Y.c,dp[n].v+=Y.v;
	return dp[n];
}
int main()
{
	// freopen("road.in","r",stdin);
	// freopen("road.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];

	for (int i=1;i<=n;i++) pre[i]=min(pre[i-1],s[i]);
	ll l=-inf,r=inf;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (check(mid).c>=m) l=mid+1; 
		else r=mid-1;
	}
	ll ans=check(r).v+r*m;
	cout << ans;
	return 0;
}