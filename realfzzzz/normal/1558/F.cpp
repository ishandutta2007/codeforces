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
int n,p[maxn];
struct node{
	int l,r;
	node* ch[2];
	int mx,add=0;
	void pushup(){
		mx=max(ch[0]->mx,ch[1]->mx);
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			mx=r-1+r%2-n*3;
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
	}
	void pushtag(int k){
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
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return mx;
		pushdown();
		int ans=0;
		if(ql<=ch[0]->r) ans=max(ans,ch[0]->query(ql,qr));
		if(qr>=ch[1]->l) ans=max(ans,ch[1]->query(ql,qr));
		return ans;
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
		for(int i=1;i<=n;i++) p[readint()]=i;
		rt=new node(1,n);
		set<int> s;
		for(int i=1;i<=n;i++) s.insert(i);
		int ans=0;
		for(int i=1;i<n;i++){
			rt->modify(p[i],p[i],n*3);
			if(p[i]>1) rt->modify(1,p[i]-1,1);
			if(p[i]<n) rt->modify(p[i]+1,n,-1);
			s.erase(p[i]);
			ans=max(ans,rt->query(*s.begin(),n));
		}
		printf("%d\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}