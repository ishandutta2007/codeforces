#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll pprime[15]={2,3,5,7,11,13,17,19,23,29};
inline ll mul(ll x,ll y,ll mod)
{
	return ((x*y-(ll)((long double)x*y/mod+1e-9)*mod)%mod+mod)%mod;
}
inline ll fpow(ll x,ll y,ll mod)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x,mod);
		x=mul(x,x,mod);
		y/=2;
	}
	return ans%mod;
}
inline bool check(ll nw,ll x,ll d,ll r)
{
	for(ll i=fpow(x,d,nw),j;r;r--)
	{
		j=mul(i,i,nw);
		if(j==1)
		{
			if(i==1||i==nw-1) return true;
			else return false;
		}
		i=j;
	}
	return false;
}
inline bool millerrabin(ll nw)
{
	if(nw==1) return 0;
	ll d=nw-1,r=0;
	while(d%2==0) d/=2,r++;
	for(register int i=0;i<10;i++)
	{
		if(nw==pprime[i]) return 1;
		if(nw%pprime[i]==0) return 0;
		if(!check(nw,pprime[i],d,r)) return 0;
	}
	return 1;
}
struct pt
{
	ll val,id;
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}qans[100005];
int n,k,bt,pt,t;
ll a[100005],b[100005],c[100005],prime[100005],tans[100005],d[100005];
map<ll,int> mp,mp2;
ll getpw(ll x,int y)
{
	ll ans=pow(x,1.0/y);
	for(ll i=max(ans-3,1ll);i<=ans+3;i++)
	{
		//printf("getpw:x=%lld,y=%d,i=%lld,pow=%lld,%d,%d\n",x,y,i,fpow(i,y,(1ll<<62)),fabs(pow(i,y)-x)<1e7,fpow(i,y,(1ll<<63))==x);
		if(fabs(pow(i,y)-x)<1e7&&fpow(i,y,(1ll<<62))==x)
			return i;
	}
	return -1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(int j=1;j<=64;j++)
		{
			ll q;
			if(j==1) q=a[i];
			else q=getpw(a[i],j);
			if(q==-1) continue;
			//printf("q=%d\n",q);
			if(millerrabin(q))
			{
			//	printf("i=%d,j=%d,q=%lld\n",i,j,q);
				d[i]=q;
				b[++bt]=q;
				mp[q]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(d[i]&&mp[d[i]]>=2)
		{
			mp2[d[i]]++;
			if(mp2[d[i]]<=2)
			{
				qans[++t].id=a[i];
				qans[t].val=d[i];
			}
		}
	sort(qans+1,qans+t+1);
	for(int i=1;i<=t;i++)
		tans[i]=qans[i].id;
	mp.clear();
	sort(b+1,b+bt+1);
	int mn=1e9,ans=0;
	ll id=-1;
	for(int l=1,r;l<=bt;l=r+1)
	{
		r=l;
		while(r<bt&&b[r+1]==b[l]) r++;
		if(r-l+1>1)
			prime[++pt]=b[l];
	}
	for(int i=1;i<=n;i++)
	{
		int ct=0;
		ll nw=a[i],qwq;
		for(int j=1;j<=pt;j++)
			if(nw%prime[j]==0)
			{
				qwq=prime[j];
				ct++;
				while(nw%prime[j]==0) nw/=prime[j];
			}
		if(nw==1)
		{
			ans++;
			if(ct>1)
			{
				tans[++t]=a[i];
				if(ct<mn) mn=ct,id=a[i];
			}
			if(ct==1)
			{
				mp[qwq]++;
				if(mp[qwq]>2)
				{
					tans[++t]=a[i];
					if(ct<mn) mn=ct,id=a[i];
				}
			}
		}
	}
//	printf("mn=%d\n",mn);
/*	printf("t=%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%lld ",tans[i]);
	printf("\n");
	printf("ans=%d\n",ans);*/
	if(ans<k)
	{
		printf("0\n");
		return 0;
	}
	if(k%2==0)
	{
		for(int i=1;i<=k;i++)
			printf("%lld ",tans[i]);
		return 0;
	}
	else
	{
		if(k>pt*2)
		{
			for(int i=1;i<=k;i++)
				printf("%lld ",tans[i]);
			return 0;
		}
		if(mn>k/2)
		{
			printf("0\n");
			return 0;
		}
		int nw=k/2-mn;
		for(int i=1;i<=pt;i++)
			if(id%prime[i]==0||nw)
			{
				if(id%prime[i]) nw--;
				for(int j=1;j<=2*pt;j++)
					if(tans[j]%prime[i]==0)
						printf("%lld ",tans[j]);
			}
		printf("%lld\n",id);
	}
	return 0;
}