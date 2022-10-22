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

int dep[300005];
int n,vis[300005],fa[300005];
V<int> v[300005],g[300005];
int p[300005];
void dfs(int x){
	for(auto u:v[x])if(!vis[u]){
		g[u].PB(x);
		g[x].PB(u);dep[u]=dep[x]+1;fa[u]=x;
		vis[u]=1;
		dfs(u);
	}
}
int ansc=0;
void dfs2(int x){
	int f=0;
	for(auto u:g[x])if(u!=fa[x]){
		dfs2(u);
		if(f&&p[u])ansc++;
		f^=p[u];
	}
	if(f&&!p[x])ansc++;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int m;
	cin>>n>>m;
	FOR(i,1,m){
		int x,y;cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	vis[1]=1;
	dfs(1);
	int q;
	cin>>q;
	V<V<int> > ans;
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		V<int> now1,now2;
		while(dep[x]<dep[y]){
			now2.PB(y);p[y]^=1;
			y=fa[y];
		}
		while(dep[x]>dep[y]){
			now1.PB(x);p[x]^=1;
			x=fa[x];
		}
		while(x!=y){
			now1.PB(x);
			now2.PB(y);p[x]^=1;p[y]^=1;
			x=fa[x];y=fa[y];
		}
		now1.PB(x);
		reverse(ALL(now2));
		for(auto u:now2)now1.PB(u);
		ans.PB(now1);
	}
	bool ff=1;
	FOR(i,1,n){
		if(p[i]){
			ff=0;break;
		}
	}
	if(ff){
		cout<<"YES\n";
		for(auto vec:ans){
			cout<<(int)(vec.size())<<'\n';
			for(auto u:vec)cout<<u<<' ';
			cout<<'\n';
		}
		io.out();
		RE 0;
	}
	dfs2(1);
	cout<<"NO\n";
	cout<<ansc;
	io.out();
	RE 0;
}