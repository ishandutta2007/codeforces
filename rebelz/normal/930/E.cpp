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

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,m1,m2,s,ncnt;
ll l[200005],r[200005],c[200005],pw[200005];
vector<pii> cl[5];
map<int,vector<pii> > v;

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

namespace sgt1{
	int ncnt,rt;
	ll val[3000000];
	int lch[3000000],rch[3000000];
	void change(int &id,int l,int r,int x,ll c){
		if(!id) id=++ncnt;
		if(l==r) return (void)(val[id]=mod(val[id]+c));
		int mid=(l+r)/2;
		if(x<=mid) change(lch[id],l,mid,x,c);
		else change(rch[id],mid+1,r,x,c);
		val[id]=mod(val[lch[id]]+val[rch[id]]);
	}
	ll query(int id,int l,int r,int ql,int qr){
		if(!id) return 0;
		if(l==ql&&r==qr) return val[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(lch[id],l,mid,ql,qr);
		else if(ql>mid) return query(rch[id],mid+1,r,ql,qr);
		else return mod(query(lch[id],l,mid,ql,mid)+query(rch[id],mid+1,r,mid+1,qr));
	}
}

namespace sgt2{
	struct node{
		int lch,rch; ll val;
	}t[5000000];
	int rt[5];
	void change(int &id,int l,int r,int x,ll c){
		if(!id) id=++ncnt;
		if(l==r) return (void)(t[id].val=mod(t[id].val+c));
		int mid=(l+r)/2;
		if(x<=mid) change(t[id].lch,l,mid,x,c);
		else change(t[id].rch,mid+1,r,x,c);
		t[id].val=mod(t[t[id].lch].val*qpow((cys+1)/2,r-mid)%cys+t[t[id].rch].val);
	}
	ll query(int id,int l,int r,int ql,int qr){
		if(!id) return 0;
		if(l==ql&&r==qr) return t[id].val;
		int mid=(l+r)/2;
		if(qr<=mid) return query(t[id].lch,l,mid,ql,qr);
		else if(ql>mid) return query(t[id].rch,mid+1,r,ql,qr);
		else return mod(query(t[id].lch,l,mid,ql,mid)*qpow((cys+1)/2,qr-mid)%cys+query(t[id].rch,mid+1,r,mid+1,qr));
	}
}

int main(){
	s=2;
	n=readint(); m1=readint(); m2=readint();
	int x,y;
	for(int i=1;i<=m1;i++){
		x=readint(); y=readint();
		cl[1].push_back(mp(y,-x));
	}
	for(int i=1;i<=m2;i++){
		x=readint(); y=readint();
		cl[2].push_back(mp(y,-x));
	}
	for(int i=1;i<=s;i++) sort(cl[i].begin(),cl[i].end());
	for(int i=1;i<=s;i++){
		if(!cl[i].size()) continue;
		v[-cl[i][0].se].push_back(mp(cl[i][0].fi,i));
		int mx=-cl[i][0].se;
		for(int j=1;j<cl[i].size();j++){
			if(cl[i][j].se==cl[i][j-1].se) continue;
			if(-cl[i][j].se<=mx) continue;
			chkmax(mx,-cl[i][j].se);
			v[-cl[i][j].se].push_back(mp(cl[i][j].fi,i));
		}
	}
	sgt1::change(sgt1::rt,0,n,0,qpow(s,n));
	for(auto x:v){
		int i=x.fi-1; auto t=x.se;
		sort(t.begin(),t.end());
		for(auto x:t){
//			cout<<"test "<<i+1<<' '<<x.fi<<' '<<x.se<<endl;
			ll tmp1=sgt1::query(1,0,n,0,i)*qpow((cys+1)/2,x.fi-i)%cys;
			ll tmp2=sgt2::query(sgt2::rt[x.se],1,n,i+1,x.fi);
//			cout<<"tmp "<<tmp1<<' '<<tmp2<<endl;
			sgt1::change(sgt1::rt,0,n,x.fi,mod(cys+cys-tmp1-tmp2));
			sgt2::change(sgt2::rt[x.se],1,n,x.fi,mod(cys+cys-tmp1-tmp2));
		}
//		for(int i=0;i<=n;i++) cout<<sgt1::query(1,0,n,i,i)<<' ';
//		cout<<endl;
	}
	printf("%lld\n",sgt1::val[sgt1::rt]);
	return 0;
}