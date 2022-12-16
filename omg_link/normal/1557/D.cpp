#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#define MN 300000
#define ML 600000

using std::map;
using std::max;
using std::vector;

struct Interval{
	int l,r;
};

struct State{
	int id,f;
	State(){
		id = f = 0;
	}
	bool operator < (const State& that)const{
		return this->f < that.f;
	}
};

struct Node{
	State mx,tag;
};

int n,m,len,frm[MN+5];
vector<Interval> l[MN+5];
Node T[ML*4+5];

void lsh(){
	map<int,int> mp;
	for(int i=1;i<=n;i++)
		for(Interval it:l[i])
			mp[it.l],mp[it.r];
	len = 0;
	for(auto& p:mp)
		p.second = ++len;
	for(int i=1;i<=n;i++)
		for(Interval& it:l[i]){
			it.l = mp[it.l];
			it.r = mp[it.r];
		}
}

void pushtag(int k,State w){
	T[k].tag = max(T[k].tag,w);
	T[k].mx = max(T[k].mx,w);
}

void pushdown(int k){
	if(T[k].tag.f){
		pushtag(k<<1,T[k].tag);
		pushtag(k<<1|1,T[k].tag);
		T[k].tag.f = 0;
	}
}

void modify(int k,int l,int r,int L,int R,State w){
	if(l==L&&r==R){
		pushtag(k,w);
		return;
	}
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) modify(k<<1,l,mid,L,R,w);
	else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
	else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
	T[k].mx = max(T[k<<1].mx,T[k<<1|1].mx);
}

State query(int k,int l,int r,int L,int R){
	if(l==L&&r==R) return T[k].mx;
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) return query(k<<1,l,mid,L,R);
	if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	return max(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int id,l,r;
		scanf("%d%d%d",&id,&l,&r);
		::l[id].push_back({l,r});
	}
	lsh();
	State ans;
	for(int i=1;i<=n;i++){
		State s;
		for(Interval it:l[i])
			s = max(s,query(1,1,len,it.l,it.r));
		frm[i] = s.id;
		s.f++;
		s.id = i;
		ans = max(ans,s);
		for(Interval it:l[i])
			modify(1,1,len,it.l,it.r,s);
	}
	vector<int> ansa;
	int lst = n+1;
	for(int i=ans.id;lst;i=frm[i]){
		for(int j=lst-1;j>i;j--)
			ansa.push_back(j);
		lst = i;
	}
	printf("%d\n",(int)ansa.size());
	for(int x:ansa)
		printf("%d ",x);
	puts("");
}