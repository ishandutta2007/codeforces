#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
typedef std::vector<int> P;
const int MAXN = 111;
int pre[MAXN][MAXN],f[MAXN][MAXN], C[MAXN][MAXN];
int fac[MAXN];
int mod,h;
bool flag=0;
unsigned long long mod_k;


__attribute__ ((always_inline)) inline
int mod_sub(long long a) { return a >= mod ? a - mod : a; }
int mod_barret(unsigned long long a) 
{
	ull x(__uint128_t(a) * mod_k >> 64);
	return a - mod *(x >>h); 
}
int main()
{
	int n=read(),m=read(),k=read();
	mod=read();
	for(h=0;;++h)
		if((1ull<<h)>=mod)break;
	--h,mod_k=((__uint128_t(1)<<(64+h))-1)/mod;
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=mod_barret( ll(fac[i-1])*i);
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=mod_barret(C[i-1][j-1]+C[i-1][j]);
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)f[i][1]=fac[i];
	for(int x=2;x<=m;++x)
	{
		memcpy(pre,f,sizeof f),memset(f,0,sizeof f);
		f[0][0]=1;
		for(int s=1;s<=n;++s)
		{
			for(int i=0;i<s;++i)
			{
				int j=s-i-1;
				for(int p=0;p<=i;++p)
				{
					int coef=mod_barret( ll(C[s-1][i])*pre[i][p]);
					if(coef==0)continue;
					for(int q=0;q<=j;++q)f[s][p+q]=mod_barret((f[s][p+q]+ll(coef)*pre[j][q]));
				}
			}
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}