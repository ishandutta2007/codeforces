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
#define cout io

/*----------------------------------------------------------------------------------------------*/

int n,m,k;
map<P<int,int>,int> mp;
int fboth[2];
int cnt1,col1[1000005][2];
int ok1;
int cnt2,col2[1000005][2];
int ok2;
int pow2[1000005],mod=998244353;
void erase(int x,int y){
	int t=mp[MP(x,y)];
	if(!t)RE;
	t--;mp[MP(x,y)]=0;
	col1[y][(x&1)^t]--;
	ok1-=(col1[y][(x&1)^t^1]>0&&col1[y][(x&1)^t]==0);
	cnt1+=(col1[y][0]==0&&col1[y][1]==0);
	fboth[(x&1)^(y&1)^t]--;
	col2[x][(y&1)^t]--;
	ok2-=(col2[x][(y&1)^t^1]>0&&col2[x][(y&1)^t]==0);
	cnt2+=(col2[x][0]==0&&col2[x][1]==0);
} 
void add(int x,int y){
	int t=mp[MP(x,y)];
	t--;
	col1[y][(x&1)^t]++;
	ok1+=(col1[y][(x&1)^t^1]>0&&col1[y][(x&1)^t]==1);
	cnt1-=(col1[y][(x&1)^t^1]==0&&col1[y][(x&1)^t]==1);
	fboth[(x&1)^(y&1)^t]++;
	col2[x][(y&1)^t]++;
	ok2+=(col2[x][(y&1)^t^1]>0&&col2[x][(y&1)^t]==1);
	cnt2-=(col2[x][(y&1)^t^1]==0&&col2[x][(y&1)^t]==1);
}
void print(){
	int ans=0;
	if(!ok1){
		ans=(ans+pow2[cnt1])%mod;
	}
	if(!ok2){
		ans=(ans+pow2[cnt2])%mod;
	}
	ans-=fboth[0]==0;
	ans-=fboth[1]==0;
	if(ans<0)ans+=mod; 
	cout<<ans<<'\n';
} 
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	pow2[0]=1;
	FOR(i,1,1000000)pow2[i]=pow2[i-1]*2%mod;
	cin>>n>>m>>k;
	cnt1=m;cnt2=n;
	FOR(i,1,k){
		int x,y,tap;
		cin>>x>>y>>tap;
		if(tap==-1){
			erase(x,y);
		}else{
			erase(x,y);
			mp[MP(x,y)]=tap+1;
			add(x,y);
		}
		print();
	}
	io.out();
	RE 0;
}