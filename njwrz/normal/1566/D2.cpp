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

int p[305][305];
V<P<int,int> > v[305*305];
int col[305*305];
P<int,int> it[305][305];
bool f[305][305];
void solve(){
	int n,m;
	cin>>n>>m;
	V<int> g;
	FOR(i,1,n){
		FOR(j,1,m){
			v[i].clear();
			cin>>p[i][j];
			g.PB(p[i][j]);
		}
	}
	sort(ALL(g));
	g.erase(unique(ALL(g)),g.end());
	V<P<int,int> > pos;
	FOR(i,1,n){
		FOR(j,1,m){
			p[i][j]=lwb(ALL(g),p[i][j])-g.begin()+1;
			v[p[i][j]].PB(MP(i,j));
			col[(i-1)*m+j]=p[i][j];
		}
	}
//	RE;
	int l=1;
	sort(col+1,col+n*m+1);
	int iter=0;
	col[n*m+1]=0;
	FOR(i,1,n*m){
		if(col[i]!=col[i+1]){
			V<int> len;
			FOR(j,l,i){
				if(j%m==1||j==l){
					len.PB(1);
				}else len.back()++;
			}
			int now=col[i];
			sort(ALL(v[now]));
			reverse(ALL(v[now]));
			for(auto u:len){
				V<P<int,int> > nv;
				FOR(_,1,u){
					nv.PB(v[now].back());
					v[now].pop_back();
				}
				FOR(_,1,u){
					iter++;
					it[nv.back().F][nv.back().S]=MP((iter-1)/m+1,(iter-1)%m+1);
					nv.pop_back();
				}
			}
			l=i+1;
		}
	}
	FOR(i,1,n){
		FOR(j,1,m)f[i][j]=0;
	}
	int ans=0;
	FOR(i,1,n*m){
		P<int,int> np=MP((i-1)/m+1,(i-1)%m+1);
		P<int,int> to=it[np.F][np.S];
		FOR(j,1,to.S){
			ans+=f[to.F][j];
		}
		f[to.F][to.S]=1;
	}
	cout<<ans<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int t;
	cin>>t;
	while(t--)solve();
	io.out();
	RE 0;
}