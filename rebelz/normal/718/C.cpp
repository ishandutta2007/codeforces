#include<bits/stdc++.h>

using namespace std;

const int cys=1000000007;
typedef long long ll;

int n,m;
ll a[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct matrix{
	ll a[5][5];
	matrix operator*(const matrix x)const{
		matrix ans;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				ans.a[i][j]=0;
				for(int k=1;k<=2;k++)
					ans.a[i][j]=(ans.a[i][j]+a[i][k]*x.a[k][j]%cys)%cys;
			}
		}
		return ans;
	}
}c,k;

struct node{
	int left,right;
	ll sum,xsum; matrix lazy;
}t[300000];

matrix power(int p){
	matrix ret=c,now=k;
	for(;p;p>>=1,now=now*now) if(p&1) ret=ret*now;
	return ret;
}

matrix f(int p){
	matrix ret;
	ret.a[1][1]=1; ret.a[1][2]=ret.a[2][1]=ret.a[2][2]=0;
	if(p==1) return ret; ret.a[1][2]=1;
	if(p==2) return ret; p-=2;
	return ret*power(p);
}

node mark(int id){
	node ret=t[id];
	ret.sum=(t[id].sum*t[id].lazy.a[1][1]%cys+t[id].xsum*t[id].lazy.a[2][1]%cys)%cys;
	ret.xsum=(t[id].sum*t[id].lazy.a[1][2]%cys+t[id].xsum*t[id].lazy.a[2][2]%cys)%cys;
	return ret;
}

void pushdown(int id){t[id]=mark(id); t[id<<1].lazy=t[id<<1].lazy*t[id].lazy,t[id<<1|1].lazy=t[id<<1|1].lazy*t[id].lazy; t[id].lazy=c;}
void pushup(int id){node lson=mark(id<<1),rson=mark(id<<1|1); t[id].sum=(lson.sum+rson.sum)%cys; t[id].xsum=(lson.xsum+rson.xsum)%cys;}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r,t[id].lazy=c;
	if(l==r){
		matrix tmp=f(a[l]); t[id].sum=tmp.a[1][1],t[id].xsum=tmp.a[1][2];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	pushup(id);
}

void change(int id,int l,int r,matrix x){
	if(t[id].left==l&&t[id].right==r) return (void)(t[id].lazy=t[id].lazy*x);
	pushdown(id);
	if(t[id<<1].right>=r) change(id<<1,l,r,x);
	else if(t[id<<1|1].left<=l) change(id<<1|1,l,r,x);
	else change(id<<1,l,t[id<<1].right,x),change(id<<1|1,t[id<<1|1].left,r,x);
	pushup(id);
}

ll query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return mark(id).sum;
	pushdown(id);
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	else return (query(id<<1,l,t[id<<1].right)+query(id<<1|1,t[id<<1|1].left,r))%cys;
}

int main(){
	c.a[1][1]=c.a[2][2]=1; c.a[1][2]=c.a[2][1]=0; k.a[1][1]=k.a[2][1]=k.a[1][2]=1; k.a[2][2]=0;
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	int opt,x,y,z;
	for(int i=1;i<=m;i++){
		opt=readint(); x=readint(); y=readint();
		if(opt==1){
			z=readint();
			change(1,x,y,power(z));
		}
		else printf("%lld\n",query(1,x,y));
	}
	return 0;
}