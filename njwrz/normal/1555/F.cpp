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

int x[500005],y[500005],val[500005],n,q;
V<P<int,int> > v[300005];
int fa[300005][20],dfn[300005],top[300005],dep[300005],siz[300005],cnt,son[300005],w[300005];
void dfs(int now){
	siz[now]=1;
	for(auto u:v[now])if(u.F!=fa[now][0]){
		fa[u.F][0]=now;dep[u.F]=dep[now]+1;w[u.F]=w[now]^u.S;
		dfs(u.F);
		if(siz[u.F]>siz[son[now]])son[now]=u.F;
		siz[now]+=siz[u.F];
	}
}
void dfs2(int now,int tp){
	dfn[now]=++cnt;top[now]=tp;
	if(son[now])dfs2(son[now],tp);
	for(auto u:v[now])if(u.F!=son[now]&&u.F!=fa[now][0])dfs2(u.F,u.F);
}
int tap[500005];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	FOR(i,0,18)if(t&(1<<i))x=fa[x][i];
	if(x==y)RE x;
	for(int i=18;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	RE fa[x][0];
}
struct Bit{
	int a[300005];
	void clear(){
		FILL(a,0);
	}
	void update(int x,int y){
		while(x<=n){
			a[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=a[x];
			x-=x&-x;
		}
		RE re;
	}
}T1,T2;
int get(int now){
	RE T1.get(now)*now+T2.get(now);
}
int get(int l,int r){
	if(l>r)RE 0;
	RE get(r)-get(l-1);
}
void up(int l,int r){
	if(l>r)RE;
	T1.update(l,1);
	T1.update(r+1,-1);
	T2.update(l,-l+1);
	T2.update(r+1,r);
}
bool check(int fr,int to){
	while(dep[fr]>=dep[to]){
		if(dep[top[fr]]<=dep[to]){
//			cout<<"!!!"<<dfn[to]+1<<' '<<dfn[fr]<<' '<<get(dfn[to]+1,dfn[fr])<<' ';
			if(get(dfn[to]+1,dfn[fr]))RE 0;
			RE 1;
		}
		if(get(dfn[top[fr]],dfn[fr]))RE 0;
		fr=fa[top[fr]][0];
	}
	RE 1;
}
void update(int fr,int to){
	while(dep[fr]>=dep[to]){
		if(dep[top[fr]]<=dep[to]){
			up(dfn[to]+1,dfn[fr]);RE;
		}
		up(dfn[top[fr]],dfn[fr]);
		fr=fa[top[fr]][0];
	}
}
int F[300005];
int getfa(int x){
	RE (x==F[x])?x:(F[x]=getfa(F[x]));
} 
void merge(int x,int y){
	x=getfa(x);y=getfa(y);
	F[x]=y; 
}
signed main(){
	io.init();
	cin>>n>>q;
	FOR(i,1,n)F[i]=i;
	FOR(i,1,q){
		cin>>x[i]>>y[i]>>val[i];
		if(getfa(x[i])!=getfa(y[i])){
			merge(x[i],y[i]);
			v[x[i]].PB(MP(y[i],val[i]));
			v[y[i]].PB(MP(x[i],val[i]));
			tap[i]=1;
		}
	}
	FOR(i,1,n)if(!dfn[i])dfs(i),dfs2(i,i);
	FOR(i,1,18){
		FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	FOR(i,1,q){
		if(tap[i]){
			cout<<"YES\n";
		}else{
			int t=val[i]^w[x[i]]^w[y[i]];
//			cout<<t<<' ';
			if(t==1){
				int mid=lca(x[i],y[i]);
//				cout<<mid<<' '<<check(x[i],mid)<<' '<<check(y[i],mid)<<' ';
				if(check(x[i],mid)&&check(y[i],mid)){
					update(x[i],mid);update(y[i],mid);
					cout<<"YES\n";
				}else cout<<"NO\n";
			}else cout<<"NO\n";
		}
	}
	io.out();
	RE 0;
}