#include<bits/stdc++.h>
#define sz 1000020
#define mod 998244353
using namespace std;
typedef long long ll;
struct FastIO{
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
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
ll sum[20][1111][2];
ll dp[20][1111][2];
int bit[20];
ll pow10[20];
int K;
#define pll pair<ll,ll> 
#define fir first
#define sec second
#define MP make_pair
pll dfs(int cur,int mask,bool zero,bool lim)
{
	if (__builtin_popcount(mask)>K) return MP(0ll,0ll);
	if (!cur) return MP(0ll,dp[cur][mask][zero]=!zero);
	if (!lim&&sum[cur][mask][zero]!=-1) return MP(sum[cur][mask][zero],dp[cur][mask][zero]);
	int End=lim?bit[cur]:9;
	ll ret=0,cnt=0,x,y;pll X;
	for (int i=0;i<=End;i++)
	{
		if (!i) X=dfs(cur-1,zero?0:(mask|1),zero,lim&&i==End);
		else X=dfs(cur-1,mask|(1<<i),0,lim&&i==End);
		x=X.fir;y=X.sec;
		(cnt+=y)%=mod;(ret+=x+y*i%mod*pow10[cur]%mod)%=mod;
	}
	if (!lim) { dp[cur][mask][zero]=cnt; sum[cur][mask][zero]=ret; }
	return MP(ret,cnt);
}
ll solve(ll x)
{
	int cnt=0;ll xx=x;
	while (xx) ++cnt,xx/=10;
	for (int i=1;i<=cnt;x/=10,i++) bit[i]=x%10;
	return dfs(cnt,0,1,1).fir;
}
int main()
{
	file();
	memset(dp,-1,sizeof(dp));memset(sum,-1,sizeof(sum));
	int i,x,y;
	pow10[1]=1;
	for (i=2;i<20;i++) pow10[i]=(pow10[i-1]*10ll)%mod;
	ll L,R;
	read>>L>>R>>K;
	x=solve(R);y=solve(L-1);
	cout<<(x-y+mod)%mod;
}