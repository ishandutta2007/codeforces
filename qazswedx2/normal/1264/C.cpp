#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int mod=998244353;
int n,m,a[1000005],sum[1000005],sum2[1000005],inv100;
set<int> st;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
void pushup(int x)
{
	sum[x]=1ll*sum[x*2]*sum[x*2+1]%mod;
	sum2[x]=addmod(sum2[x*2]+1ll*sum[x*2]*sum2[x*2+1]%mod);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=sum2[x]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr,int& ans1,int& ans2)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		ans2=addmod(1ll*ans1*sum2[x]%mod+ans2);
		ans1=1ll*ans1*sum[x]%mod;
		return;
	}
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,qr,ans1,ans2);
	query(x*2+1,mid+1,r,ql,qr,ans1,ans2);
}
int getans(int l,int r)
{
	int ans1=1,ans2=0;
	query(1,1,n,l,r-1,ans1,ans2);
	ans2=addmod(ans2+1);
	ans1=submod(1-1ll*ans1*a[r]%mod);
//	printf("l=%d,r=%d,ans1=%d,ans2=%d,%lld\n",l,r,ans1,ans2,1ll*ans1*fpow(submod(1-ans2),mod-2)%mod);
	return 1ll*ans2*fpow(submod(1-ans1),mod-2)%mod;
}
int main()
{
	inv100=fpow(100,mod-2);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=1ll*a[i]*inv100%mod;
	}
	build(1,1,n);
	st.insert(1);
	st.insert(n+1);
	int ans=getans(1,n);
	for(int i=1;i<=m;i++)
	{
		int x,l,r;
		scanf("%d",&x);
		r=*st.upper_bound(x)-1;
		l=*--st.lower_bound(x);
		if(st.find(x)!=st.end())
		{
			ans=addmod(ans+getans(l,r));
			ans=submod(ans-getans(l,x-1));
			ans=submod(ans-getans(x,r));
			st.erase(x);
		}
		else
		{
			ans=submod(ans-getans(l,r));
			ans=addmod(ans+getans(l,x-1));
			ans=addmod(ans+getans(x,r));
			st.insert(x);
		}
		printf("%d\n",ans);
	}
	return 0;
}