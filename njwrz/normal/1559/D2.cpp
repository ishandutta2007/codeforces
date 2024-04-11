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

int n;
struct dsu{
	int fa[100005];
	void init(int n){
		FOR(i,1,n)fa[i]=i;
	}
	int getfa(int x){
		if(x==fa[x])RE x;
		else RE fa[x]=getfa(fa[x]);
	}
	void merge(int x,int y){
		x=getfa(x);
		y=getfa(y);
		fa[x]=y;
	}
}g1,g2;
bool vis1[100005],vis2[100005];
signed main(){
	io.init();
	int m1,m2;
	cin>>n>>m1>>m2;
	g1.init(n);
	g2.init(n);
	FOR(i,1,m1){
		int x,y;
		cin>>x>>y;
		g1.merge(x,y);
	} 
	FOR(i,1,m2){
		int x,y;
		cin>>x>>y;
		g2.merge(x,y);
	} 
	V<P<int,int> > ans;
	V<int> v1,v2;
	FOR(i,1,n){
		if(g1.getfa(i)!=g1.getfa(1)&&g2.getfa(i)!=g2.getfa(1))ans.PB(MP(1,i)),g1.merge(1,i),g2.merge(1,i);
	}
	FOR(i,1,n){
		if(!vis2[g1.getfa(i)]&&g1.getfa(i)!=g1.getfa(1)&&g2.getfa(i)==g2.getfa(1))v2.PB(i),vis2[g1.getfa(i)]=1;
		if(!vis1[g2.getfa(i)]&&g1.getfa(i)==g1.getfa(1)&&g2.getfa(i)!=g2.getfa(1))v1.PB(i),vis1[g2.getfa(i)]=1;
	}
	if(!v1.empty()){
		int t=min(v1.size(),v2.size());
		rep(i,0,t){
			ans.PB(MP(v1[i],v2[i]));
		}
	}
	cout<<(int)ans.size()<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
	io.out();
	RE 0;
}