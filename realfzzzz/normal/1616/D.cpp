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
const int maxn=5e4+5;
int n,x,a[maxn];
struct node{
	int l,r;
	node* ch[2];
	ll mn=0,add=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(ll k){
		mn+=k;
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
		if(ql<=l&&qr>=r) return mn;
		pushdown();
		ll ans=9e18;
		if(ql<=ch[0]->r) ans=min(ans,ch[0]->query(ql,qr));
		if(qr>=ch[1]->l) ans=min(ans,ch[1]->query(ql,qr));
		return ans;
	}
	~node(){
		if(l==r) return;
		delete ch[0];
		delete ch[1];
	}
}*rt;
int f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		x=readint();
		for(int i=1;i<=n;i++) a[i]-=x;
		rt=new node(1,n);
		int l=1;
		multiset<int> s={0};
		for(int i=1;i<=n;i++){
			s.insert(f[i-1]-i);
			rt->modify(1,i,a[i]);
			while(l<i&&rt->query(l,i-1)<0){
				if(l==1) s.erase(s.find(0));
				else s.erase(s.find(f[l-2]-l+1));
				l++;
			}
			f[i]=max(f[i-1],i+*--s.end());
		}
		printf("%d\n",f[n]);
		delete rt;
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}