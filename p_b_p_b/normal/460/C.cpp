#include<bits/stdc++.h>
#define sz 100010
#define mod (int)(1e9+7)
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
int n,m,L;
int a[sz];
int v[sz];
bool judge(int W)
{
	int i;
	ll c=0,cur=0;
	v[0]=v[n+1]=0;for (i=1;i<=n;i++) v[i]=a[i]-a[i-1];
	for (i=1;i<=n;i++)
	{
		c+=v[i];
		if (c<W) cur+=W-c,v[min(i+L,n+1)]-=W-c,c=W;
		if (cur>m) return 0;
	} 
	return 1;
}
int main()
{
	file();
	int i;
	ll l=0,r=2e9,ans;
	read>>n>>m>>L;
	for (i=1;i<=n;i++) read>>a[i];
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (judge(mid)) l=(ans=mid)+1;
		else r=mid-1;
	}
	cout<<ans;
}