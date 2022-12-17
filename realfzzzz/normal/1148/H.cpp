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
int n;
struct node1{
	int l,r;
	node1* ch[2];
	int mn=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
	}
	node1(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node1(l,mid);
		ch[1]=new node1(mid+1,r);
	}
	void modify(int x,int k){
		if(l==r){
			mn=k;
			return;
		}
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
		pushup();
	}
	int query1(int ql,int qr){
		if(qr<l||ql>r) return n+1;
		if(ql<=l&&qr>=r) return mn;
		return min(ch[0]->query1(ql,qr),ch[1]->query1(ql,qr));
	}
	void get(int ql,int qr,vector<node1*>& vec){
		if(qr<l||ql>r) return;
		if(ql<=l&&qr>=r){
			vec.push_back(this);
			return;
		}
		ch[0]->get(ql,qr,vec);
		ch[1]->get(ql,qr,vec);
	}
	int query2(int x){
		if(l==r) return r;
		if(ch[0]->mn<x) return ch[0]->query2(x);
		else return ch[1]->query2(x);
	}
}*rt1;
struct node2{
	int l,r;
	node2* ch[2];
	ll sum=0,b=0,add=0,add2=0;
	void pushup(){
		sum=ch[0]->sum+ch[1]->sum+add*(r-l+1);
		b=ch[0]->b+ch[1]->b+add2*(r-l+1);
	}
	node2(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node2(l,mid);
		ch[1]=new node2(mid+1,r);
	}
	node2(node2* x){
		*this=*x;
	}
	void pushtag1(ll k){
		sum+=k*(r-l+1);
		add+=k;
	}
	void pushtag2(ll k){
		b+=k*(r-l+1);
		add2+=k;
	}
	void modify(int ql,int qr,ll k,int t){
		if(ql<=l&&qr>=r){
			pushtag1(k);
			pushtag2(k*(t-1));
			return;
		}
		if(ql<=ch[0]->r){
			ch[0]=new node2(ch[0]);
			ch[0]->modify(ql,qr,k,t);
		}
		if(qr>=ch[1]->l){
			ch[1]=new node2(ch[1]);
			ch[1]->modify(ql,qr,k,t);
		}
		pushup();
	}
	ll query(int ql,int qr,int t){
		if(qr<l||ql>r) return 0;
		if(ql<=l&&qr>=r) return sum*t-b;
		ll res=(add*t-add2)*(min(qr,r)-max(ql,l)+1);
		return res+ch[0]->query(ql,qr,t)+ch[1]->query(ql,qr,t);
	}
};
vector<int> vec[maxn];
vector<node2*> rt2[maxn];
void modify(int a,int l,int r,int k,int t){
	vec[a].push_back(t);
	rt2[a].push_back(new node2(rt2[a].back()));
	rt2[a].back()->modify(l,r,k,t);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	rt1=new node1(0,n);
	for(int i=0;i<=n;i++) vec[i].push_back(0);
	rt2[0].push_back(new node2(1,n));
	for(int i=1;i<=n;i++) rt2[i].push_back(rt2[0][0]);
	ll lans=0;
	for(int i=1;i<=n;i++){
		int a,l,r,k;
		a=(read()+lans)%(n+1);
		l=(read()+lans)%i+1;
		r=(read()+lans)%i+1;
		if(l>r) swap(l,r);
		k=(read()+lans)%(n+1);
		modify(0,i,i,1,i);
		int l2=rt1->query1(a,a)+1,r2=a?rt1->query1(0,a-1):i;
		if(l2<=r2){
			modify(a,l2,r2,-1,i);
			while(l2<=r2){
				vector<node1*> vec;
				rt1->get(a+1,n,vec);
				for(node1* u:vec) if(u->mn<r2){
					int x=u->query2(r2),k=u->query1(x,x);
					modify(x,max(k+1,l2),r2,1,i);
					r2=k;
					break;
				}
			}
		}
		rt1->modify(a,i);
		printf("%lld\n",lans=rt2[k][upper_bound(vec[k].begin(),vec[k].end(),r)-vec[k].begin()-1]->query(l,r,r));
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}