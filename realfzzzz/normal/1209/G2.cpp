// LUOGU_RID: 90461255
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
int n,m,a[maxn];
set<int> s[maxn];
struct node{
	int l,r;
	node* ch[2];
	int mn=0,mx,lmx,rmx,sum,add=0;
	void pushup(){
		if(ch[0]->mn<ch[1]->mn){
			mn=ch[0]->mn;
			lmx=ch[0]->lmx;
			rmx=max(ch[0]->rmx,ch[1]->mx);
			sum=ch[0]->sum;
		}
		else if(ch[0]->mn>ch[1]->mn){
			mn=ch[1]->mn;
			lmx=max(ch[0]->mx,ch[1]->lmx);
			rmx=ch[1]->rmx;
			sum=ch[1]->sum;
		}
		else{
			mn=ch[0]->mn;
			lmx=ch[0]->lmx;
			rmx=ch[1]->rmx;
			sum=ch[0]->sum+ch[1]->sum+max(ch[0]->rmx,ch[1]->lmx);
		}
		mx=max(ch[0]->mx,ch[1]->mx);
	}
	node(int l,int r):l(l),r(r){
		if(l==r){
			mx=lmx=r==*s[a[r]].begin()?s[a[r]].size():0;
			rmx=sum=0;
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		pushup();
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
	void modify1(int ql,int qr,int k){
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		ch[0]->modify1(ql,qr,k);
		ch[1]->modify1(ql,qr,k);
		pushup();
	}
	void modify2(int x,int k){
		if(l==r){
			mx=lmx=k;
			return;
		}
		pushdown();
		ch[x>=ch[1]->l]->modify2(x,k);
		pushup();
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) s[a[i]=read()].insert(i);
	rt=new node(0,n);
	for(int i=1;i<maxn;i++) if(s[i].size())
		rt->modify1(*s[i].begin(),*--s[i].end()-1,1);
	printf("%d\n",n-rt->sum);
	while(m--){
		int x,k;
		x=read();
		k=read();
		rt->modify1(*s[a[x]].begin(),*--s[a[x]].end()-1,-1);
		rt->modify2(*s[a[x]].begin(),0);
		if(s[k].size()){
			rt->modify1(*s[k].begin(),*--s[k].end()-1,-1);
			rt->modify2(*s[k].begin(),0);
		}
		s[a[x]].erase(x);
		s[k].insert(x);
		if(s[a[x]].size()){
			rt->modify1(*s[a[x]].begin(),*--s[a[x]].end()-1,1);
			rt->modify2(*s[a[x]].begin(),s[a[x]].size());
		}
		rt->modify1(*s[k].begin(),*--s[k].end()-1,1);
		rt->modify2(*s[k].begin(),s[k].size());
		a[x]=k;
		printf("%d\n",n-rt->sum);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}