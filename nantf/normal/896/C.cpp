#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int l,r;mutable ll v;
	bool operator<(const node &n)const{return l<n.l;}
}tmp[100010];
int n,m,seed,vmax,tl;
typedef set<node>::iterator sni;
set<node> cns;
inline bool cmpv(node n1,node n2){return n1.v<n2.v;}
inline int rnd(){int ans=seed;seed=(seed*7ll+13)%1000000007;return ans;}
inline ll qpow(ll a,ll b,int p){
	ll ans=1%p;a%=p;
	for(;b;b>>=1,a=a*a%p) if(b&1) ans=ans*a%p;
	return ans;
}
sni split(int k){
	sni p=cns.lower_bound((node){k,k,0});
	if(p!=cns.end() && p->l==k) return p;
	p--;int l=p->l,r=p->r;ll v=p->v;
	cns.erase(p);cns.insert((node){l,k-1,v});
	return cns.insert((node){k,r,v}).first;
}
void assign(int l,int r,int v){
	sni ll=split(l),rr=split(r+1);
	cns.erase(ll,rr);
	cns.insert((node){l,r,v});
}
void add(int l,int r,int v){
	sni ll=split(l),rr=split(r+1);
	for(;ll!=rr;ll++) ll->v+=v;
}
ll kth(int l,int r,int k){
	sni ll=split(l),rr=split(r+1);tl=0;
	for(;ll!=rr;ll++) tmp[++tl]=*ll;
	sort(tmp+1,tmp+tl+1,cmpv);int cnt=0;
	for(int i=1;i<=tl;i++){
		cnt+=tmp[i].r-tmp[i].l+1;
		if(cnt>=k) return tmp[i].v;
	}
}
int sum(int l,int r,int x,int y){
	sni ll=split(l),rr=split(r+1);int ans=0;
	for(;ll!=rr;ll++) ans=(ans+(ll->r-ll->l+1)*qpow(ll->v,x,y))%y;
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;i++) cns.insert((node){i,i,rnd()%vmax+1});
	cns.insert((node){n+1,n+1,0});
	for(int i=1;i<=m;i++){
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
		if(l>r) swap(l,r);
		if(op==3) printf("%lld\n",kth(l,r,rnd()%(r-l+1)+1));
		else{
			int x=rnd()%vmax+1;
			if(op==4) printf("%d\n",sum(l,r,x,rnd()%vmax+1));
			else if(op==1) add(l,r,x);
			else assign(l,r,x);
		}
	}
}