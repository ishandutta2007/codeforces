#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r; mutable int v;
	node(int ll=0,int rr=0,int vv=0):l(ll),r(rr),v(vv){}
	bool operator<(const node c)const{return l<c.l;}
};

int n,q,ans;
set<node> s;

set<node>::iterator split(int x){
	auto it=s.lower_bound(node(x));
	if(it!=s.end()&&it->l==x) return it;
	it--;
	int l=it->l,r=it->r; ll v=it->v;
	s.erase(it);
	s.insert(node(l,x-1,v));
	return s.insert(node(x,r,v)).fi;
}

void cov(int l,int r,int v){
	auto en=split(r+1),st=split(l);
	for(auto it=st;it!=en;it++) ans-=it->v*(it->r-it->l+1);
	s.erase(st,en);
	s.insert(node(l,r,v));
	ans+=v*(r-l+1);
}

int main(){
	n=readint(); q=readint();
	s.insert(node(1,n,1)); ans=n;
	s.insert(node(n+1,n+1,0));
	int x,y,z;
	while(q--){
		x=readint(); y=readint(); z=readint();
		cov(x,y,z-1);
		printf("%d\n",ans);
	}
	return 0;
}