#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int mod = 1e9+7;
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(ll y){x=(0<=y&&y<mod?y:(y%mod+mod)%mod);}
	void operator+= (Mint a){x+=a.x;if(x>=mod)x-=mod;}
	void operator-= (Mint a){x-=a.x;if(x<0)x+=mod;}
	void operator*= (Mint a){x=ll(x)*a.x%mod;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

const int MAXN = 4011;
Mint pre[MAXN][MAXN],suf[MAXN][MAXN],tp[MAXN];
char a[MAXN],b[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=n+n;++j)pre[i][j]=suf[i][j]=0;
		scanf("%s%s",a+1,b+1);
		for(int i=2;i<=n;i+=2)
		{
			if(a[i]=='1')a[i]='0';
			else if(a[i]=='0')a[i]='1';
			if(b[i]=='1')b[i]='0';
			else if(b[i]=='0')b[i]='1';
		}
		pre[0][n]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=n+n;++j)tp[j]=0;
			if(a[i]=='1'||a[i]=='?')
			{
				for(int j=1;j<=n+n;++j)tp[j]+=pre[i-1][j-1];
			}
			if(a[i]=='0'||a[i]=='?')
			{
				for(int j=0;j<=n+n;++j)tp[j]+=pre[i-1][j];
			}
			if(b[i]=='1'||b[i]=='?')
			{
				for(int j=0;j<n+n;++j)pre[i][j]+=tp[j+1];
			}
			if(b[i]=='0'||b[i]=='?')
			{
				for(int j=0;j<=n+n;++j)pre[i][j]+=tp[j];
			}
		}
		suf[n+1][n]=1;
		for(int i=n;i;--i)
		{
			for(int j=0;j<=n+n;++j)tp[j]=0;
			if(a[i]=='1'||a[i]=='?')
			{
				for(int j=1;j<=n+n;++j)tp[j]+=suf[i+1][j-1];
			}
			if(a[i]=='0'||a[i]=='?')
			{
				for(int j=0;j<=n+n;++j)tp[j]+=suf[i+1][j];
			}
			if(b[i]=='1'||b[i]=='?')
			{
				for(int j=0;j<n+n;++j)suf[i][j]+=tp[j+1];
			}
			if(b[i]=='0'||b[i]=='?')
			{
				for(int j=0;j<=n+n;++j)suf[i][j]+=tp[j];
			}
		}
		Mint ans=0;
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<=n+n;++j)
			{
				ans+=Mint(abs(n-j))*pre[i][j]*suf[i+1][n+n-j];
			}
		}
		printf("%d\n",ans.x);
	}
	return 0;
}