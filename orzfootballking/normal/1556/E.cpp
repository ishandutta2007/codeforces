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

int n,q,a[100005],b[100005],l2[100005][20],p[100005],p2[100005],l1[100005][20];
int get1(int l,int r){
	int t=p2[r-l+1];
	RE min(l2[l][t],l2[r-(1<<t)+1][t]);
}int get2(int l,int r){
	int t=p2[r-l+1];
	RE max(l1[l][t],l1[r-(1<<t)+1][t]);
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	FOR(i,2,100000)p2[i]=p2[i/2]+1;
	io.init();
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i],a[i]=b[i]-a[i];
	FOR(i,1,n)p[i]=p[i-1]+a[i],l2[i][0]=l1[i][0]=p[i];
	rep(i,1,19){
		FOR(j,1,n-(1<<i)+1){
			l2[j][i]=min(l2[j][i-1],l2[j+(1<<(i-1))][i-1]);
			l1[j][i]=max(l1[j][i-1],l1[j+(1<<(i-1))][i-1]);
		}
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		if(get1(l,r)<p[l-1]||p[r]!=p[l-1]){
			cout<<-1ll<<'\n';continue;
		}
		cout<<get2(l,r)-p[l-1]<<'\n';
	}
	io.out();
	RE 0;
}