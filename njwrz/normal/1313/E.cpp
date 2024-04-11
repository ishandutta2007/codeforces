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
#define y1 yyyy1111
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
char a[500005],b[500005],c[1000005];
int p[1500005],len;
int r[500005],l[500005];
char s[1500005];
void solve(){
	int it=0;
	FILL(p,0);
	FOR(i,2,len){
		if(it+p[it]-1>=i){
			p[i]=p[i-it+1];
			gmin(p[i],it+p[it]-i);
		}
		while(i+p[i]<=len&&s[i+p[i]]==s[p[i]+1])p[i]++;
		if(i+p[i]>it+p[it])it=i;
	}
}
struct node{
	int sum[1000005];
	void update(int x,int y){
		while(x<=m){
			sum[x]+=y;
			x+=x&-x;
		}
	} 
	int get(int x){
		int re=0;
		while(x){
			re+=sum[x];
			x-=x&-x;
		}
		RE re;
	}
}T1,T2;
void update(int l,int r,int x){
	gmax(l,1ll);
	T1.update(l,x);
	T1.update(r+1,x);
	T2.update(l,-(l-1)*x);
	T2.update(r+1,(r-l)*x);
}
int get(int x){
	RE x*T1.get(x)+T2.get(x);
}
int get(int l,int r){
	gmin(r,m-1);
	RE get(r)-get(l-1);
}
signed main(){
	io.init();
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	FOR(i,1,m)cin>>c[i];
	FOR(i,1,m)s[++len]=c[i];
	FOR(i,1,n)s[++len]=a[i];
	solve();
	FOR(i,1,n)l[i]=min(m,p[i+m]);
	len=0;
	for(int i=m;i>=1;i--)s[++len]=c[i];
	for(int i=n;i>=1;i--)s[++len]=b[i];
	solve();
	FOR(i,1,n)r[n-i+1]=min(m,p[i+m]);
	FOR(i,1,min(n,m-2)){
		update(m-r[i],m-1,1);
	}
	int ans=0;
	FOR(i,1,n){
		if(i){
			update(m-r[i-1],m-1,-1);
		}
		if(i+m-2<=n){
			update(m-r[i+m-2],m-1,1);
		}
		if(l[i]){
			ans+=get(1,l[i]);
		}
	}
	cout<<ans;
	io.out();
	RE 0;
}