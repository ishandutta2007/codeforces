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
const int maxn=2e5+5;
int n,fa[maxn*2],s[maxn*2];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
ll ans=0;
struct node{
	int l,r;
	node* ch[2];
	int s=0;
	ll sum=0;
	node(int l,int r):l(l),r(r){
		ch[0]=ch[1]=0;
	}
	void insert(int x){
		s++;
		sum+=x;
		if(l==r) return;
		int mid=l+(r-l)/2;
		if(x<=mid){
			if(ch[1]) ans+=1ll*x*ch[1]->s;
			if(!ch[0]) ch[0]=new node(l,mid);
			ch[0]->insert(x);
		}
		else{
			if(ch[0]) ans+=ch[0]->sum;
			if(!ch[1]) ch[1]=new node(mid+1,r);
			ch[1]->insert(x);
		}
	}
};
node* merge(node* a,node* b){
	if(!a) return b;
	if(!b) return a;
	if(a->ch[0]&&a->ch[1])
		ans-=a->ch[0]->sum*a->ch[1]->s;
	if(b->ch[0]&&b->ch[1])
		ans-=b->ch[0]->sum*b->ch[1]->s;
	a->s+=b->s;
	a->sum+=b->sum;
	a->ch[0]=merge(a->ch[0],b->ch[0]);
	a->ch[1]=merge(a->ch[1],b->ch[1]);
	if(a->ch[0]&&a->ch[1])
		ans+=a->ch[0]->sum*a->ch[1]->s;
	delete b;
	return a;
}
node* rt[maxn*2];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<maxn*2;i++){
		fa[i]=i;
		s[i]=1;
		rt[i]=new node(1,n);
	}
	for(int i=1;i<=n;i++){
		int a,b;
		a=read();
		b=read();
		ans-=1ll*a*b;
		int x=find(a),y=x+s[x];
		ans-=rt[x]->sum*x+rt[y]->sum*y;
		rt[x]=merge(rt[x],rt[y]);
		rt[x]->insert(b);
		s[x]+=s[y];
		fa[y]=x;
		ans+=rt[x]->sum*x;
		printf("%lld\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}