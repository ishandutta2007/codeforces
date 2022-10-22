#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
#define y1 yyyy1111
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

char c1[2005],c2[2005];
int sum[2005][2005],dp[2005][2005],dp2[2005][2005],sum2[2005][2005];
int n,mod=1e9+7;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
void solve(){
	cin>>n;
	FOR(i,1,n){
		cin>>c1[i];
		if(i&1){
			if(c1[i]!='?')c1[i]='1'+'0'-c1[i];
		}
	}
	FOR(i,1,n){
		cin>>c2[i];
		if(i&1){
			if(c2[i]!='?')c2[i]='1'+'0'-c2[i];
		}
	}
	FOR(i,0,n){
		FOR(j,0,n){
			if(!i&&!j){
				dp[0][0]=1;sum[0][0]=1;
				dp2[0][0]=0;sum2[0][0]=0;
				continue;
			}
			dp[i][j]=sum[i][j]=dp2[i][j]=sum2[i][j]=0;
			if(i&&c1[i]!='1')sum[i][j]=sum[i-1][j],sum2[i][j]=sum2[i-1][j];
			if(j&&c2[j]!='1')add(sum[i][j],sum[i][j-1]),add(sum2[i][j],sum2[i][j-1]);
			if(i&&j&&c1[i]!='1'&&c2[j]!='1'){
				add(sum[i][j],mod-sum[i-1][j-1]);
				add(sum2[i][j],mod-sum2[i-1][j-1]);
			}
			if(i&&j&&c1[i]!='0'&&c2[j]!='0'){
				add(dp[i][j],sum[i-1][j-1]);
				add(dp2[i][j],sum2[i-1][j-1]);
				add(dp2[i][j],dp[i][j]*(abs(i-j))%mod);
			}
			add(sum[i][j],dp[i][j]);
			add(sum2[i][j],dp2[i][j]);
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp2[i][j]<<'\n';
		}
	}
	cout<<sum2[n][n]<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int T;
	cin>>T;
	while(T--)solve();
	io.out();
	RE 0;
}