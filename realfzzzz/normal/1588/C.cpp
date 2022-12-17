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
const int maxn=3e5+5;
int n,a[maxn];
struct data{
	ll mn;
	int cnt;
	data operator +(const data b)const{
		if(mn<b.mn) return *this;
		else if(mn>b.mn) return b;
		else return {mn,cnt+b.cnt};
	}
};
const ll inf=9e18;
struct node{
	int l,r;
	node* ch[2];
	data v[3];
	ll add[2];
	void pushup(){
		v[0]=ch[0]->v[0]+ch[1]->v[0];
		v[1]=ch[0]->v[1]+ch[1]->v[1];
		v[2]=v[0]+v[1];
	}
	node(int l,int r):l(l),r(r){
		add[0]=add[1]=0;
		if(l==r){
			v[r%2]={0,1};
			v[!(r%2)]={inf,0};
			v[2]={0,1};
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void pushtag(bool d,ll k){
		if(v[d].mn<inf) v[d].mn+=k;
		v[2]=v[0]+v[1];
		add[d]+=k;
	}
	void pushdown(){
		ch[0]->pushtag(0,add[0]);
		ch[0]->pushtag(1,add[1]);
		ch[1]->pushtag(0,add[0]);
		ch[1]->pushtag(1,add[1]);
		add[0]=add[1]=0;
	}
	void modify(int ql,int qr,bool d,ll k){
		if(ql<=l&&qr>=r){
			pushtag(d,k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify(ql,qr,d,k);
		if(qr>=ch[1]->l) ch[1]->modify(ql,qr,d,k);
		pushup();
	}
	int query1(){
		if(l==r) return v[2].mn<0?r:r+1;
		pushdown();
		if(ch[0]->v[2].mn<0) return ch[0]->query1();
		else return ch[1]->query1();
	}
	data query2(int ql,int qr){
		if(ql<=l&&qr>=r) return v[2];
		pushdown();
		data ans={inf,0};
		if(ql<=ch[0]->r) ans=ans+ch[0]->query2(ql,qr);
		if(qr>=ch[1]->l) ans=ans+ch[1]->query2(ql,qr);
		return ans;
	}
	~node(){
		if(l==r) return;
		delete ch[0];
		delete ch[1];
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		ll ans=0;
		rt=new node(1,n);
		for(int i=n;i>0;i--){
			rt->modify(i,n,i%2,a[i]);
			rt->modify(i,n,!(i%2),-a[i]);
			int x=rt->query1();
			data res=rt->query2(i,x-1);
			if(!res.mn) ans+=res.cnt;
		}
		printf("%lld\n",ans);
		delete rt;
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}