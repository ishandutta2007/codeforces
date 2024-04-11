#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011,mod1 = 1019260817,mod2 = 998244853;
char a[MAXN];
ll f1[MAXN],pw1[MAXN],f2[MAXN],pw2[MAXN];
ll get1(int l,int r){return ((f1[r]-f1[l-1]*pw1[r-l+1])%mod1+mod1)%mod1;}
ll get2(int l,int r){return ((f2[r]-f2[l-1]*pw2[r-l+1])%mod2+mod2)%mod2;}
int maxv[MAXN];
int main()
{
	int n=read();
	scanf("%s",a+1);
	pw1[0]=1,pw2[0]=1;
	for(int i=1;i<=n;++i)
		f1[i]=(f1[i-1]*233+a[i])%mod1,f2[i]=(f2[i-1]*233+a[i])%mod2,
		pw1[i]=pw1[i-1]*233%mod1,pw2[i]=pw2[i-1]*233%mod2;
	for(int i=1;i<=(n>>1);++i)
	{
		int j=n-i+1;
		if(a[i]!=a[j])continue;
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(get1(i-mid+1,i+mid-1)==get1(j-mid+1,j+mid-1)&&
				get2(i-mid+1,i+mid-1)==get2(j-mid+1,j+mid-1))l=mid;
			else r=mid-1;
		}
		maxv[i-l+1]=i;
	}
	int cur=-1;
	for(int i=1;i<=((n+1)>>1);++i)
	{
		umax(cur,maxv[i]);
		if(cur>=i)printf("%d ",((cur-i)<<1)+1);
		else printf("-1 ");
	}
	puts("");
	return 0;
}