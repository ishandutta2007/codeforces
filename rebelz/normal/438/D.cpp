#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	int left,right,maxa;
	ll sum;
}t[300000];

int n,m;
int a[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void update(int id){t[id].maxa=max(t[id<<1].maxa,t[id<<1|1].maxa);t[id].sum=t[id<<1].sum+t[id<<1|1].sum;}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	if(l==r) return (void)(t[id].maxa=t[id].sum=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void modify(int id,int l,int r,int x){
	if(t[id].maxa<x) return;
	if(t[id].left==l&&t[id].right==r&&l==r) return (void)(t[id].sum%=x,t[id].maxa=t[id].sum);
	if(l<=t[id<<1].right) modify(id<<1,l,min(r,t[id<<1].right),x);
	if(r>=t[id<<1|1].left) modify(id<<1|1,max(l,t[id<<1|1].left),r,x);
	update(id);
}

ll query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return t[id].sum;
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	else return query(id<<1,l,t[id<<1].right)+query(id<<1|1,t[id<<1|1].left,r);
}

void change(int id,int p,int c){
	if(t[id].left==t[id].right) return (void)(t[id].maxa=t[id].sum=c);
	if(p<=t[id<<1].right) change(id<<1,p,c);
	else change(id<<1|1,p,c);
	update(id);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int opt,x,y,z;
	build(1,1,n);
	while(m--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1)
			printf("%lld\n",query(1,x,y));
		else if(opt==2){
			z=readint();
			modify(1,x,y,z);
		}
		else
			change(1,x,y);
	}
	return 0;
}