// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,b,t,w,l,num;
int now[34000000],r[10000005];
pii val[34000000],all[34000000];
bool fl[34000000];

void update(int id,int dep){
	num-=fl[id];
	fl[id]=0;
	if(t&(1<<dep)){
		if(val[id<<1].fi>=0&&val[id<<1|1].fi>=0&&val[id<<1].fi!=val[id<<1|1].fi) fl[id]=1;
		if(val[id<<1].fi>=0) val[id].fi=val[id<<1].fi;
		else if(val[id<<1|1].fi>=0) val[id].fi=val[id<<1|1].fi;
		else val[id].fi=-1;
		val[id].se=val[id<<1].se+val[id<<1|1].se-(val[id<<1].fi<0||val[id<<1|1].fi<0);
	}
	else{
		if(val[id<<1].fi>=0&&val[id<<1|1].fi>=0) val[id].fi=val[id<<1].fi^val[id<<1|1].fi;
		else val[id].fi=-1;
		val[id].se=val[id<<1].se+val[id<<1|1].se;
	}
	num+=fl[id];
}

void build(int id,int l,int r,int dep){
	if(l==r) return (void)(val[id]=mp(t==b?0:-1,n/b-(t==b)),all[id]=mp(0,n/b));
	int mid=(l+r)/2;
	build(id<<1,l,mid,dep+1);
	build(id<<1|1,mid+1,r,dep+1);
	update(id,dep);
}

void change(int id,int l,int r,int x,int c,int p,int dep){
	if(l==r){
		if(c==now[p]) return;
		num-=fl[id];
		fl[id]=0;
		if(c==-1){
			all[id].se++,all[id].fi^=now[p];
			val[id]=all[id];
			if(t==b) val[id].fi=0,val[id].se--;
			else if(val[id].se) val[id].fi=-1;
		}
		else if(now[p]==-1){
			all[id].se--,all[id].fi^=c;
			val[id]=all[id];
			if(t==b){
				if(!val[id].se) fl[id]=val[id].fi!=0;
				else val[id].se--,val[id].fi=0;
			}
			else if(val[id].se) val[id].fi=-1;
		}
		else{
			all[id].fi^=now[p]^c;
			val[id]=all[id];
			if(t==b){
				if(!val[id].se) fl[id]=val[id].fi!=0;
				else val[id].se--,val[id].fi=0;
			}
			else if(val[id].se) val[id].fi=-1;
		}
		now[p]=c;
		num+=fl[id];
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c,p,dep+1);
	else change(id<<1|1,mid+1,r,x,c,p,dep+1);
	update(id,dep);
}

ll qpow(ll x,ll p,ll cys){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); m=readint(); t=readint(); w=readint();
	for(l=0,b=1;n%b==0;l++,b<<=1);
	b>>=1,l--;
	chkmin(t,b);
	for(int i=1;i<=n;i++) now[i]=-1;
	for(int i=1;i<b;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	build(1,0,b-1,0);
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		change(1,0,b-1,r[x%b],y,x,0);
	}
	q=readint();
	while(q--){
		x=readint(); y=readint(); z=readint();
		change(1,0,b-1,r[x%b],y,x,0);
		if(num) printf("0\n");
		else printf("%lld\n",qpow(1<<w,val[1].se,z));
	}
	return 0;
}