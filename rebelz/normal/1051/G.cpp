#include<bits/stdc++.h>

#define pll pair<ll,ll>
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
	mutable int l,r; ll x;
	node(int l=0,int rr=0,ll xx=0):l(l),r(rr),x(xx){}
	bool operator<(const node c)const{return l<c.l;}
};

struct sgt{
	int lch,rch,siz;
	ll sum;
}t[10000000];

int n,cnt;
ll ans=0;
int a[200005],rt[200005];
ll b[200005];
set<node> s;
set<node>::iterator it1,it2;

void change(int &id,int l,int r,ll x){
	if(!id) id=++cnt;
	t[id].sum+=x,t[id].siz++;
	if(l==r) return;
	int mid=(l+r)/2;
	if(x<=mid) change(t[id].lch,l,mid,x);
	else change(t[id].rch,mid+1,r,x);
}

pll query(int id,int l,int r,int ql,int qr){
	if(!id) return mp(0,0);
	if(l==ql&&r==qr) return mp(t[id].siz,t[id].sum);
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id].rch,mid+1,r,ql,qr);
	pll lson=query(t[id].lch,l,mid,ql,mid),rson=query(t[id].rch,mid+1,r,mid+1,qr);
	return mp(lson.fi+rson.fi,lson.se+rson.se);
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	ans-=t[t[y].rch].sum*t[t[x].lch].siz-t[t[x].lch].sum*t[t[y].rch].siz;
	t[x].siz+=t[y].siz,t[x].sum+=t[y].sum;
	t[x].lch=merge(t[x].lch,t[y].lch);
	t[x].rch=merge(t[x].rch,t[y].rch);
	return x;
}

int main(){
	n=readint();
	pll ret; int rl,rr,ll,lr;
	a[1]=readint(); b[1]=readint();
	s.insert(node(a[1],a[1],b[1]));
	change(rt[a[1]],1,n,b[1]);
	puts("0");
	for(int i=2;i<=n;i++){
		a[i]=readint(); b[i]=readint();
		auto x=s.upper_bound(node(a[i],0,0));
		it1=x; rl=rr=1<<30,ll=lr=-1;
		if(it1!=s.end()) rl=it1->l,rr=it1->r;
		if(it1!=s.begin()) it2=--x,ll=it2->l,lr=it2->r;
		if(lr>=a[i]) ans+=(lr+1-a[i])*b[i],a[i]=lr+1;
		if(lr+1<a[i]&&a[i]+1<rl){
			s.insert(node(a[i],a[i],b[i]));
			change(rt[a[i]],1,n,b[i]);
		}
		else if(lr+1<a[i]){
			it1->l--;
			ret=query(rt[rl],1,n,b[i]+1,n);
			ans-=ret.se-ret.fi*b[i];
			change(rt[rl],1,n,b[i]);
			rt[a[i]]=rt[rl];
		}
		else if(a[i]+1<rl){
			it2->r++;
			ret=query(rt[ll],1,n,1,b[i]-1);
			ans-=ret.fi*b[i]-ret.se;
			change(rt[ll],1,n,b[i]);
		}
		else{
			ret=query(rt[ll],1,n,1,b[i]-1);
			ans-=ret.fi*b[i]-ret.se;
			ret=query(rt[rl],1,n,b[i]+1,n);
			ans-=ret.se-ret.fi*b[i];
			rt[ll]=merge(rt[ll],rt[rl]);
			it2->r=rr;
			s.erase(it1);
			change(rt[ll],1,n,b[i]);
		}
		printf("%lld\n",ans);
//		cout<<"HYCHYCHYCHYCHYCHYCHYCHYCHYC AK IOI"<<endl;
//		for(auto tmp:s) cout<<tmp.l<<' '<<tmp.r<<' '<<t[rt[tmp.l]].sum<<endl;
//		cout<<"HYCHYCHYCHYCHYCHYCHYCHYCHYC AK CTSC"<<endl;
	}
	return 0;
}