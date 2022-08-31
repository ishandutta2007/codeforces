#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
typedef long long ll;
int n,m,q,mid,g[1000005],b[10005][55],cnt[100005],tans[55],s;
ll a[1000005],f[55];
void ins(ll x)
{
	for(ll i=m-1;i>=0;i--)
		if(x&(1ll<<i))
		{
			if(!f[i])
			{
				f[i]=x;
				return;
			}
			else x^=f[i];
		}
}
void dfs1(int dep,int x)
{
	if(dep==s)
	{
		g[x]=addmod(g[x]+1);
		return;
	}
	dfs1(dep+1,x);
	dfs1(dep+1,x^f[dep]);
}
int getans(ll x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x-=x&-x;
	}
	return ans;
}
void dfs2(int dep,ll x)
{
	if(dep==m)
	{
		int nw=x&((1ll<<mid)-1),nans=getans(x-nw);
		for(int i=0;i<=mid;i++)
			tans[i+nans]=addmod(tans[i+nans]+b[nw][i]);
		return;
	}
	dfs2(dep+1,x);
	dfs2(dep+1,x^f[dep]);
}
bool cmp(const ll x,const ll y)
{
	return x>y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		ins(a[i]);
	}
	q=m;
	sort(f,f+m,cmp);
	for(int i=0;i<m;i++)
	{
		if(!f[i])
		{
			m=i;
			break;
		}
	}
	sort(f,f+m);
	mid=12;
	s=m;
	for(int i=0;i<m;i++)
		if(f[i]>=(1<<mid))
		{
			s=i;
			break;
		}
//	printf("s=%d\n",s);
	dfs1(0,0);
	for(int i=1;i<(1<<mid);i++)
		cnt[i]=cnt[i/2]+i%2;
	for(int i=0;i<(1<<mid);i++)
		for(int j=0;j<(1<<mid);j++)
		{
			int nw=cnt[i^j];
			b[j][nw]=addmod(b[j][nw]+g[i]);
		}
	//printf("---");
	dfs2(s,0);
	int mul=fpow(2,n-m);
	for(int i=0;i<=q;i++)
	{
		tans[i]=1ll*tans[i]*mul%mod;
		printf("%d ",tans[i]);
	}
	return 0;
}