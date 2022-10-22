#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 500011,mod = 1e9+7;
char s[MAXN];
std::vector<pii>op;
int L[2],R[2],a[2];
int main()
{
	int n=read(),h=read(),w=read(),ans=0;
	L[0]=1,R[0]=w,L[1]=1,R[1]=h;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='R')
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			R[0]=min(R[0]+1,w),++L[0];
		}
		else if(s[i]=='L')
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			L[0]=max(L[0]-1,1),--R[0];
		}
		else if(s[i]=='U')
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			R[1]=min(R[1]+1,h),++L[1];
		}
		else
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			L[1]=max(L[1]-1,1),--R[1];
		}
		if(L[0]>R[0]||L[1]>R[1]){printf("%d\n",(ans+mod)%mod);return 0;}
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='R')
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			if(R[0]==w)op.push_back(pii(i,0));
			R[0]=min(R[0]+1,w),++L[0];
		}
		else if(s[i]=='L')
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			if(L[0]==1)op.push_back(pii(i,0));
			L[0]=max(L[0]-1,1),--R[0];
		}
		else if(s[i]=='U')
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			if(R[1]==h)op.push_back(pii(i,1));
			R[1]=min(R[1]+1,h),++L[1];
		}
		else
		{
			ans=(ans+ll(R[0]-L[0]+1)*(R[1]-L[1]+1))%mod;
			if(L[1]==1)op.push_back(pii(i,1));
			L[1]=max(L[1]-1,1),--R[1];
		}
		if(L[0]>R[0]||L[1]>R[1]){printf("%d\n",(ans+mod)%mod);return 0;}
	}
	if(op.empty()){puts("-1");return 0;}
	a[0]=R[0]-L[0]+1,a[1]=R[1]-L[1]+1;
	int lst=0;
	while(1)
	{
		for(auto x:op)
		{
			int T=x.first,G=x.second;
			ans=(ans+ll(T-lst)*a[0]%mod*a[1]%mod)%mod;
			--a[G];
			if(a[0]==0||a[1]==0){printf("%d\n",(ans+mod)%mod);return 0;}
			lst=T;
		}
		lst-=n;
	}
	return 0;
}