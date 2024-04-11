#include<cstdio>
#include<cstdlib>
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
const int MAXN = 5011,mod = 1e9+7;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(int x):x(x) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
	void operator/= (Mint you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

Mint p[MAXN][MAXN];
int main()
{
	int k=read();
	Mint pa=read(),pb=read(),s=pa+pb,ans=0;
	pa/=s,pb/=s;
	p[1][0]=1;
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<k;++j)
		{
			if(i!=1||j!=0)p[i][j]=p[i-1][j]*pa;
			if(j>=i)p[i][j]+=p[i][j-i]*pb;
		}
		if(i==k)
		{
			Mint rate=pa/pb;
			for(int j=0;j<k;++j)ans+=p[i][j]*(rate+k+j);
		}
		else for(int j=k;j<k+i;++j)ans+=p[i][j-i]*pb*j;
	}
	printf("%d\n",ans.x);
	return 0;
}