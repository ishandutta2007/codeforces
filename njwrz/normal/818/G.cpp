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
int cost[100005],to[100005],nxt[100005],st[100005],flow[100005];
void addedge(int fr,int t,int f,int w){
	++cnt;
	if(st[fr])nxt[cnt]=st[fr];
	st[fr]=cnt;
	flow[cnt]=f;
	cost[cnt]=w;
	to[cnt]=t;
}
void add(int fr,int t,int f,int w){
	addedge(fr,t,f,w);
	addedge(t,fr,0,-w);
}
const int N=12015;
int edge[N],lst[N],d[N],maxi=2e9;
bool inq[N];
bool spfa(){
	rep(i,0,N)d[i]=maxi;
	d[s]=0;
	queue<int> q;
	q.emplace(s);inq[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int now=st[x];now;now=nxt[now]){
			if(flow[now]&&d[to[now]]>d[x]+cost[now]){
				d[to[now]]=d[x]+cost[now];
				lst[to[now]]=x;
				edge[to[now]]=now;
				if(!inq[to[now]])inq[to[now]]=1,q.emplace(to[now]);
			}
		}
	}
	RE d[t]<maxi;
}
P<int,int> solve(){
	int maxflow=0,minicost=0;
	while(spfa()){
		int mi=1e9;
		for(int now=t;now!=s;now=lst[now])gmin(mi,flow[edge[now]]);
		for(int now=t;now!=s;now=lst[now])
			flow[edge[now]]-=mi,flow[edge[now]^1]+=mi;
		minicost+=mi*d[t];
		maxflow+=mi;
	}
	RE MP(maxflow,minicost);
}
int n,a[3005],pp[10],L[100005];
signed main(){
	io.init();
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	s=4*n+1;t=4*n+2;
	add(s,n*4+3,4,0);
	FOR(i,1,n){
		if(pp[a[i]%7]){
			add(pp[a[i]%7],i,4,0);
			add(pp[a[i]%7],i+2*n,1,-1);
		}
		pp[a[i]%7]=i;
		if(L[a[i]]){
			add(L[a[i]]+n,i+n,4,0);
		}
		if(L[a[i]-1])add(L[a[i]-1]+n,i+2*n,1,-1);
		if(L[a[i]+1])add(L[a[i]+1]+n,i+2*n,1,-1);
		L[a[i]]=i;
		add(i+2*n,i+3*n,1,0);
		add(i+3*n,i,1,0);add(i+3*n,i+n,1,0);
		add(i+3*n,t,1,0);add(n*4+3,i+n*2,1,-1);
	}
	cout<<-solve().S;
	io.out();
	RE 0;
}