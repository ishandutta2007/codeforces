#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 5000011,mod = 1e9+7;
ll seed = 0,base = 0;

int rnd()
{
	int ret = seed;
	seed = (seed * base + 233)%mod;
	return ret;
}
int p[MAXN],t[MAXN],a[MAXN],b[MAXN];
void init(int n)
{
	int m=read();
	p[0] = 0;
	for(int i=1;i<=m;++i)
	{
		p[i]=read();
		int k=read(),x=read(),w=read();
		seed = x;
		base = w;
		for(int j=p[i-1]+1;j<=p[i];++j)
			t[j] = (rnd()&1) + 1,
			b[j] = a[j] = (rnd()%k) + 1;
	}
}
std::vector<int>seq;
int main()
{
	int n=read();
	init(n);
	int A=1,B=2;
	ll s1=0,s2=0,cur=0;
	for(int i=1;i<=n;++i)
		if(t[i]==1)s1+=a[i];
		else s2+=a[i];
	if(s1>s2||(s1==s2&&t[1]==2))
	{
		std::swap(A,B);
	}
		if(t[1]!=A)--b[1];
	for(int i=1;i<=n;++i)
		if(t[i]==A)cur+=b[i],b[i]=0;
		else
		{
			int tp=min(b[i],cur);
			b[i]-=tp,cur-=tp;
		}
	for(int i=1;i<=n;++i)
		if(t[i]==A)cur+=b[i],b[i]=0;
		else
		{
			int tp=min(b[i],cur);
			b[i]-=tp,cur-=tp;
		}
	for(int i=1;i<=n;++i)
		if(t[i]==A)cur+=b[i],b[i]=0;
		else
		{
			int tp=min(b[i],cur);
			b[i]-=tp,cur-=tp;
		}
	int ans=1;
	for(int i=1;i<=n;++i)ans=ans*(((ll(a[i]-b[i])^(ll(i)*i))+1)%mod)%mod;
	printf("%d\n",ans);
	return 0;
}