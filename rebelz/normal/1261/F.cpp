#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lch,rch,val;
}t[5000005];

const int cys=998244353;
int n,m,rt,cnt,ncnt; ll ans=0;
pll a[100005];
ll pw[65];

void add(int dep,ll l,ll r,ll ql,ll qr,ll v){
	if(l==ql&&r==qr) return (void)(a[++cnt]=mp(v,dep+1));
	ll mid=(l+r)/2;
	if(qr<=mid) add(dep-1,l,mid,ql,qr,v);
	else if(ql>mid) add(dep-1,mid+1,r,ql,qr,v+(1ll<<dep));
	else add(dep-1,l,mid,ql,mid,v),add(dep-1,mid+1,r,mid+1,qr,v+(1ll<<dep));
}

void ask(int &id,ll l,ll r,ll ql,ll qr,int dep,ll v,int sd){
	if(!id) id=++ncnt;
	if(t[id].val) return;
	if(dep+1==sd||(l==ql&&r==qr)) return (void)(t[id].val=1);
	ll mid=(l+r)/2;
	if(v&(1ll<<dep)){
		if(qr<=mid) ask(t[id].rch,mid+1,r,ql^(1ll<<dep),qr^(1ll<<dep),dep-1,v,sd);
		else if(ql>mid) ask(t[id].lch,l,mid,ql^(1ll<<dep),qr^(1ll<<dep),dep-1,v,sd);
		else ask(t[id].lch,l,mid,l,qr^(1ll<<dep),dep-1,v,sd),ask(t[id].rch,mid+1,r,ql^(1ll<<dep),r,dep-1,v,sd);
	}
	else{
		if(qr<=mid) ask(t[id].lch,l,mid,ql,qr,dep-1,v,sd);
		else if(ql>mid) ask(t[id].rch,mid+1,r,ql,qr,dep-1,v,sd);
		else ask(t[id].lch,l,mid,ql,mid,dep-1,v,sd),ask(t[id].rch,mid+1,r,mid+1,qr,dep-1,v,sd);
	}
}

void getans(int id,ll v,int dep){
	if(!id) return;
	if(t[id].val) return (void)(ans=(ans+v%cys*pw[dep+1]+(dep+1==0?0:pw[dep]*(pw[dep+1]-1)%cys))%cys);
	getans(t[id].lch,v,dep-1);
	getans(t[id].rch,v+(1ll<<dep),dep-1);
}

int main(){
	n=readint();
	ll x,y;
	for(int i=1;i<=n;i++){
		x=readint(); y=readint();
		add(59,0,(1ll<<60)-1,x,y,0);
	}
	m=readint();
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		for(int j=1;j<=cnt;j++) ask(rt,0,(1ll<<60)-1,x,y,59,a[j].fi,a[j].se);
	}
	pw[0]=1;
	for(int i=1;i<=60;i++) pw[i]=pw[i-1]*2%cys;
	getans(rt,0,59);
	printf("%lld\n",ans);
	return 0;
}