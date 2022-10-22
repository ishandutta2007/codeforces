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

/*----------------------------------------------------------------------------------------------*/

V<int> v[1000005];
int n,a[1000005],f[1000005],p[1000005];
P<int,int> st[1000005];
int it[1000005];
int len=0;
char c[1000005];
signed main(){
	io.init();
	cin>>n;
	int maxi=0;
	FOR(i,1,n)cin>>a[i],v[a[i]].PB(i),gmax(maxi,a[i]);
	FOR(i,1,n){
		it[i]=n;
		cin>>c[i];
		if(a[i]==1)c[i]='*';
	}
	FOR(i,2,maxi)if(!f[i]){
		int cnt=0;
		for(int j=i;j<=maxi;j+=i){
			f[j]=1;
			if(!v[j].empty()){
				for(auto u:v[j])p[++cnt]=u;
			}
		}
		if(!cnt)continue;
		sort(p+1,p+cnt+1);
//		FOR(j,1,cnt)cout<<p[j]<<' ';
//		cout<<'\n';
		len=0;
		st[++len]=MP(0,0);
		p[cnt+1]=n+1;
		int sum=0;
		FOR(j,1,cnt){
			int now=0;
			ll t=a[p[j]];
			while(t%i==0)t/=i,now++;
			if(c[p[j]]=='/')now=-now;
			sum+=now;
			if(now<0)gmin(it[p[j]],p[j-1]+1);
			while(len&&st[len].S>sum){
				gmin(it[p[j]],p[st[len].F]+1);
				len--;
			}
			st[++len]=MP(j,sum);
		}
	}
	ll ans=0;
	len=0;
//	cout<<"-------------------------------------------------\n";
//	FOR(i,1,n)cout<<it[i]<<' ';
//	cout<<"\n\n";
	for(int i=n;i>=1;i--){
		while(len&&st[len].F>i)len--;
		if(i&&c[i]!='/'){
			if(len){
				ans+=max(0,st[len].S-i+1);
			}else ans+=n-i+1;
//			cout<<i<<' '<<ans<<'\n';
		} 
		if(it[i]==n)continue;
		while(len&&st[len].F>=it[i])len--;
//		cout<<i<<' '<<it[i]<<' '<<i-1<<'\n';
		st[++len]=MP(it[i],i-1);
	}
	cout<<ans;
	RE 0;
}