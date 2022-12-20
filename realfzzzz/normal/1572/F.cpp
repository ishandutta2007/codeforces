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
int n,q;
struct node1{
	int l,r;
	node1* ch[2];
	ll sum,add=0;
	void pushup(){
		sum=ch[0]->sum+ch[1]->sum;
	}
	node1(int l,int r):l(l),r(r),sum(r-l+1){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node1(l,mid);
		ch[1]=new node1(mid+1,r);
	}
	void pushtag(ll k){
		sum+=k*(r-l+1);
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,ll k){
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,k);
		pushup();
	}
	ll query(int ql,int qr){
		if(ql<=l&&qr>=r) return sum;
		pushdown();
		ll ans=0;
		if(ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
		if(qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
		return ans;
	}
}*rt1;
struct node2{
	int l,r;
	node2* ch[2];
	int mx,mx2,cnt=1,add=0;
	void pushup(){
		if(ch[0]->mx>ch[1]->mx){
			mx=ch[0]->mx;
			mx2=max(ch[0]->mx2,ch[1]->mx);
			cnt=ch[0]->cnt;
		}
		else if(ch[0]->mx<ch[1]->mx){
			mx=ch[1]->mx;
			mx2=max(ch[1]->mx2,ch[0]->mx);
			cnt=ch[1]->cnt;
		}
		else{
			mx=ch[0]->mx;
			mx2=max(ch[0]->mx2,ch[1]->mx2);
			cnt=ch[0]->cnt+ch[1]->cnt;
		}
	}
	node2(int l,int r):l(l),r(r),mx(r),mx2(l==r?0:r-1){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node2(l,mid);
		ch[1]=new node2(mid+1,r);
	}
	void pushtag(int k){
		mx+=k;
		add+=k;
	}
	void pushdown(){
		if(ch[0]->mx>ch[1]->mx) ch[0]->pushtag(add);
		else if(ch[0]->mx<ch[1]->mx) ch[1]->pushtag(add);
		else{
			ch[0]->pushtag(add);
			ch[1]->pushtag(add);
		}
		add=0;
	}
	void modify1(int x,int k){
		if(l==r){
			rt1->modify(x,mx,-1);
			rt1->modify(x,mx=k,1);
			return;
		}
		pushdown();
		if(x<=ch[0]->r) ch[0]->modify1(x,k);
		else ch[1]->modify1(x,k);
		pushup();
	}
	void modify2(int ql,int qr,int k){
		if(k>=mx) return;
		if(ql<=l&&qr>=r&&k>=mx2){
			rt1->modify(k+1,mx,-cnt);
			pushtag(k-mx);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify2(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify2(ql,qr,k);
		pushup();
	}
}*rt2;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	rt1=new node1(1,n);
	rt2=new node2(1,n);
	while(q--){
		int p=readint();
		if(p==1){
			int c,g;
			c=readint();
			g=readint();
			rt2->modify1(c,g);
			if(c>1) rt2->modify2(1,c-1,c-1);
		}
		else{
			int l,r;
			l=readint();
			r=readint();
			printf("%lld\n",rt1->query(l,r));
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}