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

int n;
int a[sz][sz];

int ask(int x1,int y1,int x2,int y2){printf("? %d %d %d %d\n",x1,y1,x2,y2);fflush(stdout);int ret;read(ret);return ret;}
void Print(){puts("!");rep(i,1,n) { rep(j,1,n) printf("%d",a[i][j]); puts(""); } fflush(stdout); exit(0); }
void End(int x,int y,int w){w^=a[x][y];rep(i,1,n) rep(j,1,n) if ((i+j)&1) a[i][j]^=w;Print();}

int main()
{
//    file();
	read(n);
	a[1][1]=1;a[n][n]=0;
	a[1][2]=0;a[2][3]=ask(1,2,2,3)^1;a[2][1]=ask(2,1,2,3)^a[2][3]^1;a[3][2]=ask(1,2,3,2)^1;
	rep(i,1,n) rep(j,1,n) if (i+j!=2)
	{
		if (((i+j)&1)&&max(i,j)<=3) continue;
		if (i==1) a[1][j]=a[1][j-2]^ask(1,j-2,1,j)^1;
		else if (j==1) a[i][1]=a[i-2][1]^ask(i-2,1,i,1)^1;
		else a[i][j]=a[i-1][j-1]^ask(i-1,j-1,i,j)^1;
	}
	rep(i,1,n-2) if (a[i][i]&&!a[i+2][i+2])
	{
		if (a[i][i+2])
		{
			if (a[i][i+1]==a[i+1][i+2])
			{
				if (ask(i,i,i+1,i+2)) End(i+1,i+2,1);
				else End(i+1,i+2,0);
			}
			else
			{
				if (ask(i,i+1,i+2,i+2)) End(i,i+1,0);
				else End(i,i+1,1);
			}
		}
		else
		{
			if (a[i][i+1]==a[i+1][i+2])
			{
				End(i,i+1,ask(i,i+1,i+2,i+2)^1);
			}
			else
			{
				End(i+1,i+2,ask(i,i,i+1,i+2));
			}
		}
	}
	puts("WRONG!!!");
	return 0;
}