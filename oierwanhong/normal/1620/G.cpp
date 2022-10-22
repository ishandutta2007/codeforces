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

const int MAXN = 23;
Mint f[1<<23];
int cnt[MAXN][27];
char a[200011];
int now[27],pre[27][27];
int n;
void dfs(int x,int s,int sgn)
{
	//printf("dfs x=%d,s=%d\n",x,s);
	if(x==n)
	{
		if(!s){f[0]=0;return;}
		Mint prod=1;
		for(int c=0;c<26;++c)prod*=(now[c]+1);
		if(sgn)f[s]=prod;
		else f[s]=-prod;
		//printf("F[%d]=%d\n",s,f[s].x);
		return;
	}
	memcpy(pre[x],now,sizeof now);
	for(int c=0;c<26;++c)umin(now[c],cnt[x][c]);
	dfs(x+1,s|(1<<x),sgn^1);
	//printf("back x=%d,s=%d\n",x,s);
	for(int c=0;c<26;++c)now[c]=pre[x][c];
	dfs(x+1,s,sgn);
}
void FWT(Mint *a)
{
	for(int cur=1;cur<(1<<n);cur<<=1)
		for(int j=0;j<(1<<n);j+=cur<<1)
			for(int k=0;k<cur;++k)
				a[j+cur+k]+=a[j+k];
}
int main()
{
	n=read();
	for(int i=0;i<n;++i)
	{
		scanf("%s",a);
		int l=strlen(a);
		for(int j=0;j<l;++j)++cnt[i][a[j]-'a'];
	}
	memset(now,0x3f,sizeof now);
	dfs(0,0,0);
	FWT(f);
	ll ans=0;
	for(int s=0;s<(1<<n);++s)
	{
		int res=f[s].x,sum=0,c=0;
		//printf("F[%d]=%d\n",s,f[s].x);
		for(int i=0;i<n;++i)
			if(s&(1<<i))sum+=i+1,++c;
		ans^=ll(res)*sum*c;
	}
	printf("%lld\n",ans);
	return 0;
}