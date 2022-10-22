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
#define cin io
#define cout io

/*----------------------------------------------------------------------------------------------*/

int dp[200005],n,m;
P<int,int> p[200005];
int a[200005];
int l[200005],r[200005];
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	a[0]=-2e9;a[n+1]=2e9;
	sort(a+1,a+n+1);
	FOR(i,1,m){
		cin>>p[i].F>>p[i].S;
		if((*lwb(a+1,a+n+1,p[i].F))<=p[i].S)i--,m--;
	}
	sort(p+1,p+m+1);
	reverse(p+1,p+m+1);
	int nowm=0,mini=2e9;
	FOR(i,1,m){
		if(p[i].S>=mini){
			
		}else{
			mini=p[i].S;
			p[++nowm]=p[i];
		}
	}
	m=nowm;
	sort(p+1,p+m+1);
	int pos=1;
	FOR(i,1,n+1){
		l[i-1]=pos;
		while(pos<=m&&p[pos].S<a[i]){
//			cout<<p[pos].F<<' '<<p[pos].S<<'\n';
			pos++;
		}
		r[i-1]=pos-1;
//		cout<<'\n';
	}
	FOR(i,1,m)dp[i]=1e18;
	FOR(i,1,n){
		int dp0=1e18,dp1=1e18;
		FOR(j,l[i-1]-1,r[i-1]){
			gmin(dp0,dp[j]+(j==r[i-1]?0:(a[i]-p[j+1].S)));
			gmin(dp1,dp[j]+2*(j==r[i-1]?0:(a[i]-p[j+1].S)));
			gmin(dp[j],dp0);
		}
//		cout<<dp0<<' '<<dp1<<'\n';
		FOR(j,l[i],r[i]){
			gmin(dp[j],dp0+(p[j].F-a[i])*2);
			gmin(dp[j],dp1+(p[j].F-a[i]));
		}
	}
	cout<<dp[m]<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int t;
	cin>>t;
	while(t--)solve();
	io.out();
	RE 0;
}