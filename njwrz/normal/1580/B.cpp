#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
const double eps=1e-6;
struct inout{
    static const int ibufl=1<<25;
    char in_buf[ibufl+5],out_buf[ibufl+5],*inf,*ouf;
    void init(){
        fread(in_buf,1,ibufl,stdin);
        inf=in_buf;
        ouf=out_buf;
    }
    inout& operator >>(int &a){
        int fh=1;
        while(!(isdigit(*inf)||*inf=='-'))++inf;
        if(*inf=='-')fh=-1,++inf;
        a=0;
        while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
        a*=fh;
        return *this;
    }
    inout& operator >>(char &a){
        while(*inf==' '||*inf=='\n')++inf;
        a=*inf;
        ++inf;
        return *this;
    }
    inout& operator >>(char *a){
        while(*inf==' '||*inf=='\n')++inf;
        while(!(*inf==' '||*inf=='\n')){*a=*inf;++inf;++a;}
        *a='\0';
        return *this;
    }
    inout& operator >>(double &a){
        int fh=1;
        double s;
        while(!(isdigit(*inf)||*inf=='-'))++inf;
        if(*inf=='-')fh=-1,++inf;
        a=0;
        while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
        if(*inf=='.'){
            s=0.1;
            ++inf;
            while(isdigit(*inf)){
                a+=s*(*inf-'0');
                ++inf;
                s*=0.1;
            }
        }
        a*=fh;
        return *this;
    }
    void writeint(int x){
        if(x/10)writeint(x/10);
        *ouf=x%10+'0';
        ++ouf;
    }
    inout& operator <<(int a){

        if(a<0){*ouf='-';++ouf;a=-a;}
        writeint(a);
        return *this;
    }
    static const int sz=2;
    inout& operator <<(char a){
        *ouf=a;++ouf;
        return *this;
    }
    inout& operator <<(char *a){
        while(*a){
            *ouf=*a;
            ++ouf;
            ++a;
        }
        return *this;
    }
    inout& operator <<(double a){
        if(a<-eps){*ouf='-';++ouf;a=-a;}
        writeint((int)a);
        a-=(int)a;
        *ouf='.';
        ++ouf;
        FOR(i,1,sz){
            a=a*10;
            *ouf=(int)a+'0';
            ++ouf;
            a-=(int)a;
        }
        return *this;
    }
    void out(){
        fwrite(out_buf,1,ouf-out_buf,stdout);
    }
};
inout io;
#define cin io
#define cout io

/*----------------------------------------------------------------------------------------------*/

int n,m,k,mod;
int C[105][105]; 
int dp[105][105][105],p[105];
inline void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
inline int dfs(int n,int m,int k){
	int &re=dp[n][m][k];
	if(re!=-1)RE re;
	if(!k&&n<m)RE re=p[n];
	if(n<m||n<k||k+m>n+1)RE re=0;
	if(m==1){
		if(k==1){
			RE re=p[n];
		}
		RE re=0;
	}
	re=0;
	FOR(i,1,n){
		FOR(j,0,k)if(dp[i-1][m-1][j]&&dp[n-i][m-1][k-j]){
			add(re,(0ll+((dp[i-1][m-1][j]==-1)?dfs(i-1,m-1,j):dp[i-1][m-1][j]))*
			((dp[n-i][m-1][k-j]==-1)?dfs(n-i,m-1,k-j):dp[n-i][m-1][k-j])%mod*C[n-1][i-1]%mod);
		}
	}
//	cout<<n<<' '<<m<<' '<<k<<' '<<re<<'\n';
	RE re;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	freopen("1.txt","r",stdin);
	io.init();
	cin>>n>>m>>k>>mod;
	p[0]=1;
	FOR(i,1,n)p[i]=1ll*p[i-1]*i%mod;
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=mod)C[i][j]-=mod;
		}
	}
	FILL(dp,-1);
	cout<<dfs(n,m,k);
	io.out();
	RE 0;
}