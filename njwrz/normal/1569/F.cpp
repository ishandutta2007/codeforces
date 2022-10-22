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

int num[15],n;
bool f[15][15];
int C[15],p[15][15],len[15];
P<int,P<int,int> > q[600000];
int t;
bool vis[1<<12][14][15];
int tot;
inline bool dfs2(int mask,int x,int y){
	q[++t]=MP(mask,MP(x,y));
	if(mask==(1<<n)-1)RE 1;
	FOR(i,1,tot){
		FOR(j,1,len[i])if(!(mask&(1<<p[i][j]))){
			FOR(K,j+1,len[i])if(!(mask&(1<<p[i][K]))){
				if(f[p[i][j]][x]&&f[p[i][K]][y]||f[p[i][j]][y]&&f[p[i][K]][x]){
					if(!vis[mask|(1<<p[i][j])|(1<<p[i][K])][p[i][j]][p[i][K]]){
						vis[mask|(1<<p[i][j])|(1<<p[i][K])][p[i][j]][p[i][K]]=1;
						if(dfs2(mask|(1<<p[i][j])|(1<<p[i][K]),p[i][j],p[i][K]))RE 1;
					}
				}
			}
		}
	}
	RE 0;
}
void dfs(int x,int used,int cnt){
	if(x+cnt>n)RE ;
	if(x==n){
		t=0;tot=used;
		FOR(i,1,used){
			FOR(j,1,len[i]){
				FOR(K,j+1,len[i])if(f[p[i][j]][p[i][K]]){
					vis[(1<<p[i][j])+(1<<p[i][K])][p[i][j]][p[i][K]]=1;
					if(dfs2((1<<p[i][j])+(1<<p[i][K]),p[i][j],p[i][K])){
						FOR(i,1,t)vis[q[i].F][q[i].S.F][q[i].S.S]=0;
						C[used]++;RE ;
					}
				}
			}
		}
		FOR(i,1,t)vis[q[i].F][q[i].S.F][q[i].S.S]=0;
		RE ;
	}
	FOR(i,1,used+1){
		num[i]++;p[i][++len[i]]=x;
		dfs(x+1,max(used,i),cnt+((num[i]&1)?1:(-1)));
		num[i]--;--len[i];
	}
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	freopen("F_in.txt","r",stdin);
	io.init();
	int m,k;
	cin>>n>>m>>k;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;x--;y--;
		f[x][y]=f[y][x]=1;
	}
	dfs(0,0,0);
	ll ans=0;
	FOR(i,1,k){
		ll p=1;
		for(int j=k;j>=k-i+1;j--)p*=j;
//		cout<<C[i]<<' ';
		ans+=C[i]*p;
	}
	printf("%lld",ans);
//	io.out();
	RE 0;
}