#include <stdio.h>
#include <algorithm>
#define MN 500000

const int INF = 0x3fffffff;

int n,q;
char str[MN+5];

struct Segment{
	bool ed;
	int len;
	Segment(){}
	Segment(bool arg1,int arg2){
		ed = arg1;
		len = arg2;
	}
};

struct Rnode{
	int ans;
	bool isComplete;
	Segment pre,suf;
};

struct Tnode{
	Rnode rnode[2];
	int flip,tag;
	Rnode& get(int x){
		return rnode[x^flip];
	}
}T[MN*4+5];

void construct(Rnode &node,int direction){
	node.ans = 1;
	node.isComplete = true;
	node.pre = Segment(direction,1);
	node.suf = Segment(direction,1);
}

void updateRnode(Rnode &node,const Rnode &ls,const Rnode &rs){
	if(ls.suf.ed == 0 && rs.pre.ed == 1){
		node.ans = std::max(ls.ans,rs.ans);
		node.isComplete = false;
		node.pre = ls.pre;
		node.suf = rs.suf;
	}else{
		node.ans = std::max({ls.ans,rs.ans,ls.suf.len+rs.pre.len});
		node.isComplete = (ls.isComplete && rs.isComplete);
		node.pre = ls.pre;
		if(ls.isComplete) node.pre.len += rs.pre.len;
		node.suf = rs.suf;
		if(rs.isComplete) node.suf.len += ls.suf.len;
	}
}

void updateTnode(int k){
	updateRnode(T[k].get(0),T[k<<1].get(0),T[k<<1|1].get(0));
	updateRnode(T[k].get(1),T[k<<1].get(1),T[k<<1|1].get(1));
}

void build(int k,int l,int r){
	if(l==r){
		construct(T[k].get(0),str[l]=='>');
		construct(T[k].get(1),str[l]=='<');
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	updateTnode(k);
}

void flipTnode(int k){
	T[k].flip ^= 1;
	T[k].tag ^= 1;
}

void pushdown(int k){
	if(T[k].tag){
		flipTnode(k<<1);
		flipTnode(k<<1|1);
		T[k].tag = 0;
	}
}

void flip(int k,int l,int r,int L,int R){
	if(l==L&&r==R){
		flipTnode(k);
		return;
	}
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) flip(k<<1,l,mid,L,R);
	else if(L>mid) flip(k<<1|1,mid+1,r,L,R);
	else{
		flip(k<<1,l,mid,L,mid);
		flip(k<<1|1,mid+1,r,mid+1,R);
	}
	updateTnode(k);
}

Rnode query(int k,int l,int r,int L,int R){
	if(l==L&&r==R){
		return T[k].get(0);
	}
	int mid = (l+r)>>1;
	pushdown(k);
	if(R<=mid) return query(k<<1,l,mid,L,R);
	else if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	else{
		Rnode node;
		updateRnode(node,query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
		return node;
	}
}

int main(){
	#ifdef LOCAL
		freopen("sample.in","r",stdin);
	#endif
	scanf("%d%d",&n,&q);
	scanf("%s",&str[1]);
	build(1,1,n);
	for(int l,r;q--;){
		scanf("%d%d",&l,&r);
		flip(1,1,n,l,r);
		printf("%d\n",query(1,1,n,l,r).ans);
	}
}