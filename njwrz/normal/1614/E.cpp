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

int ch[20000000][2],tag[20000000],mini[20000000];
int n,maxn=1e9,cnt,root;
void pushdown(int x){
	mini[ch[x][0]]+=tag[x];
	mini[ch[x][1]]+=tag[x];
	tag[ch[x][0]]+=tag[x];
	tag[ch[x][1]]+=tag[x];
	tag[x]=0;
}
void update(int x,int l,int r,int tl,int tr,int num){
	if(l>=tl&&r<=tr){
		tag[x]+=num;
		mini[x]+=num;
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	if(!ch[x][0]){
		ch[x][0]=++cnt;
		ch[x][1]=++cnt;
		mini[ch[x][0]]=l;
		mini[ch[x][1]]=mid+1;
	}
	pushdown(x);
	update(ch[x][0],l,mid,tl,tr,num);
	update(ch[x][1],mid+1,r,tl,tr,num);
	mini[x]=min(mini[ch[x][0]],mini[ch[x][1]]);
}
int find(int x,int l,int r,int num){
	if(mini[x]>num)RE -1;
	if(l==r){
		RE l;
	}
	int mid=(l+r)>>1;
	if(!ch[x][0]){
		ch[x][0]=++cnt;
		ch[x][1]=++cnt;
		mini[ch[x][0]]=l;
		mini[ch[x][1]]=mid+1;
	}
	pushdown(x);
	if(mini[ch[x][1]]<=num){
		RE find(ch[x][1],mid+1,r,num);
	}else RE find(ch[x][0],l,mid,num);
}
int get(int x,int l,int r,int it){
	if(l==r){
		RE mini[x];
	}
	int mid=(l+r)>>1;
	if(!ch[x][0]){
		ch[x][0]=++cnt;
		ch[x][1]=++cnt;
		mini[ch[x][0]]=l;
		mini[ch[x][1]]=mid+1;
	}
	pushdown(x);
	if(it<=mid)RE get(ch[x][0],l,mid,it);
	else RE get(ch[x][1],mid+1,r,it);
}
int mod=(1e9+1);
signed main(){
	io.init();
	cin>>n;root=cnt=1;
	int lstans=0;
	FOR(i,1,n){
		int T;
		cin>>T;
		int t=find(root,0,maxn,T-1);
		int t2=find(root,0,maxn,T)+1;
//		cout<<t<<' '<<t2<<'\n';
		if(t>=0)update(root,0,maxn,0,t,1);
		if(t2<=maxn)update(root,0,maxn,t2,maxn,-1);
		int cnt;cin>>cnt;
		FOR(j,1,cnt){
			int x;
			cin>>x;
			x=(x+lstans)%mod;
			lstans=get(root,0,maxn,x);
			cout<<lstans<<'\n';
		}
	}
	io.out();
	RE 0;
}