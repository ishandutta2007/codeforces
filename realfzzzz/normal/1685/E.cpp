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
const int maxn=1e5+5;
int n,m,a[maxn*2],p[maxn*2];
struct data{
	int sum,pre,pos;
	data operator +(data b){
		if(pre<sum+b.pre) return {sum+b.sum,pre,pos};
		else return {sum+b.sum,sum+b.pre,b.pos};
	}
};
struct node{
	int l,r;
	node* ch[2];
	data val;
	void pushup(){
		val=ch[0]->val+ch[1]->val;
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			int k=a[r]==n+1?0:a[r]<=n?-1:1;
			val={k,k,r};
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void modify(int x,int k){
		if(l==r){
			val={k,k,x};
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	data query(int ql,int qr){
		if(ql>r||qr<l) return {0,n*2+1,0};
		if(ql<=l&&qr>=r) return val;
		return ch[0]->query(ql,qr)+ch[1]->query(ql,qr);
	}
}*rt;
ll s1=0,s2=0;
bool vis1[maxn*2],vis2[maxn*2];
void upd1(int x,int tp){
	if(vis1[x]==(tp>0)) return;
	vis1[x]=tp>0;
	s1+=(p[x==n+1?1:x+1]-p[x]+n*2+1)%(n*2+1)*tp;
}
void upd2(int x,int tp){
	if(vis2[x]==(tp>0)) return;
	vis2[x]=tp>0;
	s2+=(p[x==n*2+1?n+1:x+1]-p[x]+n*2+1)%(n*2+1)*tp;
}
void upd(int x,int y,int tp){
	if(x<=n+1){
		upd1(x,tp);
		upd1(x==1?n+1:x-1,tp);
	}
	if(x>=n+1){
		upd2(x,tp);
		upd2(x==n+1?n*2+1:x-1,tp);
	}
	if(y<=n+1){
		upd1(y,tp);
		upd1(y==1?n+1:y-1,tp);
	}
	if(y>=n+1){
		upd2(y,tp);
		upd2(y==n+1?n*2+1:y-1,tp);
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n*2+1;i++) p[a[i]=read()]=i;
	rt=new node(1,n*2+1);
	for(int i=1;i<=n+1;i++) upd1(i,1);
	for(int i=n+1;i<=n*2+1;i++) upd2(i,1);
	while(m--){
		int u,v;
		u=read();
		v=read();
		upd(a[u],a[v],-1);
		swap(a[u],a[v]);
		swap(p[a[u]],p[a[v]]);
		upd(a[u],a[v],1);
		rt->modify(u,a[u]==n+1?0:a[u]<=n?-1:1);
		rt->modify(v,a[v]==n+1?0:a[v]<=n?-1:1);
		data res=rt->query(p[n+1],n*2+1);
		if(res.pre<0||res.sum+rt->query(1,p[n+1]).pre<0)
			printf("%d\n",rt->val.pos%(n*2+1));
		else if(s1!=n*2+1) printf("%d\n",p[n+1]%(n*2+1));
		else if(s2!=n*2+1) printf("%d\n",p[n+1]-1);
		else printf("-1\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}