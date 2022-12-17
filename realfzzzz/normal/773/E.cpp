// LUOGU_RID: 96630972
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
const int maxn=5e5+5;
int n,a[maxn],ord[maxn],rk[maxn];
struct node{
	int l,r;
	node* ch[2];
	int mn=maxn*2,add=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r){
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
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		ch[0]->modify(ql,qr,k);
		ch[1]->modify(ql,qr,k);
		pushup();
	}
	int query1(int ql,int qr){
		if(ql>r||qr<l) return maxn*2;
		if(ql<=l&&qr>=r) return mn;
		pushdown();
		return min(ch[0]->query1(ql,qr),ch[1]->query1(ql,qr));
	}
	int query2(){
		if(l==r) return r;
		pushdown();
		return ch[ch[1]->mn<0]->query2();
	}
}*rt1,*rt2;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int x,int y){
		return a[x]<a[y];
	});
	for(int i=1;i<=n;i++) rk[ord[i]]=i;
	rt1=new node(0,n+1);
	rt2=new node(0,n+1);
	rt1->modify(0,0,1-maxn*2);
	rt2->modify(0,0,-1-maxn*2);
	for(int i=1;i<=n;i++){
		rt1->modify(rk[i]+1,n+1,-1);
		rt1->modify(rk[i],rk[i],a[i]-maxn*2);
		rt2->modify(rk[i]+1,n+1,1);
		rt2->modify(rk[i],rk[i],a[i]-maxn*2);
		int x=rt2->query2();
		printf("%d\n",min(rt1->query1(x+1,n+1),-(a[ord[x]]-rt1->query1(x,x))*2-1)+i-1);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}