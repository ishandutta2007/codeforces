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

int n,m,Q;
V<P<int,P<int,int> > > p[1<<19];
int ans[200005];
P<int,P<int,int> > q[200005];
map<P<int,int>,int> lst,num;
void update(int x,int l,int r,int tl,int tr,int tx,int ty,int num){
	if(l>=tl&&r<=tr){
		p[x].PB(MP(num,MP(tx,ty)));
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,tx,ty,num);
	update(rc,mid+1,r,tl,tr,tx,ty,num);
}
int nump[35];
int len,fa[200005],top[200005],siz[200005];
P<int,int> mp[200005];
int getfa(int x,int &y){
	if(x==fa[x]){
		RE x;
	}else{
		y^=top[x];
		RE getfa(fa[x],y);
	}
}
void in(int x){
	for(int i=29;i>=0;i--){
		if(x&(1<<i)){
			if(!nump[i]){
				nump[i]=x;break;
			}else x^=nump[i];
		}
	}
}
void merge(int x,int y,int num){
	x=getfa(x,num);
	y=getfa(y,num);
//	cout<<' '<<x<<' '<<y<<' '<<num<<'\n';
	if(x==y){
		in(num);
		RE;
	}
	if(siz[y]>siz[x]){
		swap(x,y);
	}
	mp[++len]=MP(y,siz[y]);
	top[y]=num;
	fa[y]=x;
	siz[x]+=siz[y];
}
int get(int x,int y){
	int num=0;
	x=getfa(x,num);y=getfa(y,num);
	for(int i=29;i>=0;i--)if(num&(1<<i)){
		if(nump[i])num^=nump[i];
	}
	RE num;
}
void solve(int x,int l,int r){
	int nowp[30]={},st=len;
	rep(i,0,30)nowp[i]=nump[i];
//	cout<<x<<'\n';
	for(auto u:p[x]){
//		cout<<u.F<<' '<<u.S.F<<' '<<u.S.S<<'\n';
		merge(u.S.F,u.S.S,u.F);
	}
//	cout<<' ';
//	rep(i,0,3){
//		cout<<nump[i]<<' ';
//	}
//	cout<<'\n';
	if(l==r){
		if(q[l].F){
			ans[q[l].F]=get(q[l].S.F,q[l].S.S);
		}
	}else{
		int mid=(l+r)>>1;
		solve(lc,l,mid);
		solve(rc,mid+1,r);
	}
	while(len>st){
		siz[mp[len].F]=mp[len].S;
		top[mp[len].F]=0;
		fa[mp[len].F]=mp[len].F;
		len--;
	}
	rep(i,0,30)nump[i]=nowp[i];
}
signed main(){
	io.init();
	cin>>n>>m;
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>y)swap(x,y);
		lst[MP(x,y)]=1;
		num[MP(x,y)]=z;
	}
	cin>>Q;
	FOR(i,1,Q){
		int tap;
		cin>>tap;
		if(tap==1){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>y)swap(x,y);
			lst[MP(x,y)]=i;
			num[MP(x,y)]=z;
		}else if(tap==2){
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			int lt=lst[MP(x,y)];lst[MP(x,y)]=0;
			update(1,1,Q,lt,i,x,y,num[MP(x,y)]);
		}else{
			cin>>q[i].S.F>>q[i].S.S;
			q[i].F=i;
		}
	}
	for(auto u:lst){
		if(u.S){
			P<int,int> now=u.F;
//			cout<<now.F<<' '<<now.S<<'\n';
			update(1,1,Q,u.S,Q,now.F,now.S,num[now]);
		}
	}
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	solve(1,1,Q);
	FOR(i,1,Q){
		if(q[i].F)cout<<ans[i]<<'\n';
	}
	io.out();
	RE 0;
}