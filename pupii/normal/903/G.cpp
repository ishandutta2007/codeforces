#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int B[200010],A[200010];
std::vector<std::pair<int,int>>vec[200010];
ll seg[800010],tag[800010];
#define mid ((l+r)>>1)
void upd(int x,ll d){seg[x]+=d,tag[x]+=d;}
void down(int x){if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return upd(x,d);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=std::min(seg[x<<1],seg[x<<1|1]);
}
void build(int x,int l,int r){
	if(l==r){seg[x]=B[l];return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=std::min(seg[x<<1],seg[x<<1|1]);
}
ll right[200010];
std::multiset<ll>set;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),q=gi(),a,b,c;
	for(int i=1;i<n;++i)A[i]=gi(),B[i+1]=gi();
	build(1,1,n);
	for(int i=1;i<=m;++i)a=gi(),b=gi(),c=gi(),vec[a].push_back({b,c});
	for(int i=1;i<=n;++i){
		for(auto pr:vec[i])b=pr.first,c=pr.second,update(1,1,n,1,b,c);
		right[i]=seg[1];
		set.insert(A[i]+right[i]);
	}
	printf("%lld\n",*set.begin());
	while(q--){
		a=gi(),b=gi();
		set.erase(set.find(A[a]+right[a]));
		set.insert((A[a]=b)+right[a]);
		printf("%lld\n",*set.begin());
	}
	return 0;
}