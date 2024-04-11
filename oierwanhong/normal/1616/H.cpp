#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
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
const int mod = 998244353;
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
	Mint(ll y){x=(0<=y&&y<mod?y:(y%mod+mod)%mod);}
	void operator+= (Mint a){x+=a.x;if(x>=mod)x-=mod;}
	void operator-= (Mint a){x-=a.x;if(x<0)x+=mod;}
	void operator*= (Mint a){x=ll(x)*a.x%mod;}
	Mint operator- (){return x?mod-x:0;}
	Mint operator++ (){return x+1==mod?0:x+1;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

const int MAXN = 300011;
Mint pw[MAXN];
Mint calc(std::vector<int> a,std::vector<int> b,int lim,int k)
{
	if(a.empty())return pw[b.size()]-1;
	if(b.empty())return pw[a.size()]-1;
	if(k<0)return pw[a.size()]*pw[b.size()]-1;
	std::vector<int>a0,a1,b0,b1;
	for(auto x:a)
		if(x&(1<<k))a1.emplace_back(x);
		else a0.emplace_back(x);
	for(auto x:b)
		if(x&(1<<k))b1.emplace_back(x);
		else b0.emplace_back(x);
	int c=lim>>k&1;
	if(c==0)
	{
		Mint res=calc(a0,b0,lim,k-1)+calc(a1,b1,lim,k-1);
		res=res-(pw[a0.size()]-1)-(pw[a1.size()]-1)+pw[a.size()]-1;
		res=res-(pw[b0.size()]-1)-(pw[b1.size()]-1)+pw[b.size()]-1;
		return res;
	}
	else
	{
		Mint res=(calc(a0,b1,lim,k-1)+1)*(calc(a1,b0,lim,k-1)+1)-1;
		//res=res-(pw[a0.size()]-1)-(pw[a1.size()]-1)+pw[a.size()]-1;
		//res=res-(pw[b0.size()]-1)-(pw[b1.size()]-1)+pw[b.size()]-1;
		return res;
	}
}
Mint solve(std::vector<int> a,int lim,int k)
{
	if(k<0)return pw[a.size()]-1;
	if(a.empty())return 0;
	std::vector<int>a0,a1;
	for(auto x:a)
		if(x&(1<<k))a1.emplace_back(x);
		else a0.emplace_back(x);
	int c=lim>>k&1;
	if(c==0)
	{
		Mint res=solve(a0,lim,k-1)+solve(a1,lim,k-1);
		return res;
	}
	else
	{
		Mint res=calc(a0,a1,lim,k-1);
		return res;
	}
}
int main()
{
	std::vector<int>a;
	int n=read(),lim=read();
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2;
	for(int i=0;i<n;++i)a.emplace_back(read());
	printf("%d\n",solve(a,lim,29).x);
	return 0;
}