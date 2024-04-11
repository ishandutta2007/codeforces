#include<bits/stdc++.h>
#define sz 201010
#define mod 998244353
using namespace std;
typedef long long ll;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
	#endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
ll sum[sz];
int n,m;
ll ksm(int y)
{
	ll ret,x;
	for (ret=1,x=2;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
	return ret;
}
int main()
{
	file();
	read>>n>>m;
	int i,j,k,x,y,z;
	char c;
	for (i=n;i;i--)
	{
		cin>>c;
//		sum[i]=sum[i+1];
		if (c=='1') sum[i]=ksm(i-1);
	}
	for (i=1;i<=m;i++) (sum[i]+=sum[i-1])%=mod;
	ll ans=0;
	for (i=m;i;i--)
	{
		cin>>c;
		if (c=='1') (ans+=sum[i])%=mod;
	}
	cout<<ans;
}