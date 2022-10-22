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

int n,a[300005];
map<int,V<int> > mp;
P<int,int> q[300005];
P<int,int> q2[300005];
int len,len2,pos[300005];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	mp.clear();
	len=0;len2=0;
	int sum=0;
	q[++len]=MP(n+1,0);
	q2[++len2]=MP(n+1,0);pos[len2]=0;
	mp[0].PB(-n-1);
	int ans=0;
	for(int i=n;i>=1;i--){
		if(i&1)sum-=a[i];else sum+=a[i];
		V<int> &tv=mp[sum];
		if(i&1){
			while(len>1&&q[len].S<=sum)len--;
			int tp=lwb(pos+2,pos+len2+1,sum)-pos-1;
			int lim=min(q[len].F,q2[tp].F);
//			cout<<tp<<' '<<q2[tp].F<<'\n';
			ans+=tv.size()-(lwb(ALL(tv),-lim)-tv.begin());
			q[++len]=MP(i,sum);
		}else {
			while(len2>1&&q2[len2].S>=sum)len2--;
			q2[++len2]=MP(i,sum);pos[len2]=sum;
		}
		tv.PB(-i);
	}
	mp.clear();len=0;sum=0;len2=0;
	q[++len]=MP(n+1,0);
	q2[++len2]=MP(n+1,0);pos[len2]=0;
	mp[0].PB(-n-1);
	for(int i=n;i>=1;i--){
		if(i&1)sum+=a[i];else sum-=a[i];
		V<int> &tv=mp[sum];
		if(!(i&1)){
			while(len>1&&q[len].S<=sum)len--;
			int tp=lwb(pos+2,pos+len2+1,sum)-pos-1;
			int lim=min(q[len].F,q2[tp].F);
//			cout<<tp<<' '<<q2[tp].F<<'\n';
			ans+=tv.size()-(lwb(ALL(tv),-lim)-tv.begin());
			q[++len]=MP(i,sum);
		}else {
			while(len2>1&&q2[len2].S>=sum)len2--;
			q2[++len2]=MP(i,sum);pos[len2]=sum;
		}
		tv.PB(-i);
	}
	cout<<ans<<'\n';
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