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

ll n,m,p;
ll a[1000005],sum[2100000];
vector<ll> vec[2100000];

vector<ll> merge(vector<ll> x,vector<ll> y,ll val){
	vector<ll> ret(0);
	int now=0;
	for(int i=0;i<x.size();i++){
		while(now<y.size()&&y[now]<x[i]+val-i*p){
			ret.pb(y[now]-val+i*p);
			now++;
		}
		if(!now||y[now-1]<x[i]+val-(i+1)*p) ret.pb(x[i]);
		else ret.pb(y[now-1]-val+(i+1)*p);
	}
	while(now<y.size()){
		ret.pb(y[now]-val+x.size()*p);
		now++;
	}
	return ret;
}

void build(int id,int l,int r){
	if(l==r) return (void)(vec[id].pb(p-a[l]),sum[id]=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	sum[id]=sum[id<<1]+sum[id<<1|1];
	vec[id]=merge(vec[id<<1],vec[id<<1|1],sum[id<<1]);
}

ll getans(int id,ll x){
	int pl=upper_bound(vec[id].begin(),vec[id].end(),x)-vec[id].begin();
	return x+sum[id]-pl*p;
}

ll query(int id,int l,int r,int ql,int qr,ll c){
	if(l==ql&&r==qr) return getans(id,c);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,c);
	else return query(id<<1|1,mid+1,r,mid+1,qr,query(id<<1,l,mid,ql,mid,c));
}

int main(){
	n=readint(); m=readint(); p=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	int l,r;
	while(m--){
		l=readint(); r=readint();
		printf("%lld\n",query(1,1,n,l,r,0));
	}
	return 0;
}