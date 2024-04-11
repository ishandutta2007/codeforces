#include <stdio.h>
#include <algorithm>
#include <map>
#define MN 400000

int n,ans=0;

std::map<int,int> mp;

struct Segment{
	int l,r,col;
}s[MN+5];

struct STree{
	struct node{
		int max,tag;
	}T[MN*4+5];
	
	void pushtag(int k,int w){
		T[k].max += w;
		T[k].tag += w;
	}
	
	void pushdown(int k){
		if(T[k].tag){
			pushtag(k<<1,T[k].tag);
			pushtag(k<<1|1,T[k].tag);
			T[k].tag = 0;
		}
	}
	
	void add(int k,int l,int r,int L,int R,int w){
		if(L>R) return;
		if(l==L&&r==R){
			pushtag(k,w);
			return;
		}
		int mid = (l+r)>>1;
		pushdown(k);
		if(R<=mid) add(k<<1,l,mid,L,R,w);
		else if(L>mid) add(k<<1|1,mid+1,r,L,R,w);
		else add(k<<1,l,mid,L,mid,w),add(k<<1|1,mid+1,r,mid+1,R,w);
		T[k].max = std::max(T[k<<1].max,T[k<<1|1].max);
	}
	
	void update(int k,int l,int r,int p,int w){
		if(l==r){
			T[k].max = std::max(T[k].max,w);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(k);
		if(p<=mid) update(k<<1,l,mid,p,w);
		else update(k<<1|1,mid+1,r,p,w);
		T[k].max = std::max(T[k<<1].max,T[k<<1|1].max);
	}
	
	int query(int k,int l,int r,int L,int R){
		if(l==L&&r==R){
			return T[k].max;
		}
		int mid = (l+r)>>1;
		pushdown(k);
		if(R<=mid) return query(k<<1,l,mid,L,R);
		if(L>mid) return query(k<<1|1,mid+1,r,L,R);
		return std::max(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
	}
	
}ST[2];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].col);
		mp[s[i].l] = 0;
		mp[s[i].r] = 0;
		s[i].col--;
	}
	for(auto &x:mp){
		static int id = 1;
		x.second = id++;
	}
	for(int i=1;i<=n;i++){
		s[i].l = mp[s[i].l];
		s[i].r = mp[s[i].r];
	}
	std::sort(s+1,s+1+n,[](Segment a,Segment b)->bool{
		return a.r<b.r;
	});
	for(int i=1;i<=n;i++){
		int c = s[i].col;
		ST[c].add(1,1,MN,1,s[i].l,1);
		int tans = ST[c].query(1,1,MN,1,s[i].r);
		ST[c^1].update(1,1,MN,s[i].r+1,tans);
		ans = std::max(ans,tans);
	}
	printf("%d\n",ans);
}