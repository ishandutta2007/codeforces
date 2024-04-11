#pragma GCC optimize(2)
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

int n,m;
bool f[(1<<19)];
int siz[(1<<20)+5],tag[(1<<20)+5],val[(1<<20)+5];
void dfs(int x,int l,int r){
	if(l==r){
		siz[x]=f[l];
		RE;
	}
	int mid=(l+r)>>1;
	dfs(lc,l,mid);
	dfs(rc,mid+1,r);
	siz[x]=siz[lc]+siz[rc];
}
void pushdown(int x){
	tag[lc]^=tag[x];
	tag[rc]^=tag[x];
	val[lc]^=tag[x];
	val[rc]^=tag[x];
	tag[x]=0;
}
int get(int x,int l,int r){
	if(l==r)RE l;
	int t=(r-l+1)>>1;
	pushdown(x);
	int mid=(l+r)>>1;
	if(val[x]&t){
		if(siz[rc]==t){
			RE get(lc,l,mid)+t;
		}else RE get(rc,mid+1,r)-t;
	}else{
		if(siz[lc]==t){
			RE get(rc,mid+1,r);
		}else RE get(lc,l,mid);
	}
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	cin>>n>>m;
	FOR(i,1,n){
		int x;
		cin>>x;f[x]=1;
	}
	dfs(1,0,(1<<19)-1);
	FOR(i,1,m){
		int x;
		cin>>x;
		tag[1]^=x;val[1]^=x;
		cout<<get(1,0,(1<<19)-1)<<'\n';
	}
	io.out();
	RE 0;
}