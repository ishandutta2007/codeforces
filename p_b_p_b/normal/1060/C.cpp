#include<bits/stdc++.h>
#define sz 2020
#define mod 998244353ll
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
ll a[sz],b[sz];
ll aa[sz],bb[sz];
int n,m;
int main()
{
	file();
	int i,j,k,x,y,z;
	ll X;
	read>>n>>m;
	for (i=1;i<=n;i++) read>>a[i],a[i]+=a[i-1];
	for (i=1;i<=m;i++) read>>b[i],b[i]+=b[i-1];
	memset(aa,0x3f,sizeof(aa));memset(bb,0x3f,sizeof(bb));
	for (i=1;i<=n;i++)
		for (j=1;j<=i;j++)
			aa[j]=min(aa[j],a[i]-a[i-j]);
	for (i=1;i<=m;i++)
		for (j=1;j<=i;j++)
			bb[j]=min(bb[j],b[i]-b[i-j]);
	read>>X;
	int ans=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (aa[i]*bb[j]<=X)
				ans=max(ans,i*j);
	cout<<ans;		
}