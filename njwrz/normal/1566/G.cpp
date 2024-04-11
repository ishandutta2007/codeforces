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

multiset<P<int,int> > e[100005],p[100005];
int n;
map<P<int,int> ,int> mp;
set<P<int,int> > s;
int get(int x){
	int re=0;
	for(auto u:p[x])re+=u.F;
	RE re;
}
P<int,int> C(P<int,int> x){
	if(x.F>x.S){
		swap(x.F,x.S);
	}
	RE x;
}
set<P<int,P<int,int> > > edge;
void solve(int x){
	if(e[x].size()>=3){
		auto u=e[x].begin();
		p[x].clear();
		FOR(_,1,3){
			p[x].emplace(*u);u++;
		}
		s.emplace(MP(get(x),x));
	}else p[x]=e[x];
}
void add(int x,int y,int w){
	if(x>y)swap(x,y);
	for(auto u:p[x])edge.erase(MP(u.F,C(MP(x,u.S))));
	for(auto u:p[y])edge.erase(MP(u.F,C(MP(u.S,y))));
	mp[MP(x,y)]=w;
	if(p[x].size()==3)s.erase(MP(get(x),x));
	if(p[y].size()==3)s.erase(MP(get(y),y));
	e[x].emplace(MP(w,y));
	e[y].emplace(MP(w,x));
	solve(x);
	solve(y);
	for(auto u:p[x])if(p[u.S].count(MP(u.F,x)))edge.emplace(MP(u.F,C(MP(x,u.S))));
	for(auto u:p[y])if(p[u.S].count(MP(u.F,y)))edge.emplace(MP(u.F,C(MP(y,u.S))));
}
void erase(int x,int y){
	if(x>y)swap(x,y);
	int w=mp[MP(x,y)];
	for(auto u:p[x])edge.erase(MP(u.F,C(MP(x,u.S))));
	for(auto u:p[y])edge.erase(MP(u.F,C(MP(u.S,y))));
	if(p[x].size()==3)s.erase(MP(get(x),x));
	if(p[y].size()==3)s.erase(MP(get(y),y));
	e[x].erase(e[x].lwb(MP(w,y)));
	e[y].erase(e[y].lwb(MP(w,x)));
	solve(x);
	solve(y);
	for(auto u:p[x])if(p[u.S].count(MP(u.F,x)))edge.emplace(MP(u.F,C(MP(x,u.S))));
	for(auto u:p[y])if(p[u.S].count(MP(u.F,y)))edge.emplace(MP(u.F,C(MP(y,u.S))));
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int n,m;
	cin>>n>>m;
	FOR(i,1,m){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
	}
	int q;
	cin>>q;
	FOR(i,0,q){
		if(i){
			int tap;
			cin>>tap;
			if(tap){
				int x,y,w;
				cin>>x>>y>>w;
				add(x,y,w);
			}else {
				int x,y;
				cin>>x>>y;
				erase(x,y);
			}
		}
		int ans=1e18;
		if(!s.empty())ans=(*s.begin()).F;
		auto u=edge.begin();
		int n1=(*u).S.F,n2=(*u).S.S,val=(*u).F;
		for(auto u1:p[n1]){
			for(auto u2:p[n2]){
				if(u1.S!=n2&&u2.S!=n1&&u1.S!=u2.S){
					gmin(ans,u1.F+u2.F);
				}
			}
		}
		u++;
		int siz=2;
		while(siz<=edge.size()){
			if(siz>10)break;
			if((*u).S.F!=n1&&(*u).S.S!=n2&&(*u).S.F!=n2&&(*u).S.S!=n1){
				gmin(ans,val+(*u).F);break;
			}
			u++;
			siz++;
		}
		cout<<ans<<'\n';
	}
	io.out();
	RE 0;
}