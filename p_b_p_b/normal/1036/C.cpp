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
ll dp[23][5];
int bit[23];
ll dfs(int cur,int num,bool lim)
{
	if (num>3) return 0;
	if (!cur) return 1;
	if (!lim&&dp[cur][num]!=-1) return dp[cur][num];
	int end=lim?bit[cur]:9;
	ll ret=0;
	for (int i=0;i<=end;i++)
	{
		ret+=dfs(cur-1,num+(bool)i,lim&&i==end);
	}
	if (!lim) dp[cur][num]=ret;
	return ret;
}
ll solve(ll x)
{
	if (!x) return 1;
	int cnt=0;memset(bit,0,sizeof(bit));
	while (x) bit[++cnt]=x%10,x/=10;
	return dfs(cnt,0,1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	file();
	ll L,R,T;
	read>>T;
	while (T--)
	{
		read>>L>>R;
		printf("%lld\n",solve(R)-solve(L-1));
	}
}