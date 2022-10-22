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

V<P<int,int> > v[300005];
int n,m;
int l[300005],r[300005],h[300005];
P<int,int> tag[1<<21],maxi[1<<21];
void pushdown(int x){
	gmax(maxi[lc],tag[x]);
	gmax(maxi[rc],tag[x]);
	gmax(tag[lc],tag[x]);
	gmax(tag[rc],tag[x]);
}
void update(int x,int l,int r,int tl,int tr,P<int,int> val){
	if(l>=tl&&r<=tr){
		gmax(tag[x],val);
		gmax(maxi[x],val);
		RE;
	}
	if(l>tr||tl>r)RE;
	pushdown(x);
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,val);
	update(rc,mid+1,r,tl,tr,val);
	maxi[x]=max(maxi[lc],maxi[rc]);
}
P<int,int> get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE maxi[x];
	if(l>tr||tl>r)RE MP(0,0);
	pushdown(x);
	int mid=(l+r)>>1;
	RE max(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
int lst[300005];
bool used[300005];
signed main(){
	io.init();
	cin>>n>>m;
	V<int> g;
	FOR(i,1,m)cin>>h[i]>>l[i]>>r[i],g.PB(l[i]),g.PB(r[i]);
	sort(ALL(g));
	g.erase(unique(ALL(g)),g.end());
	FOR(i,1,m){
		l[i]=lwb(ALL(g),l[i])-g.begin()+1;
		r[i]=lwb(ALL(g),r[i])-g.begin()+1;
		v[h[i]].PB(MP(l[i],r[i]));
	}
	int len=g.size();
	int ans=n,x=0;
	FOR(i,1,n)if(!v[i].empty()){
		P<int,int> fr=MP(0,0);
		for(auto u:v[i])gmax(fr,get(1,1,len,u.F,u.S));
		fr.F++;
		lst[i]=fr.S;
		fr.S=i;
		for(auto u:v[i])update(1,1,len,u.F,u.S,fr);
		if(n-fr.F<ans){
			ans=n-fr.F;
			x=i;
		}
	}
	V<int> av;
	while(x){
		used[x]=1;
		x=lst[x];
	}
	FOR(i,1,n)if(!used[i])av.PB(i);
	cout<<(int)av.size()<<'\n';
	for(auto u:av)cout<<u<<' ';
	io.out();
	RE 0;
}