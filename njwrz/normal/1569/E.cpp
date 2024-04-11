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

map<int,int> mp[16];
int p[40],n,A,a[40],rnk[40],t,mod=998244353;
void solve(int mask){
	rep(i,0,t)p[i]=i;
	int now=0;
	rep(i,0,n-1){
		for(int j=0;j<t;j+=(1<<(i+1))){
			if(mask&(1<<now)){
				rnk[p[j]]=(1<<(n-i-1))+1;
				p[j]=p[j+(1<<i)];
			}else{
				rnk[p[j+(1<<i)]]=(1<<(n-i-1))+1;
			}
			now++;
		}
	}
	rnk[p[0]]=2;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	io.init();
	int k;
	cin>>n>>A>>k;
	a[0]=1;
	rep(i,1,35)a[i]=a[i-1]*A%mod;
	t=1<<n;t/=2;
	rep(mask,0,1<<(t-1)){
		solve(mask);
		int val=0;
		rep(i,0,t){
			val=(val+(i+1)*a[rnk[i]])%mod;
		}
		mp[p[0]][val]=mask;
	}
	int mask1=-1,mask2=-1;
	int win=-1;
	rep(mask,0,1<<(t-1)){
		solve(mask);
		int val=0;
		rep(i,0,t){
			val=(val+(i+t+1)*a[rnk[i]])%mod;
		}
		int tval=(val-(p[0]+t+1)*a[2]%mod+(p[0]+t+1)*a[1])%mod;
		if(tval<0)tval+=mod;
		tval=k-tval;
		if(tval<0)tval+=mod;
		rep(i,0,t){
			if(mp[i].count(tval)){
				mask1=mp[i][tval];mask2=mask;win=p[0]+t;
				break;
			}
		}
		if(mask1!=-1)break;
		rep(i,0,t){
			int tval=k-val;
			tval=(tval+(i+1)*a[2]-(i+1)*a[1])%mod;
			if(tval<0)tval+=mod;
			if(mp[i].count(tval)){
				mask1=mp[i][tval];
				mask2=mask;win=i;
				break;
			}
		}
		if(mask1!=-1)break;
	}
	if(mask1==-1){
		puts("-1");io.out();RE 0;
	}
	solve(mask1);
	rep(i,0,t){
		if(i==win){
			cout<<1ll<<' ';
		}else cout<<rnk[i]<<' ';
	}
	solve(mask2);
	rep(i,t,2*t){
		if(i==win){
			cout<<1ll<<' ';
		}else cout<<rnk[i-t]<<' ';
	}
	io.out();
	RE 0;
}