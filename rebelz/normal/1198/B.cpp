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
	int lazy;
}t[600000];

int n,q;
int a[200005];

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].lazy=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy=max(t[id<<1].lazy,t[id].lazy);
		t[id<<1|1].lazy=max(t[id<<1|1].lazy,t[id].lazy);
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(t[id].lazy=c);
	int mid=(l+r)/2;
	pushdown(id);
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
}

void calc(int id,int l,int r,int x){
	if(l==r) return (void)(printf("%d ",max(x,t[id].lazy)));
	int mid=(l+r)/2;
	calc(id<<1,l,mid,max(x,t[id].lazy));
	calc(id<<1|1,mid+1,r,max(x,t[id].lazy));
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	q=readint();
	int opt,x;
	while(q--){
		opt=readint(); x=readint();
		if(opt==1) change(1,1,n,x,readint());
		else t[1].lazy=max(t[1].lazy,x);
	}
	calc(1,1,n,0);
	puts("");
	return 0;
}