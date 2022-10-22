#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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

/*----------------------------------------------------------------------------------------------*/

int L[300005],R[300005];
int cnt[300005],fa[300005],siz[300005];
bool down[300005],vis[300005];
int n,m,k;
int dp[300005];
int get(int x){
	RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
}
bool merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x==y)RE 0;
	fa[x]=y;siz[y]+=siz[x];
	down[y]|=down[x];
	RE 1;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	cin>>n>>m>>k;
	FOR(i,1,k)fa[i]=i,siz[i]=1;
	FOR(i,1,n){
		int len,x;
		cin>>len>>x;
		rep(j,1,len){
			int y;
			cin>>y;
			if(!R[x]){
				if(!merge(x,y)){
					down[x]=down[y]=1;
				}
			}
			merge(x,y);
			if(R[x]&&R[x]!=y){
				down[x]=1;
			}
			if(L[y]&&L[y]!=x){
				down[y]=1;
			}
			R[x]=y;
			L[y]=x;
			x=y;
		}
	}
	FOR(i,1,k)down[get(i)]|=down[i];
	FOR(i,1,k)if(!vis[fa[i]]&&!down[fa[i]]){
		cnt[siz[fa[i]]]++;vis[fa[i]]=1;
	}
	V<int> v;
	FOR(i,1,m)if(cnt[i]){
		v.PB(i);
	}
	dp[0]=1;
	int mod=998244353;
	FOR(i,1,m){
		for(auto u:v)if(u<=i){
			dp[i]=(1ll*dp[i-u]*cnt[u]+dp[i])%mod;
		}
	}
	cout<<dp[m];
	RE 0;
}