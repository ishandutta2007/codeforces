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

int cnt[3];
int a[100005],n;
int sum[1<<18][3],ans1[1<<18],ans2[1<<18],ans3[1<<18];
void update(int x){
	rep(i,0,3)sum[x][i]=sum[lc][i]+sum[rc][i];
	ans1[x]=min({ans1[lc]+sum[rc][1],sum[lc][0]+ans1[rc],sum[lc][0]+sum[rc][1]});
	ans2[x]=min({ans2[lc]+sum[rc][2],sum[lc][1]+ans2[rc],sum[lc][1]+sum[rc][2]});
	ans3[x]=min({ans3[lc]+sum[rc][2],sum[lc][0]+ans3[rc],ans1[lc]+sum[rc][2],sum[lc][0]+ans2[rc],ans1[lc]+ans2[rc]});
	gmin(ans1[x],sum[x][0]);
	gmin(ans1[x],sum[x][1]);
	gmin(ans2[x],sum[x][1]);
	gmin(ans2[x],sum[x][2]);
	rep(i,0,3)gmin(ans3[x],sum[x][i]);
}
void build(int x,int l,int r){
	if(l==r){
		if(l>=1&&r<=n)sum[x][a[l]]++;
		ans1[x]=ans2[x]=ans3[x]=1e8;
		gmin(ans1[x],sum[x][0]);
		gmin(ans1[x],sum[x][1]);
		gmin(ans2[x],sum[x][1]);
		gmin(ans2[x],sum[x][2]);
		rep(i,0,3)gmin(ans3[x],sum[x][i]);
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x);
}
void update(int x,int l,int r,int it,int to){
	if(l==r){
		rep(i,0,3)sum[x][i]=0;
		sum[x][to]=1;
		ans1[x]=ans2[x]=ans3[x]=1e8;
		ans1[x]=ans2[x]=ans3[x]=1e8;
		gmin(ans1[x],sum[x][0]);
		gmin(ans1[x],sum[x][1]);
		gmin(ans2[x],sum[x][1]);
		gmin(ans2[x],sum[x][2]);
		rep(i,0,3)gmin(ans3[x],sum[x][i]);
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update(lc,l,mid,it,to);
	else update(rc,mid+1,r,it,to);
	update(x);
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int m;
	cin>>n>>m;
	FOR(i,1,n){
		char c;
		cin>>c;
		a[i]=c-'a';cnt[a[i]]++;
	}
	build(1,1,n);
	FOR(i,1,m){
		int x;char c;
		cin>>x>>c;
		cnt[a[x]]--;
		cnt[c-'a']++;
		update(1,1,n,x,c-'a');
		a[x]=c-'a';
		if(!cnt[0]||!cnt[1]||!cnt[2]){
			cout<<0ll<<'\n';
		}
		else cout<<ans3[1]<<'\n';
	}
	io.out();
	RE 0;
}