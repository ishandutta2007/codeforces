#include<bits/stdc++.h>

#define IT set<node>::iterator
#define pli pair<ll,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r; mutable ll v;
	node(int ll,int rr=-1,long long vv=0):l(ll),r(rr),v(vv){}
	bool operator<(const node c)const{return l<c.l;}
};

set<node> s;
ll seed,n,m,vmax,ans;
ll a[100005];
vector<pli> vec;

ll rnd(){
	ll ret=seed;
	seed=(7ll*seed+13)%1000000007;
	return ret;
}

ll power(ll x,ll p,int cys){
	x=(x%cys+cys)%cys;
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

IT split(int x){
	IT it=s.lower_bound(node(x));
	if(it!=s.end()&&it->l==x) return it;
	it--;
	int l=it->l,r=it->r; ll v=it->v;
	s.erase(it);
	s.insert(node(l,x-1,v)); s.insert(node(x,r,v));
	return s.lower_bound(node(x));
}

void cov(int l,int r,int x){
	auto st=split(l),en=split(r+1);
	s.erase(st,en);
	s.insert(node(l,r,x));
}

void add(int l,int r,int x){
	auto st=split(l),en=split(r+1);
	for(auto it=st;it!=en;it++) it->v+=x;
}

ll kth(int l,int r,int k){
	vec.clear();
	auto st=split(l),en=split(r+1);
	for(auto it=st;it!=en;it++) vec.push_back(mp(it->v,it->r-it->l+1));
	sort(vec.begin(),vec.end());
	for(auto v:vec){
		k-=v.se;
		if(k<=0) return v.fi;
	}
}

ll sum(int l,int r,int x,int y){
	ll ret=0;
	auto st=split(l),en=split(r+1);
	for(auto it=st;it!=en;it++) ret=(ret+1ll*(it->r-it->l+1)*power(it->v,x,y)%y)%y;
	return ret;
}

int main(){
	n=readint(); m=readint(); seed=readint(); vmax=readint();
	for(int i=1;i<=n;i++){
		a[i]=rnd()%vmax+1;
		s.insert(node(i,i,a[i]));
	}
	s.insert(node(n+1,n+1,0));
	int opt,x,y; ll z;
	for(int i=1;i<=m;i++){
		opt=rnd()%4+1,x=rnd()%n+1,y=rnd()%n+1;
		if(x>y) swap(x,y);
		if(opt==1) add(x,y,rnd()%vmax+1);
		else if(opt==2) cov(x,y,rnd()%vmax+1);
		else if(opt==3) printf("%lld\n",kth(x,y,rnd()%(y-x+1)+1));
		else{
			z=rnd()%vmax+1;
			printf("%lld\n",sum(x,y,z,rnd()%vmax+1));
		}
	}
	return 0;
}