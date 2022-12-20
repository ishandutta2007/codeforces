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
const int maxn=2e5+5;
int n,a[maxn];
vector<int> q[maxn];
int ans[maxn];
struct node{
	int l,r;
	node* ch[2];
	int mn,mx,add;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
		mx=max(ch[0]->mx,ch[1]->mx);
	}
	node(int l,int r):l(l),r(r),mn(l),mx(r),add(0){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(int k){
		mn+=k;
		mx+=k;
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
	int querymx(int ql,int qr){
		if(ql<=l&&qr>=r) return mx;
		pushdown();
		int ans=-n;
		if(ql<=ch[0]->r) ans=max(ans,ch[0]->querymx(ql,qr));
		if(qr>=ch[1]->l) ans=max(ans,ch[1]->querymx(ql,qr));
		return ans;
	}
	int querymn(int ql,int qr){
		if(ql<=l&&qr>=r) return mn;
		pushdown();
		int ans=n;
		if(ql<=ch[0]->r) ans=min(ans,ch[0]->querymn(ql,qr));
		if(qr>=ch[1]->l) ans=min(ans,ch[1]->querymn(ql,qr));
		return ans;
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) q[a[i]=readint()].push_back(i);
	rt=new node(0,n);
	for(int i=1;i<=n;i++){
		for(int j:q[i]) ans[j]=(rt->querymx(j,n)-rt->querymn(0,j-1))/2;
		for(int j:q[i]) rt->modify(j,n,-2);
		for(int j:q[i]) ans[j]=max(ans[j],(-rt->querymn(j,n)+rt->querymx(0,j-1)-1)/2);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}