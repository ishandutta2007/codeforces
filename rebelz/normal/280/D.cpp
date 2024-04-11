#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,x;
	node(int l=0,int r=0,int x=0):l(l),r(r),x(x){}
	bool operator<(const node c)const{return x<c.x;}
	bool operator>(const node c)const{return x>c.x;}
	node operator+(const node c)const{return node(l,c.r,x+c.x);}
	node f(){return node(l,r,-x);}
};

struct seg{
	node minl,minr,maxl,maxr,mina,maxa,sum;
	bool rev;
	seg operator+(const seg c)const{
		seg ret;
		ret.minl=min(minl,sum+c.minl),ret.maxl=max(maxl,sum+c.maxl);
		ret.minr=min(c.minr,minr+c.sum),ret.maxr=max(c.maxr,maxr+c.sum);
		ret.mina=min(min(mina,c.mina),minr+c.minl);
		ret.maxa=max(max(maxa,c.maxa),maxr+c.maxl);
		ret.sum=sum+c.sum,ret.rev=0;
		return ret;
	}
}t[300000];

int n,m,ans;
stack<node> q;
int a[100005];

void build(int id,int l,int r){
	if(l==r){
		t[id].minl=t[id].minr=t[id].maxl=t[id].maxr=t[id].mina=t[id].maxa=t[id].sum=node(l,r,a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]+t[id<<1|1];
}

void reverse(int id){
	seg ret;
	ret.rev=t[id].rev^1;
	ret.minl=t[id].maxl.f(),ret.minr=t[id].maxr.f();
	ret.maxl=t[id].minl.f(),ret.maxr=t[id].minr.f();
	ret.mina=t[id].maxa.f(),ret.maxa=t[id].mina.f();
	ret.sum=t[id].sum.f();
	t[id]=ret;
}

void pushdown(int id){
	if(t[id].rev){
		reverse(id<<1),reverse(id<<1|1);
		t[id].rev^=1;
	}
}

void change(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return reverse(id);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr);
	else change(id<<1,l,mid,ql,mid),change(id<<1|1,mid+1,r,mid+1,qr);
	t[id]=t[id<<1]+t[id<<1|1];
}

void update(int id,int l,int r,int p,int x){
	if(l==r){
		t[id].minl=t[id].minr=t[id].maxl=t[id].maxr=t[id].mina=t[id].maxa=t[id].sum=node(l,r,x);
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(p<=mid) update(id<<1,l,mid,p,x);
	else update(id<<1|1,mid+1,r,p,x);
	t[id]=t[id<<1]+t[id<<1|1];
}

seg query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id];
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	m=readint();
	int opt,x,y,z; seg tmp;
	while(m--){
		opt=readint(); x=readint(); y=readint();
		if(opt==0) update(1,1,n,x,y);
		else{
			z=readint();
			ans=0;
			while(z--){
				tmp=query(1,1,n,x,y);
				if(tmp.maxa.x<0) break;
				ans+=tmp.maxa.x;
				q.push(tmp.maxa);
				change(1,1,n,tmp.maxa.l,tmp.maxa.r);
			}
			while(!q.empty()){
				change(1,1,n,q.top().l,q.top().r);
				q.pop();
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}