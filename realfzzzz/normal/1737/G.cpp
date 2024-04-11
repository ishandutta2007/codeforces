#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
mt19937 rnd(time(0));
const int maxn=1e5+5;
int n,d,m,a[maxn],x[maxn],y[maxn];
char s[maxn];
int n2=0,a2[maxn],ord[maxn];
struct node{
	int rd;
	node* ch[2];
	ll x,add=0;
	int s=1;
	void pushup(){
		s=1;
		if(ch[0]) s+=ch[0]->s;
		if(ch[1]) s+=ch[1]->s;
	}
	node(ll x):rd(rnd()),x(x){
		ch[0]=ch[1]=0;
	}
	void pushtag(ll k){
		x+=k;
		add+=k;
	}
	void pushdown(){
		if(ch[0]) ch[0]->pushtag(add);
		if(ch[1]) ch[1]->pushtag(add);
		add=0;
	}
};
node* merge(node* l,node* r){
	if(!l) return r;
	if(!r) return l;
	if(l->rd>r->rd){
		l->pushdown();
		l->ch[1]=merge(l->ch[1],r);
		l->pushup();
		return l;
	}
	else{
		r->pushdown();
		r->ch[0]=merge(l,r->ch[0]);
		r->pushup();
		return r;
	}
}
void split1(node* o,ll k,node*& l,node*& r){
	if(!o){
		l=r=0;
		return;
	}
	o->pushdown();
	int ls=o->ch[0]?o->ch[0]->s:0;
	if(k>=ls+1){
		l=o;
		split1(o->ch[1],k-ls-1,o->ch[1],r);
	}
	else{
		r=o;
		split1(o->ch[0],k,l,o->ch[0]);
	}
	o->pushup();
}
void split2(node* o,ll k,node*& l,node*& r){
	if(!o){
		l=r=0;
		return;
	}
	o->pushdown();
	if(k>=o->x){
		l=o;
		split2(o->ch[1],k,o->ch[1],r);
	}
	else{
		r=o;
		split2(o->ch[0],k,l,o->ch[0]);
	}
	o->pushup();
}
node* rt=0;
int t=0;
void move(int x){
	int s=rt->s;
	rt->pushtag(1ll*x/s*(d+s-1));
	node *left,*right;
	split1(rt,x%s,left,right);
	if(left) left->pushtag(d+s-1);
	rt=merge(right,left);
	t+=x;
}
int calc(ll x){
	int s=rt->s;
	node *left,*right;
	split1(rt,s-1,left,right);
	int c=(x-right->x-1)/(d+s-1);
	rt=merge(left,right);
	split2(rt,x-1ll*(d+s-1)*(c+1)-1,left,right);
	c=s*c+(left?left->s:0);
	rt=merge(left,right);
	return c;
}
ll query(int x){
	if(upper_bound(a2+1,a2+n2+1,a[x])-a2-1+rt->s<x) return a[x];
	ll l=1,r=3e18;
	while(l<r){
		ll mid=l+(r-l)/2;
		int y=upper_bound(a2+1,a2+n2+1,mid)-a2-1;
		node *left,*right;
		split2(rt,mid-y,left,right);
		if(y+(left?left->s:0)>=x) r=mid;
		else l=mid+1;
		rt=merge(left,right);
	}
	return r;
}
ll ans[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	d=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		x[i]=read();
		y[i]=read();
		ord[i]=i;
	}
	sort(ord+1,ord+m+1,[](int a,int b){
		return x[a]<x[b];
	});
	for(int i=1;i<=n;i++) if(s[i]=='0') a2[++n2]=a[i];
	int c=1;
	auto deal=[](int u){
		move(x[u]-t);
		ans[u]=query(y[u]);
	};
	for(int i=1;i<=n;i++) if(s[i]=='1'){
		int u=a[i]-(upper_bound(a2+1,a2+n2+1,a[i])-a2-1);
		if(!rt){
			rt=new node(u);
			continue;
		}
		while(c<=m&&x[ord[c]]-t<=calc(u)) deal(ord[c++]);
		move(calc(u));
		rt=merge(rt,new node(u));
	}
	while(c<=m) deal(ord[c++]);
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}