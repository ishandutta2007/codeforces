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

/*----------------------------------------------------------------------------------------------*/

P<P<int,int>,int> p[200005];
int n;
bool check(P<int,int> x,P<int,int> y,P<int,int> z){
	RE (x.F-y.F)*(x.S-z.S)==(x.F-z.F)*(x.S-y.S);
}
double dist(P<int,int> x,P<int,int> y){
	RE sqrt(0.0+(x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S));
}
signed main(){
	io.init();
	int k;
	cin>>n>>k;
	FOR(i,1,n)cin>>p[i].F.F>>p[i].F.S,p[i].S=i;
	if(check(p[1].F,p[2].F,p[3].F)){
		FOR(i,4,n){
			if(!check(p[1].F,p[2].F,p[i].F)){
				swap(p[i],p[1]);break;
			}
		}
	}else if(n>3){
		if(check(p[1].F,p[3].F,p[4].F)){
			swap(p[2],p[1]);
		}else if(check(p[1].F,p[2].F,p[4].F)){
			swap(p[3],p[1]);
		}
	}
	sort(p+2,p+n+1);
//	FOR(i,1,n)cout<<p[i].F.F<<' '<<p[i].F.S<<' '<<p[i].S<<'\n';
	if(p[1].S==k){
		printf("%.10f",min(dist(p[1].F,p[2].F),dist(p[1].F,p[n].F))+dist(p[2].F,p[n].F));
		RE 0;
	}
	int it=-1;
	FOR(i,2,n)if(p[i].S==k)it=i;
	double ans=dist(p[it].F,p[1].F)+min(dist(p[1].F,p[2].F),dist(p[1].F,p[n].F))+dist(p[2].F,p[n].F);
	gmin(ans,min(dist(p[it].F,p[2].F)+dist(p[n].F,p[1].F),dist(p[it].F,p[n].F)+dist(p[2].F,p[1].F))+dist(p[2].F,p[n].F));
	rep(i,2,n){
		gmin(ans,dist(p[it].F,p[2].F)+dist(p[2].F,p[i].F)+dist(p[i].F,p[1].F)+dist(p[1].F,p[i+1].F)+dist(p[i+1].F,p[n].F));
		gmin(ans,dist(p[it].F,p[n].F)+dist(p[n].F,p[i+1].F)+dist(p[i+1].F,p[1].F)+dist(p[1].F,p[i].F)+dist(p[i].F,p[2].F));
		gmin(ans,dist(p[it].F,p[i].F)+dist(p[2].F,p[i].F)+dist(p[2].F,p[1].F)+dist(p[1].F,p[i+1].F)+dist(p[i+1].F,p[n].F));
		gmin(ans,dist(p[it].F,p[i+1].F)+dist(p[n].F,p[i+1].F)+dist(p[n].F,p[1].F)+dist(p[1].F,p[i].F)+dist(p[i].F,p[2].F));
	}
	if(it>2){
		gmin(ans,dist(p[it].F,p[n].F)+dist(p[n].F,p[1].F)+dist(p[1].F,p[it-1].F)+dist(p[it-1].F,p[2].F));
		gmin(ans,dist(p[it].F,p[n].F)+dist(p[n].F,p[1].F)+dist(p[1].F,p[2].F)+dist(p[it-1].F,p[2].F));
	}else{
		gmin(ans,dist(p[it].F,p[n].F)+dist(p[n].F,p[1].F));
		gmin(ans,dist(p[it].F,p[n].F)+dist(p[n].F,p[1].F));
	}
	if(it<n){
		gmin(ans,dist(p[it].F,p[2].F)+dist(p[2].F,p[1].F)+dist(p[1].F,p[it+1].F)+dist(p[it+1].F,p[n].F));
		gmin(ans,dist(p[it].F,p[2].F)+dist(p[2].F,p[1].F)+dist(p[1].F,p[n].F)+dist(p[it+1].F,p[n].F));
	}else{
		gmin(ans,dist(p[it].F,p[2].F)+dist(p[2].F,p[1].F));
		gmin(ans,dist(p[it].F,p[2].F)+dist(p[2].F,p[1].F));
	}
	printf("%.10f",ans);
	RE 0;
}