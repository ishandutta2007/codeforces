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

int n,cnt;
int f[400005],finv[400005],inv[400005],mod=998244353;
int C(int x,int y){
	RE f[x]*finv[x-y]%mod*finv[y]%mod;
}
int a[200005];
int N=200000;
void add(int x,int y){
	while(x<=N){
		a[x]+=y;
		x+=x&-x;
	}
}
int p[200005];
int get(int x){
	int re=0;
	for(int i=17;i>=0;i--){
		if(re+(1<<i)<=N&&x>=a[re+(1<<i)]){
			x-=a[re+(1<<i)];
			re+=(1<<i);
		}
	}
	RE re+1;
}
void solve(){
	int n,m;
	V<int> ans,era;
	cin>>n>>m;
	int fuckvkcup;
	FOR(i,1,m){
		cin>>fuckvkcup>>p[i];
	}
	for(int i=m;i>=1;i--){
		int t1=get(p[i]+1),t2=get(p[i]);
		era.PB(t2);
		ans.PB(t1);
		add(t2,-1);
	}
	for(auto u:era)add(u,1);
	sort(ALL(ans));ans.erase(unique(ALL(ans)),ans.end());
	cout<<C(n+n-1-ans.size(),n)<<'\n';
}
signed main(){
	srand(time(0));
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	f[0]=f[1]=finv[0]=finv[1]=inv[1]=1;
	FOR(i,2,400000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int T;
	cin>>T;
	FOR(i,1,200000)add(i,1);
	while(T--)solve(); 
	io.out();
	RE 0;
}