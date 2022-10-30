#pragma GCC optimize(2)
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
//#define cin io
//#define cout io

/*----------------------------------------------------------------------------------------------*/

int a[14],dp[1<<14],mod=1e9+7,num[1<<14],check[15000000],p3[14],ck[14][1<<14],inv[2000005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	io.init();
	int n;
	cin>>n;
	inv[1]=1;
	FOR(i,2,2000000){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	}
	rep(i,0,n)cin>>a[i];
	p3[0]=1;
	rep(i,1,n)p3[i]=p3[i-1]*3;
	rep(i,0,(1<<n)){
		rep(j,0,n)if(i&(1<<j))num[i]+=p3[j];
	}
	rep(i,0,n){
		rep(mask,0,1<<n)if(!(mask&(1<<i))){
			ck[i][mask]=1;
			rep(j,0,n)if(mask&(1<<j))ck[i][mask]=(ck[i][mask]*inv[a[i]+a[j]]%mod*a[j])%mod;
		}
	}
	rep(i,0,p3[n-1]*3)check[i]=1;
	rep(mask,0,1<<n){
		int t=((1<<n)-1)^mask,now=t;
		while(t){
			rep(i,0,n)if(mask&(1<<i)){
				(check[num[mask]+num[t]*2]*=ck[i][t])%=mod;
			}
			t=(t-1)&now;
		} 
	}
	int ans=0;
	rep(st,0,n){
		FILL(dp,0);
		rep(mask,1,1<<n)if(mask&(1<<st)){
			int t=(mask-1)&mask;
			dp[mask]=1;
			while(t){
				if(t&(1<<st)){
					dp[mask]=(dp[mask]-dp[t]*check[num[t]+2*num[mask^t]]%mod+mod)%mod;
				}
				t=(t-1)&mask;
			}
		}
		ans+=dp[(1<<n)-1];
	}
	cout<<ans%mod;
//	io.out();
	RE 0;
}