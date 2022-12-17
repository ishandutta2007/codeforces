#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
int n,m,s,t;
struct edge{
	int v,w;
};
vector<edge> g[maxn];
const int mod=1e9+7;
int pw[maxn*2];
ll M=0;
struct node{
	node* ch[2];
	int ls,hs=0;
	bool tag=0;
	void pushup(int l,int r){
		int mid=l+(r-l)/2;
		hs=(ch[0]->hs+ch[1]->hs)%mod;
		ls=ch[0]->ls==mid?ch[1]->ls:ch[0]->ls;
	}
	node(int l,int r):ls(l-1){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	node(node* x){
		*this=*x;
	}
	void pushtag(int l,int r){
		hs=0;
		ls=l-1;
		tag=1;
	}
	void pushdown(int l,int r){
		if(tag){
			int mid=l+(r-l)/2;
			ch[0]=new node(ch[0]);
			ch[0]->pushtag(l,mid);
			ch[1]=new node(ch[1]);
			ch[1]->pushtag(mid+1,r);
			tag=0;
		}
	}
	void modify1(int ql,int qr,int l,int r){
		if(ql<=l&&qr>=r){
			pushtag(l,r);
			return;
		}
		pushdown(l,r);
		int mid=l+(r-l)/2;
		if(ql<=mid){
			ch[0]=new node(ch[0]);
			ch[0]->modify1(ql,qr,l,mid);
		}
		if(qr>mid){
			ch[1]=new node(ch[1]);
			ch[1]->modify1(ql,qr,mid+1,r);
		}
		pushup(l,r);
	}
	void modify2(int x,int l,int r){
		if(l==r){
			ls=r;
			hs=pw[r];
			return;
		}
		pushdown(l,r);
		int mid=l+(r-l)/2;
		if(x<=mid){
			ch[0]=new node(ch[0]);
			ch[0]->modify2(x,l,mid);
		}
		else{
			ch[1]=new node(ch[1]);
			ch[1]->modify2(x,mid+1,r);
		}
		pushup(l,r);
	}
	int query(int x,int l,int r){
		if(l==r) return ls;
		pushdown(l,r);
		int mid=l+(r-l)/2;
		if(x<=mid){
			int res=ch[0]->query(x,l,mid);
			return res==mid?ch[1]->ls:res;
		}
		else return ch[1]->query(x,mid+1,r);
	}
}*rt[maxn];
int cmp(node* a,node* b,int l,int r){
	if(l==r){
		if(a->hs!=b->hs) return a->hs?-1:1;
		return 0;
	}
	a->pushdown(l,r);
	b->pushdown(l,r);
	int mid=l+(r-l)/2;
	if(a->ch[1]->hs!=b->ch[1]->hs)
		return cmp(a->ch[1],b->ch[1],mid+1,r);
	else return cmp(a->ch[0],b->ch[0],l,mid);
}
struct cmp2{
	bool operator ()(int a,int b){
		int res=cmp(rt[a],rt[b],0,maxn*2-1);
		if(res) return res>0;
		return a<b;
	}
};
int p[maxn];
int main(){
	n=readint();
	m=readint();
	for(int i=0;i<m;i++){
		int s,t,x;
		s=readint();
		t=readint();
		x=readint();
		g[s].push_back({t,x});
		g[t].push_back({s,x});
	}
	s=readint();
	t=readint();
	pw[0]=1;
	for(int i=1;i<maxn*2;i++) pw[i]=1ll*pw[i-1]*2%mod;
	set<int,cmp2> pq={s};
	rt[s]=new node(0,maxn*2-1);
	while(pq.size()){
		int u=*pq.begin();
		pq.erase(pq.begin());
		for(edge e:g[u]){
			rt[0]=new node(rt[u]);
			int res=rt[0]->query(e.w,0,maxn*2-1);
			if(res>=e.w) rt[0]->modify1(e.w,res,0,maxn*2-1);
			rt[0]->modify2(res+1,0,maxn*2-1);
			if(!rt[e.v]||cmp(rt[0],rt[e.v],0,maxn*2-1)>0){
				if(rt[e.v]) pq.erase(e.v);
				rt[e.v]=rt[0];
				p[e.v]=u;
				pq.insert(e.v);
			}
		}
	}
	if(!rt[t]){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",rt[t]->hs);
	int u=t;
	vector<int> ans;
	while(u!=s){
		ans.push_back(u);
		u=p[u];
	}
	printf("%d\n%d ",(int)ans.size()+1,s);
	for(int i=(int)ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}