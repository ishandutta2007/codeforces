#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int mina,minax,num,lazy;
}t[2200000];

const int N=1000000;
int n,q;
int a[500005];

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy,t[id<<1|1].lazy+=t[id].lazy;
		t[id<<1].mina+=t[id].lazy,t[id<<1|1].mina+=t[id].lazy;
		t[id<<1].minax+=t[id].lazy,t[id<<1|1].minax+=t[id].lazy;
		t[id].lazy=0;
	}
}

void update(int id){
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
	if(t[id<<1].minax==t[id<<1|1].minax) t[id].minax=t[id<<1].minax,t[id].num=t[id<<1].num+t[id<<1|1].num;
	else if(t[id<<1].minax>t[id<<1|1].minax) t[id].minax=t[id<<1|1].minax,t[id].num=t[id<<1|1].num;
	else t[id].minax=t[id<<1].minax,t[id].num=t[id<<1].num;
}

void build(int id,int l,int r){
	t[id].mina=0,t[id].minax=1<<30;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr) return (void)(t[id].minax+=c,t[id].mina+=c,t[id].lazy+=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

void active(int id,int l,int r,int x,bool c){
	if(l==r){
		if(c) t[id].minax=t[id].mina,t[id].num=1;
		else t[id].minax=1<<30,t[id].num=0;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) active(id<<1,l,mid,x,c);
	else active(id<<1|1,mid+1,r,x,c);
	update(id);
}

int main(){
	n=readint(); q=readint();
	build(1,1,N);
	for(int i=1;i<=n;i++) a[i]=readint(),active(1,1,N,a[i],1);
	a[0]=N;
	for(int i=1;i<=n+1;i++) change(1,1,N,min(a[i],a[i-1])+1,max(a[i],a[i-1]),1);
	int x,y;
	while(q--){
		x=readint(); y=readint();
		change(1,1,N,min(y,a[x-1])+1,max(y,a[x-1]),1),change(1,1,N,min(a[x+1],y)+1,max(a[x+1],y),1);
		change(1,1,N,min(a[x],a[x-1])+1,max(a[x],a[x-1]),-1),change(1,1,N,min(a[x+1],a[x])+1,max(a[x+1],a[x]),-1);
		active(1,1,N,a[x],0);
		active(1,1,N,y,1);
		a[x]=y;
		printf("%d\n",t[1].num);
	}
	return 0;
}