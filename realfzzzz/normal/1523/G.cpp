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
const int maxn=5e4+5,maxm=1e5+5;
int n,m,l[maxm],r[maxm];
vector<int> vec[maxn];
struct node{
	int l,r;
	node* ch[2];
	int mn=m+1;
	node(int l,int r):l(l),r(r){
		ch[0]=ch[1]=0;
	}
	void modify(int x,int k){
		mn=min(mn,k);
		if(l==r) return;
		int mid=l+(r-l)/2;
		if(x<=mid){
			if(!ch[0]) ch[0]=new node(l,mid);
			ch[0]->modify(x,k);
		}
		else{
			if(!ch[1]) ch[1]=new node(mid+1,r);
			ch[1]->modify(x,k);
		}
	}
	int query(int ql,int qr){
		if(ql<=l&&qr>=r) return mn;
		int ans=m+1;
		if(ch[0]&&ql<=ch[0]->r)
			ans=min(ans,ch[0]->query(ql,qr));
		if(ch[1]&&qr>=ch[1]->l)
			ans=min(ans,ch[1]->query(ql,qr));
		return ans;
	}
}*c[maxn];
void modify(int x,int y,int k){
	while(x<=n){
		c[x]->modify(y,k);
		x+=x&-x;
	}
}
int query(int x,int y){
	int s=m+1;
	while(x){
		s=min(s,c[x]->query(y,n));
		x-=x&-x;
	}
	return s;
}
int solve(int L,int R){
	int x=query(R,L);
	if(x>m) return 0;
	return solve(L,l[x]-1)+solve(r[x]+1,R)+r[x]-l[x]+1;
}
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		l[i]=read();
		r[i]=read();
		vec[r[i]-l[i]+1].push_back(i);
	}
	for(int i=1;i<=n;i++) c[i]=new node(1,n);
	for(int i=n;i>0;i--){
		for(int j:vec[i]) modify(r[j],l[j],j);
		ans[i]=solve(1,n);
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}