#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
int n,m,t,tans[105],a[105][105],fr[10005],infr[10005],pn=1000;
int c[105][105],p[105];
ll f[105],b[105];
const int table[105]={0,0,1,26,2,23,27,0,3,16,24,30,28,11,0,13,4,7,17,0,25,22,0,15,29,10,12,6,0,21,14,9,5,20,8,19,18};
int tmod=37;
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
			x^=f[i];
		}
}
bool cmp(const ll x,const ll y)
{
	return x>y;
}
int solve(ull x)
{
	x=((x&0xAAAAAAAAAAAAAAAA)>>1)+(x&0x5555555555555555);
	x=((x&0xCCCCCCCCCCCCCCCC)>>2)+(x&0x3333333333333333);
	x=((x&0xF0F0F0F0F0F0F0F0)>>4)+(x&0x0F0F0F0F0F0F0F0F);
	x=((x&0xFF00FF00FF00FF00)>>8)+(x&0x00FF00FF00FF00FF);
	x=((x&0xFFFF0000FFFF0000)>>16)+(x&0x0000FFFF0000FFFF);
	x=((x&0xFFFFFFFF00000000)>>32)+(x&0x00000000FFFFFFFF);
	return x;
}
void solve2(ll *g,int len)
{
	ll sum=0;
	tans[0]++;
	for(int i=1;i<(1<<len);i++)
	{
		//printf("i=%d,ta=%d,g=%lld\n",i,table[(i&-i)%tmod],g[table[(i&-i)%tmod]]);
		sum^=g[table[(i&-i)%tmod]];
		tans[solve(sum)]++;
	}
}
int C(int x,int y)
{
	if(x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%I64d",&x);
		ins(x);
	}
	for(int i=m-2;i>=0;i--)
		for(int j=i+1;j<m;j++)
			if(f[i]&&f[j]&&(f[j]&(1ll<<i)))
				f[j]^=f[i];
	sort(f,f+m,cmp);
	/*for(int i=0;i<m;i++)
		printf("%lld ",f[i]);
	printf("\n");*/
	t=m;
	for(int i=0;i<m;i++)
		if(!f[i])
		{
			t=i;
			break;
		}
	sort(f,f+t);
	if(t<=27)
	{
		solve2(f,t);
		int mul=fpow(2,n-t);
		for(int i=0;i<=m;i++)
		{
			tans[i]=1ll*tans[i]*mul%mod;
			printf("%d ",tans[i]);
		}
		return 0;
	}
	int at=0;
	for(int i=t-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
			a[at][j]=(f[i]>>j)&1;
		at++;
	}
	for(int i=0;i<t;i++)
	{
		int id=0;
		for(int j=m-1;j>=0;j--)
			if(a[i][j])
			{
				id=j;
				break;
			}
		if(id!=m-i-1)
		{
		//	printf("i=%d,id=%d\n",i,id);
			for(int j=0;j<t;j++)
				swap(a[j][id],a[j][m-i-1]);
		}
	}
	for(int i=t;i<m;i++)
	{
		a[i][m-i-1]=1;
		for(int j=m-t;j<m;j++)
			a[i][j]=a[m-j-1][m-i-1];
		for(int j=0;j<m;j++)
			b[i-t]|=(((ll)a[i][j])<<j);
	}
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}*/
	solve2(b,m-t);
/*	for(int i=0;i<=m;i++)
		printf("%d ",tans[i]);
	printf("\n");*/
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=i;k++)
				if(k%2==0) c[i][j]=addmod(c[i][j]+1ll*C(j,k)*C(m-j,i-k)%mod);
				else c[i][j]=submod(c[i][j]-1ll*C(j,k)*C(m-j,i-k)%mod);
		//	printf("i=%d,j=%d,c=%d\n",i,j,c[i][j]);
		}
	int mul=fpow(2,(n-m+mod-1)%(mod-1));
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
			p[i]=addmod(p[i]+1ll*tans[j]*c[i][j]%mod);
		p[i]=1ll*p[i]*mul%mod;
	}
	for(int i=0;i<=m;i++)
		printf("%d ",p[i]);
	return 0;
}