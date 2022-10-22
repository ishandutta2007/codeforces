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
//#define cout io

/*----------------------------------------------------------------------------------------------*/

int s,t;
int cnt=1;
int cost[1000005],to[1000005],nxt[1000005],st[1000005],flow[1000005];
void addedge(int fr,int t,int f,int w){
	++cnt;
	if(st[fr])nxt[cnt]=st[fr];
	st[fr]=cnt;
	flow[cnt]=f;
	cost[cnt]=w;
	to[cnt]=t;
}
const int N=6000;
void add(int fr,int t,int f,int w){
	assert(fr<N&&t<N);
	addedge(fr,t,f,w);
	addedge(t,fr,0,-w);
}
int edge[N],lst[N],h[N];
int d[N],maxi=2e9;
bool vis[N];
bool dijkstra(){
	rep(i,0,N)d[i]=maxi;
	FILL(vis,0);
	d[s]=0;
	priority_queue<P<int,int>,V<P<int,int> > ,greater<P<int,int> > > q;
	q.emplace(MP(0,s));
	while(!q.empty()){
		P<int,int> cur=q.top();
		q.pop();
		if(cur.F>d[cur.S])continue;       
		vis[cur.S]=1;
		if(cur.S==t)break;
		for(int now=st[cur.S];now;now=nxt[now]){
			int u=to[now];
			if(flow[now]>0&&d[u]>d[cur.S]+h[cur.S]-h[u]+cost[now]){
				d[u]=d[cur.S]+h[cur.S]-h[u]+cost[now];
				edge[u]=now;
				lst[u]=cur.S;
				q.emplace(MP(d[u],u));
			}
		} 
	}
	rep(i,0,N)if(d[i]<maxi)h[i]+=d[i];
	RE d[t]<maxi;
}
P<int,int> solve(){
	int maxflow=0,minicost=0;
	while(dijkstra()){
		int mi=1e9;
		for(int now=t;now!=s;now=lst[now])gmin(mi,flow[edge[now]]);
		for(int now=t;now!=s;now=lst[now])
			flow[edge[now]]-=mi,flow[edge[now]^1]+=mi;
		minicost+=mi*h[t];
		maxflow+=mi;
	}
	RE MP(maxflow,minicost);
}
int l[55],r[55],n; 
signed main(){
	io.init();
	int q;
	cin>>n>>q;
	FOR(i,1,n)l[i]=1,r[i]=n;
	FOR(i,1,q){
		int tl,tr,tap,num;
		cin>>tap>>tl>>tr>>num;
		if(tap==1){
			FOR(j,tl,tr)gmax(l[j],num);
		}else FOR(j,tl,tr)gmin(r[j],num);
	}
	FOR(i,1,n){
		if(l[i]>r[i]){
			cout<<-1;io.out();RE 0;
		}
	}
	s=0;
	FOR(i,1,n){
		FOR(j,1,n)add(s,(i-1)*n+j,1,2*j-1);
	}
	FOR(i,1,n){
		FOR(j,1,n){
			FOR(k,1,n)if(l[k]<=i&&r[k]>=i){
				add((i-1)*n+j,n*n+k,1,0);
			}
		}
	}
	t=n*n+n+1;
	FOR(i,1,n)add(n*n+i,t,1,0);
	P<int,int> ans=solve();
	cout<<ans.S<<'\n';
	io.out();
	RE 0;
}