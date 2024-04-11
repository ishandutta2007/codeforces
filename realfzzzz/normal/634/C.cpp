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
const int maxn=2e5+5;
int n,k,a,b,q;
struct node{
	int l,r;
	node* ch[2];
	int sum=0;
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void modify(int x,int k){
		sum+=k;
		if(l==r) return;
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return sum;
		int ans=0;
		if(ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
		if(qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
		return ans;
	}
}*rt1,*rt2,*rt3,*rt4;
int s[maxn];
void modify(int x,int f){
	if(s[x]<=a) rt1->modify(x,s[x]*f);
	else rt2->modify(x,f);
	if(s[x]<=b) rt3->modify(x,s[x]*f);
	else rt4->modify(x,f);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	a=readint();
	b=readint();
	q=readint();
	rt1=new node(1,n);
	rt2=new node(1,n);
	rt3=new node(1,n);
	rt4=new node(1,n);
	while(q--){
		int opt=readint();
		if(opt==1){
			int d,a;
			d=readint();
			a=readint();
			modify(d,-1);
			s[d]+=a;
			modify(d,1);
		}
		else{
			int p=readint(),ans=0;
			if(p+k<=n) ans+=rt1->query(p+k,n)+rt2->query(p+k,n)*a;
			if(p>1) ans+=rt3->query(1,p-1)+rt4->query(1,p-1)*b;
			printf("%d\n",ans);
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}