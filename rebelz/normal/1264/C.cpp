#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;

struct node{
	ll x,y,z;
	node operator+(const node c)const{
		node ret; ret.x=ret.y=ret.z=0;
		ret.x=(y*c.x+x)%cys;
		ret.y=y*c.y%cys;
		ret.z=(z+y*c.z)%cys;
		return ret;
	}
}t[600000];

int n,q;
ll a[200005];
set<int> s;

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

ll getans(node x){return x.z*qpow(mod(1+cys-x.x),cys-2)%cys;}

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].x=mod(1+cys-a[l]),t[id].y=a[l],t[id].z=1);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]+t[id<<1|1];
}

node query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	n=readint(); q=readint();
	ll inv100=qpow(100,cys-2);
	for(int i=1;i<=n;i++) a[i]=readint()*inv100%cys;
	build(1,1,n);
	ll ans=getans(t[1]);
	s.insert(1),s.insert(n+1);
	int x;
	for(int i=1;i<=q;i++){
		x=readint();
		auto it=s.lower_bound(x),it1=it,it2=it;
		if(*it==x){
			it1--,it2++;
			ans-=getans(query(1,1,n,*it1,*it-1));
			ans-=getans(query(1,1,n,*it,*it2-1));
			ans+=getans(query(1,1,n,*it1,*it2-1));
			ans%=cys;
			s.erase(it);
		}
		else{
			it1--;
			ans-=getans(query(1,1,n,*it1,*it-1));
			ans+=getans(query(1,1,n,*it1,x-1));
			ans+=getans(query(1,1,n,x,*it-1));
			ans%=cys;
			s.insert(x);
		}
		printf("%lld\n",mod(ans+cys));
	}
	return 0;
}