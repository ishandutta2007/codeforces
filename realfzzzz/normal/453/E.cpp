#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,m;
typedef long long ll;
struct sgt_node{
	int l,r;
	sgt_node* ch[2];
	ll s;
	sgt_node(int l,int r):l(l),r(r),s(0){
		ch[0]=ch[1]=0;
	}
	sgt_node(sgt_node* x){
		*this=*x;
	}
	void modify(int x,ll k){
		s+=k;
		if(l==r) return;
		int mid=l+(r-l)/2;
		if(x<=mid){
			if(!ch[0]) ch[0]=new sgt_node(l,mid);
			else ch[0]=new sgt_node(ch[0]);
			ch[0]->modify(x,k);
		}
		else{
			if(!ch[1]) ch[1]=new sgt_node(mid+1,r);
			else ch[1]=new sgt_node(ch[1]);
			ch[1]->modify(x,k);
		}
	}
	ll query(int ql,int qr){
		if(ql<=l&&qr>=r) return s;
		int mid=l+(r-l)/2;
		ll ans=0;
		if(ql<=mid&&ch[0]) ans+=ch[0]->query(ql,qr);
		if(qr>mid&&ch[1]) ans+=ch[1]->query(ql,qr);
		return ans;
	}
}*rt1[maxn],*rt2[maxn];
struct odt_node{
	int l,r,t,s;
	odt_node(int l,int r,int t,int s=0):l(l),r(r),t(t),s(s){}
	bool operator <(const odt_node b)const{
		return r<b.r;
	}
};
set<odt_node> odt;
typedef set<odt_node>::iterator iter;
iter split(int x){
	if(x>n) return odt.end();
	odt_node u=*odt.lower_bound(odt_node(x,x,0));
	odt.erase(u);
	if(x>u.l) odt.insert(odt_node(u.l,x-1,u.t,u.s));
	return odt.insert(odt_node(x,u.r,u.t,u.s)).first;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	rt1[0]=new sgt_node(0,1e9+1);
	rt2[0]=new sgt_node(0,1e9+1);
	for(int i=1;i<=n;i++){
		int s,m,r;
		s=readint();
		m=readint();
		r=readint();
		odt.insert(odt_node(i,i,0,s));
		rt1[i]=new sgt_node(rt1[i-1]);
		rt1[i]->modify(r?(m-1)/r+1:1e9+1,r);
		rt2[i]=new sgt_node(rt2[i-1]);
		rt2[i]->modify(r?(m-1)/r+1:1e9+1,m);
	}
	m=readint();
	while(m--){
		int t,l,r;
		t=readint();
		l=readint();
		r=readint();
		iter itl,itr;
		itr=split(r+1);
		itl=split(l);
		ll ans=0;
		for(iter i=itl;i!=itr;i++)
			if(i->s){
				int m,r;
				r=rt1[i->r]->s-rt1[i->r-1]->s;
				m=rt2[i->r]->s-rt2[i->r-1]->s;
				ans+=min(1ll*m,i->s+1ll*r*t);
			}
			else{
				ll m,r;
				r=rt1[i->r]->query(t-i->t+1,1e9+1)-rt1[i->l-1]->query(t-i->t+1,1e9+1);
				m=rt2[i->r]->query(0,t-i->t)-rt2[i->l-1]->query(0,t-i->t);
				ans+=r*(t-i->t)+m;
			}
		odt.erase(itl,itr);
		odt.insert(odt_node(l,r,t));
		printf("%lld\n",ans);
	}
	return 0;
}