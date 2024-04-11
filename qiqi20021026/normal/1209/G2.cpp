#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define ls (x<<1)
#define rs (x<<1|1)

int n,m,a[N];
set<int> se[N];

struct node{
	int p1,p2,sum,val,all;
	node(int a=0,int b=0,int c=0,int d=0):p1(a),p2(b),sum(c),val(d),all(d){}
}seg[N<<2];

void MAX(int &x,int y){x=max(x,y);}

void merge(node &p,int x,int l,int r){
	if (!seg[x].p1) return;
	if (l==r){
		if (p.p2>=seg[x].p1){
			MAX(p.p2,seg[x].p2);
			MAX(p.val,seg[x].all);
		}
		else{
			p.p1=seg[x].p1;
			p.p2=seg[x].p2;
			p.sum+=p.val;
			p.val=seg[x].val;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (p.p2>=seg[ls].p1){
		MAX(p.p2,seg[ls].p2);
		MAX(p.val,seg[ls].all);
		merge(p,rs,mid+1,r);
	}
	else{
		merge(p,ls,l,mid);
		p.p1=seg[x].p1;
		p.p2=seg[x].p2;
		p.sum+=seg[x].sum-seg[ls].sum;
		p.val=seg[x].val;
	}
}

void mdf(int x,int l,int r,int t,int k,int o){
	if (l==r){seg[x]=node(t*(k>0),k,0,o); return;}
	int mid=(l+r)>>1;
	if (t<=mid) mdf(ls,l,mid,t,k,o);
	else mdf(rs,mid+1,r,t,k,o);
	seg[x]=seg[ls];
	merge(seg[x],rs,mid+1,r);
	seg[x].all=max(seg[ls].all,seg[rs].all);
}

void ers(int i){
	int c=a[i];
	mdf(1,1,n,*se[c].begin(),0,0);
	se[c].erase(i);
	if (se[c].size())
		mdf(1,1,n,*se[c].begin(),*se[c].rbegin(),se[c].size());
}

void ins(int i){
	int c=a[i];
	if (se[c].size())
		mdf(1,1,n,*se[c].begin(),0,0);
	se[c].insert(i);
	mdf(1,1,n,*se[c].begin(),*se[c].rbegin(),se[c].size());
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		se[a[i]].insert(i);
	}
	for (int i=1;i<=200000;++i){
		if (se[i].empty()) continue;
		int x=*se[i].begin(),y=*se[i].rbegin(),z=se[i].size();
		mdf(1,1,n,x,y,z);
	}
	printf("%d\n",n-seg[1].sum-seg[1].val);
	for (int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		ers(x); a[x]=y; ins(x);
		printf("%d\n",n-seg[1].sum-seg[1].val);
	}
	
	return 0;
}