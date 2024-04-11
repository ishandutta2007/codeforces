#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=5e5+50;
const int inf=0x3f3f3f3f;
int n,m;
int A[maxn],last[maxn],tmp[maxn];
struct ques{int id,x;};
vector<ques>que[maxn];
int ans[maxn];
struct segment_tree{
	struct node{
		int l,r;
		pii mi;
	}tree[maxn<<2];
	void push_up(int p){tree[p].mi=min(tree[p<<1].mi,tree[p<<1|1].mi);}
	void build(int p,int l,int r){
		tree[p].mi=(pii){l,inf},tree[p].l=l,tree[p].r=r;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
	}
	void update(int p,int l,int r,int x,int v){
		if(l==r){
			tree[p].mi=(pii){v,l};
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)update(p<<1,l,mid,x,v);
		else update(p<<1|1,mid+1,r,x,v);
		push_up(p);
	}
	pii query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return tree[p].mi;
		int mid=(l+r)>>1;
		if(qr<=mid)return query(p<<1,l,mid,ql,qr);
		else if(mid<ql)return query(p<<1|1,mid+1,r,ql,qr);
		return min(query(p<<1,l,mid,ql,qr),query(p<<1|1,mid+1,r,ql,qr));
	}
	void dfs(int p){
		if(tree[p].l==tree[p].r){
			if(tree[p].l<=10)printf("mi[%d]=%d\n",tree[p].l,tree[p].mi);
			return;
		}
		dfs(p<<1);
		dfs(p<<1|1);
	}
}T;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<maxn;i++)last[i]=0;
	for(int i=1;i<=n;i++){
		tmp[i]=last[A[i]];
		last[A[i]]=i;
	}
	T.build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>r)swap(l,r);
		que[r].push_back((ques){i,l});
	}
	for(int i=1;i<=n;i++){
		T.update(1,1,n,i,tmp[i]);
		if(tmp[i])T.update(1,1,n,tmp[i],inf);
		//T.dfs(1);
		for(int j=0;j<que[i].size();j++){
			ques e=que[i][j];
			pii res=T.query(1,1,n,e.x,i);
			//if(e.id==2)printf("e.x=%d\n",e.x);
			if(res.first>=e.x)ans[e.id]=0;
			else ans[e.id]=A[res.second];
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}