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
const int maxn=1e6+5;
int n,m,a[maxn],b[maxn],ord[maxn*2];
struct node{
	int l,r;
	node* ch[2];
	int mn,add=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r),mn(l){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(int k){
		mn+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,int k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
}*rt;
vector<int> q1[maxn*2];
int q2[maxn*2];
inline int lowbit(int x){
	return x&-x;
}
int c[maxn*2];
void modify(int x,int k){
	while(x<=n+m){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=m;i++) b[i]=readint();
		for(int i=1;i<=n;i++) ord[i]=a[i];
		for(int i=1;i<=m;i++) ord[n+i]=b[i];
		sort(ord+1,ord+n+m+1);
		for(int i=1;i<=n;i++) a[i]=lower_bound(ord+1,ord+n+m+1,a[i])-ord;
		for(int i=1;i<=m;i++) b[i]=lower_bound(ord+1,ord+n+m+1,b[i])-ord;
		for(int i=1;i<=n+m;i++){
			q1[i]={};
			q2[i]=0;
		}
		for(int i=1;i<=n;i++) q1[a[i]].push_back(i);
		for(int i=1;i<=m;i++) q2[b[i]]++;
		rt=new node(0,n);
		ll ans=0;
		for(int i=1;i<=n+m;i++){
			for(int x:q1[i]) rt->modify(x,n,-1);
			ans+=1ll*rt->mn*q2[i];
			for(int x:q1[i]) rt->modify(0,x-1,1);
		}
		for(int i=1;i<=n+m;i++) c[i]=0;
		for(int i=n;i>0;i--){
			ans+=query(a[i]-1);
			modify(a[i],1);
		}
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}