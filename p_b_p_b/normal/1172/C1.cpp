#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define sz 66
    #define mod 998244353ll
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
    templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
    templ inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t=(f?-t:t);
    }
    template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
    char __sr[1<<21],__z[20];int __C=-1,__zz=0;
    inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
    inline void print(register int x)
    {
        if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
        while(__z[++__zz]=x%10+48,x/=10);
        while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
    }
    void file()
    {
        #ifdef NTFOrz
        freopen("a.in","r",stdin);
        #endif
    }
    inline void chktime()
    {
        #ifndef ONLINE_JUDGE
        cout<<(clock()-t)/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
int a[sz];
int w[sz];
ll sum1,sum2; // 2 like; 1 dislike

ll dp[sz][sz][sz];

ll work(int p)
{
	ll S1=sum1,S2=sum2;
	if (a[p]) S2-=w[p]; else S1-=w[p];
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	rep(i,0,m-1) rep(j,0,i) rep(k,0,i-j) if (dp[i][j][k])
	{
		ll sum=sum1+sum2,p1=S1,p2=S2,p3=w[p];
		ll W=dp[i][j][k];
		if (!a[p])
		{
			// j like, i-j dislike , k dislike
			sum=sum+j*2-i;
			p3-=k;
			p1=S1-(i-j-k);
			p2=S2+j;
			sum=inv(sum);
			(dp[i+1][j+1][k]+=W*sum%mod*p2%mod)%=mod;
			(dp[i+1][j][k]+=W*sum%mod*p1%mod)%=mod;
			(dp[i+1][j][k+1]+=W*sum%mod*p3%mod)%=mod;
		}
		else
		{
			//j dislike, i-j like , k like
			sum=sum-j*2+i;
			p3+=k;
			p1=S1-j;
			p2=S2+(i-j-k);
			sum=inv(sum);
			(dp[i+1][j+1][k]+=W*sum%mod*p1%mod)%=mod;
			(dp[i+1][j][k]+=W*sum%mod*p2%mod)%=mod;
			(dp[i+1][j][k+1]+=W*sum%mod*p3%mod)%=mod;
		}
	}
	ll ret=0;
	rep(i,0,m) rep(j,0,m-i) (ret+=dp[m][j][i]*(a[p]?w[p]+i:w[p]-i)%mod)%=mod;
	return ret;
}

int main()
{
    file();
	read(n,m);
	rep(i,1,n) read(a[i]);
	rep(i,1,n)
	{
		read(w[i]);
		if (!a[i]) sum1+=w[i];
		else sum2+=w[i];
	}
	rep(i,1,n) printf("%I64d\n",work(i));
	return 0;
}