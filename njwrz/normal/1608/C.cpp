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
#define cout io

/*----------------------------------------------------------------------------------------------*/

V<int> g[300005];
int dfn[300005],low[300005],n,cnt;
int a[300005],b[300005],col[300005],cntcol;
int len,q[300005];
bool in[300005];
void dfs(int x){
	dfn[x]=low[x]=++cnt;
	in[x]=1;
	q[++len]=x;
	for(auto u:g[x]){
		if(!dfn[u]){
			dfs(u);
			gmin(low[x],low[u]);
		}else{
			if(in[u])gmin(low[x],dfn[u]);
		}
	}
	if(low[x]==dfn[x]){
		++cntcol;
		while(q[len]!=x){
			in[q[len]]=0;
			col[q[len]]=cntcol;
			len--;
		}
		in[q[len]]=0;
		col[q[len]]=cntcol;
		len--;
	}
}
void solve(){
	int n;cnt=0;cntcol=0;
	cin>>n;
	V<int> v;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]);
	FOR(i,1,n)cin>>b[i];
	sort(ALL(v));
	FOR(i,1,n)a[i]=lwb(ALL(v),a[i])-v.begin()+1;
	v.clear();
	FOR(i,1,n)v.PB(b[i]);
	sort(ALL(v));
	FOR(i,1,n)b[i]=lwb(ALL(v),b[i])-v.begin()+1;
	FOR(i,1,3*n)g[i].clear();
	for(int i=n*2;i>n+1;i--){
		g[i].PB(i-1);
	}
	for(int i=n*3;i>2*n+1;i--){
		g[i].PB(i-1);
	}
	FOR(i,1,n){
		g[i].PB(a[i]+n);
		g[a[i]+n].PB(i);
		g[i].PB(b[i]+2*n);
		g[b[i]+2*n].PB(i);
	}
	FOR(i,1,n*3)dfn[i]=low[i]=0;
	FOR(i,1,n)if(!dfn[i]){
		dfs(i);
	}
	FOR(i,1,n){
		if(col[i]==cntcol){
			cout<<1;
		}else cout<<0;
	}
	cout<<'\n';
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