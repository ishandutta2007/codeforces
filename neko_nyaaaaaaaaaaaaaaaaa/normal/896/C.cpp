#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,seed,vmax;
struct node{
	int l,r;
	mutable ll x;
	bool operator < (const node &b)const{return l<b.l;}
};
set<node>S;
int rnd(){
	int ret=seed;
	seed=(seed*7ll+13)%1000000007;
	return ret;
}
typedef set<node>::iterator IT;
IT split(int l){
	IT x=S.lower_bound(node{l,l,1});
	if(x!=S.end()&&x->l==l)return x;
	--x;
	int l1=x->l,r=x->r;ll w=x->x;
	S.erase(x);
	S.insert(node{l1,l-1,w});
	return S.insert(node{l,r,w}).first;
}
void add(int l,int r,int x){
	IT l1=split(l),r1=split(r+1);
	for(;l1!=r1;l1++)l1->x+=x;
}
void assign(int l,int r,int x){
	IT l1=split(l),r1=split(r+1);
	S.erase(l1,r1);S.insert(node{l,r,x});
}
void rankx(int l,int r,int k){
	IT l1=split(l),r1=split(r+1);
	vector<pair<ll,int> > t;
	for(;l1!=r1;l1++)t.push_back(make_pair(l1->x,l1->r-l1->l+1));
	sort(t.begin(),t.end());
	ll ans=0;
	for(auto it:t){
		if(k<=it.second){ans=it.first;break;}
		else k-=it.second;
	}
	printf("%lld\n",ans);
}
int qpow(int a,int b,int mo){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
void sum(int l,int r,int x,int p){
	IT l1=split(l),r1=split(r+1);
	ll ans=0;
	for(;l1!=r1;l1++)(ans+=1ll*qpow(l1->x%p,x,p)*(l1->r-l1->l+1)%p)%=p;
	printf("%lld\n",ans);
}
int main(){
//	freopen("1.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;i++)
		S.insert(node{i,i,rnd()%vmax+1});
	S.insert(node{n+1,n+1,0});
	int op,l,r,x,y;
	for(int i=0;i<m;i++){
		op=rnd()%4+1;
		l=rnd()%n+1,r=rnd()%n+1;
		if(l>r)swap(l,r);
		if(op==3)x=(rnd()%(r-l+1))+1;
		else x=rnd()%vmax+1;
		if(op==4)y=rnd()%vmax+1;
		if(op==1)add(l,r,x);
		if(op==2)assign(l,r,x);
		if(op==3)rankx(l,r,x);
		if(op==4)sum(l,r,x,y);
	}
	return 0;
}