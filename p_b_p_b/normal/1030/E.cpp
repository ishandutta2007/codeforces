#include<bits/stdc++.h>
#define sz 301010
#define mod 2147483648ll
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
int cnt[sz];
int sum[sz];
int n;
int count(ll x)
{
	int ret=0;
	while (x) ret++,x-=(x&(-x));
	return ret;
}
int main()
{
	file();
	int i,j;
	ll z;
	read>>n;
	for (i=1;i<=n;i++) read>>z,sum[i]=sum[i-1]+(cnt[i]=__builtin_popcountll(z));
	ll ans=0,odd=0,even=1;
	for (i=1;i<=n;i++) 
		if (sum[i]&1) ans+=odd,odd++;
		else ans+=even,even++;
	for (i=1;i<=n;i++)
	{
		int mx=0;
		for (j=i;i-j<=66&&j;j--)
		{
			mx=max(mx,cnt[j]);
			if (mx>sum[i]-sum[j-1]-mx&&((sum[i]-sum[j-1])&1)==0) --ans;
		}
	}
	cout<<ans;
}