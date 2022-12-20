#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=1.5e5+5;
int n,p[maxn];
typedef long long ll;
struct node{
	int l,r;
	node* ch[2];
	int s=0,mx=0,mx2=0,cnt=0,add1=0,add2=0;
	ll sum=0;
	void pushup(){
		s=ch[0]->s+ch[1]->s;
		sum=ch[0]->sum+ch[1]->sum;
		if(ch[0]->mx>ch[1]->mx){
			mx=ch[0]->mx;
			mx2=max(ch[0]->mx2,ch[1]->mx);
			cnt=ch[0]->cnt;
		}
		else if(ch[0]->mx<ch[1]->mx){
			mx=ch[1]->mx;
			mx2=max(ch[0]->mx,ch[1]->mx2);
			cnt=ch[1]->cnt;
		}
		else{
			mx=ch[0]->mx;
			mx2=max(ch[0]->mx2,ch[1]->mx2);
			cnt=ch[0]->cnt+ch[1]->cnt;
		}
	}
	node(int l,int r):l(l),r(r){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag1(int k){
		if(mx) mx+=k;
		if(mx2) mx2+=k;
		sum+=1ll*s*k;
		add1+=k;
	}
	void pushtag2(int k){
		mx+=k;
		sum+=1ll*cnt*k;
		add2+=k;
	}
	void pushdown(){
		ch[0]->pushtag1(add1);
		ch[1]->pushtag1(add1);
		add1=0;
		if(ch[0]->mx>ch[1]->mx) ch[0]->pushtag2(add2);
		else if(ch[0]->mx<ch[1]->mx) ch[1]->pushtag2(add2);
		else{
			ch[0]->pushtag2(add2);
			ch[1]->pushtag2(add2);
		}
		add2=0;
	}
	void modify1(int x,int k){
		if(l==r){
			s=cnt=1;
			sum=mx=k;
			return;
		}
		pushdown();
		if(x<=ch[0]->r) ch[0]->modify1(x,k);
		else ch[1]->modify1(x,k);
		pushup();
	}
	void modify2(int ql,int qr,int k){
		if(ql<=l&&qr>=r){
			pushtag1(k);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify2(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify2(ql,qr,k);
		pushup();
	}
	void modify3(int ql,int qr,int k){
		if(k>=mx) return;
		if(ql<=l&&qr>=r&&k>mx2){
			pushtag2(k-mx);
			return;
		}
		pushdown();
		if(ql<=ch[0]->r) ch[0]->modify3(ql,qr,k);
		if(qr>=ch[1]->l) ch[1]->modify3(ql,qr,k);
		pushup();
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return s;
		pushdown();
		int ans=0;
		if(ql<=ch[0]->r) ans+=ch[0]->query(ql,qr);
		if(qr>=ch[1]->l) ans+=ch[1]->query(ql,qr);
		return ans;
	}
	~node(){
		if(l==r) return;
		delete ch[0];
		delete ch[1];
	}
}*rt;
ll ans[maxn];
void work(){
	rt=new node(1,n);
	for(int i=1;i<=n;i++){
		rt->modify1(p[i],i+1);
		if(p[i]<n) rt->modify2(p[i]+1,n,1);
		if(p[i]>1) rt->modify3(1,p[i]-1,rt->query(1,p[i]-1)+1);
		ans[i]+=rt->sum;
	}
	delete rt;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) p[readint()]=i;
	work();
	for(int i=1;i<=n;i++) p[i]=n-p[i]+1;
	work();
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]-1ll*i*(i+2));
	return 0;
}