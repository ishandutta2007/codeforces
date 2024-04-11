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
char c[505][505];
int d[4][2]={
0,-1,
1,0,
-1,0,
0,1
};
V<P<int,int> > v[505][505];
int col[505][505];
int val[505][505];
void dfs(int x,int y){
	bool f[2]={};
	for(auto u:v[x][y]){
		if(col[u.F][u.S]!=-1){
			f[col[u.F][u.S]]=1;
		}
	}
	if(f[0]&&f[1]){
		puts("NO");exit(0);
	}
	col[x][y]=f[0];
	for(auto u:v[x][y])if(col[u.F][u.S]==-1){
		col[u.F][u.S]=!f[0];
		dfs(u.F,u.S);
	}
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c[i][j];
		}
	}
	rep(x,2,n){
		rep(y,2,m)if(c[x][y]!='.'){
			int cnt=0;
			rep(k,0,4){
				int tx=d[k][0]+x,ty=d[k][1]+y;
				cnt+=c[tx][ty]=='.';
			}
			if(cnt==1||cnt==3){
				puts("NO");RE 0;
			}
			if(cnt==2){
				P<int,int> p1=MP(0,0),p2=MP(0,0);
				rep(k,0,4){
					int tx=d[k][0]+x,ty=d[k][1]+y;
					if(c[tx][ty]=='.'){
						if(p1.F){
							p2=MP(tx,ty);
						}else p1=MP(tx,ty);
					}
				}
				v[p1.F][p1.S].PB(p2);
				v[p2.F][p2.S].PB(p1);
				val[x][y]=5;
			}else if(cnt==4){
				v[x-1][y].PB(MP(x,y-1));
				v[x][y-1].PB(MP(x-1,y));
				v[x][y+1].PB(MP(x+1,y));
				v[x+1][y].PB(MP(x,y+1));
				val[x][y]=10;
			}
		}
	}
	FILL(col,-1);
	FOR(i,1,n){
		FOR(j,1,m)if(col[i][j]==-1&&c[i][j]=='.'){
			dfs(i,j);
		}
	}
	cout<<"YES\n";
	FOR(i,1,n){
		FOR(j,1,m){
			if(col[i][j]!=-1){
				cout<<(col[i][j]?4:1)<<' ';
			}else cout<<val[i][j]<<' ';
		}
		cout<<'\n';
	}
	io.out();
	RE 0;
}