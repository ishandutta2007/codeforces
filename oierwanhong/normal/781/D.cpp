#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<bitset>
typedef long long ll;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
using std::max;
using std::min;
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 511;
typedef std::bitset<MAXN> vec;
struct matrix
{
	vec a[MAXN];
	matrix(int tp=0)
	{
		if(tp)for(int i=0;i<MAXN;++i)a[i][i]=1;
	}
	matrix operator *(const matrix& you)
	{
		matrix tp;
		for(int i=0;i<MAXN;++i)
			for(int j=0;j<MAXN;++j)
				if(a[i][j])tp.a[i]|=you.a[j];
		return tp;
	}
	vec operator *(const vec& you)
	{
		vec res;
		for(int i=0;i<MAXN;++i)res[i]=(a[i]&you).any();
		return res;
	}
}f[61][2];
int main()
{
	int n=read(),m=read();
	while(m--)
	{
		int u=read(),v=read(),t=read();
		if(t==0)f[0][0].a[v][u]=1;
		else f[0][1].a[v][u]=1;
	}
	for(int k=1;k<=60;++k)
		f[k][0]=f[k-1][1]*f[k-1][0],
		f[k][1]=f[k-1][0]*f[k-1][1];
	vec a;
	for(int i=1;i<=n;++i)a[i]=1;
	if((f[60][0]*a).any()){puts("-1");return 0;}
	ll res=0;
	bool nf=0;
	for(int k=59;k>=0;--k)
		if((f[k][nf]*a).any())res+=1ll<<k, a=f[k][nf]*a,nf^=1;
	printf("%lld\n",res>ll(1e18)?-1ll:res);
	return 0;
}