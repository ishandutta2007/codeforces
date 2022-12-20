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
int n,m;
ll a[maxn],w[maxn],v[maxn];
int ord[maxn],p[maxn];
const ll inf=9e18;
struct node{
	int l,r;
	node* ch[2];
	ll s1[60],s2[60],s3[60];
	void pushup(){
		for(int i=0;i<60;i++){
			s1[i]=ch[0]->s1[i]+ch[1]->s1[i];
			s2[i]=ch[0]->s2[i]+ch[1]->s2[i];
			s3[i]=ch[0]->s3[i];
			if(ch[1]->s3[i]<inf)
				s3[i]=min(s3[i],ch[0]->s1[i]+ch[1]->s3[i]);
		}
	}
	void upd(){
		int u=ord[r],d=60;
		while(!(w[u]>>d&1)) d--;
		for(int i=0;i<d;i++){
			s1[i]=s2[i]=0;
			s3[i]=inf;
		}
		s1[d]=s2[d]=0;
		s3[d]=a[u]?w[u]:inf;
		for(int i=d+1;i<60;i++){
			s1[i]=w[u]*a[u];
			s2[i]=v[u]*a[u];
			s3[i]=inf;
		}
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			upd();
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void modify(int x){
		if(l==r){
			upd();
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x);
		else ch[1]->modify(x);
		pushup();
	}
	void get(int ql,int qr,vector<node*>& vec){
		if(ql<=l&&qr>=r){
			vec.push_back(this);
			return;
		}
		if(ql<=ch[0]->r) ch[0]->get(ql,qr,vec);
		if(qr>=ch[1]->l) ch[1]->get(ql,qr,vec);
	}
	int query(int d,ll& c,ll& s){
		if(l==r){
			int u=ord[r];
			if(!(w[u]>>d&1)){
				ll t=c/w[u];
				c-=w[u]*t;
				s+=v[u]*t;
			}
			else if(c>=w[u]){
				c-=w[u];
				s+=v[u];
			}
			return r+1;
		}
		if(c>=ch[0]->s3[d]||c<=ch[0]->s1[d]) return ch[0]->query(d,c,s);
		else return ch[1]->query(d,c-=ch[0]->s1[d],s+=ch[0]->s2[d]);
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		w[i]=read();
		v[i]=read();
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		if(v[a]!=v[b]) return v[a]>v[b];
		return w[a]<w[b];
	});
	for(int i=1;i<=n;i++) p[ord[i]]=i;
	rt=new node(1,n);
	while(m--){
		int opt=read();
		if(opt==1){
			int k,d;
			k=read();
			d=read();
			a[d]+=k;
			rt->modify(p[d]);
		}
		else if(opt==2){
			int k,d;
			k=read();
			d=read();
			a[d]-=k;
			rt->modify(p[d]);
		}
		else{
			ll c=read(),ans=0;
			int d=60,x=1;
			while(d>=0&&!(c>>d&1)) d--;
			while(d>=0&&x<=n){
				vector<node*> vec;
				rt->get(x,n,vec);
				for(node* u:vec)
					if(c>=u->s3[d]||c<=u->s1[d]){
						x=u->query(d,c,ans);
						break;
					}
					else{
						c-=u->s1[d];
						ans+=u->s2[d];
						x=u->r+1;
					}
				while(d>=0&&!(c>>d&1)) d--;
			}
			printf("%lld\n",ans);
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}