#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int ans,l0,l1,r0,r1;
	ll lf,rg,lazy;
}t[1100000];

int n,m;
ll a[300005];

void update(int id,int l,int mid,int r){
	t[id].lf=t[id<<1].lf,t[id].rg=t[id<<1|1].rg;
	t[id].ans=max(t[id<<1].ans,t[id<<1|1].ans);
	if(t[id<<1].rg>t[id<<1|1].lf) chkmax(t[id].ans,(mid-t[id<<1].r1+1)+(t[id<<1|1].l0-mid));
	else if(t[id<<1].rg<t[id<<1|1].lf) chkmax(t[id].ans,(mid-t[id<<1].r0+1)+(t[id<<1|1].l1-mid));
	if(t[id<<1].l0==mid&&t[id<<1].rg>t[id<<1|1].lf) t[id].l0=t[id<<1|1].l0;
	else t[id].l0=t[id<<1].l0;
	if(t[id<<1|1].r0==mid+1&&t[id<<1].rg<t[id<<1|1].lf) t[id].r0=t[id<<1].r0;
	else t[id].r0=t[id<<1|1].r0;
	if(t[id<<1].r0==l&&t[id<<1].rg<t[id<<1|1].lf) t[id].l1=t[id<<1|1].l1;
	else if(t[id<<1].l1==mid&&t[id<<1].rg>t[id<<1|1].lf) t[id].l1=t[id<<1|1].l0;
	else t[id].l1=t[id<<1].l1;
	if(t[id<<1|1].l0==r&&t[id<<1].rg>t[id<<1|1].lf) t[id].r1=t[id<<1].r1;
	else if(t[id<<1|1].r1==mid+1&&t[id<<1].rg<t[id<<1|1].lf) t[id].r1=t[id<<1].r0;
	else t[id].r1=t[id<<1|1].r1;
}

void build(int id,int l,int r){
	if(l==r){
		t[id].ans=1,t[id].l0=t[id].l1=t[id].r0=t[id].r1=l;
		t[id].lf=t[id].rg=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id,l,mid,r);
}

void add(int id,ll c){t[id].lazy+=c,t[id].lf+=c,t[id].rg+=c;}
void pushdown(int id){if(t[id].lazy) add(id<<1,t[id].lazy),add(id<<1|1,t[id].lazy),t[id].lazy=0;}

void change(int id,int l,int r,int ql,int qr,ll c){
	if(l==ql&&r==qr) return add(id,c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id,l,mid,r);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	m=readint();
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		change(1,1,n,x,y,z);
		printf("%d\n",t[1].ans);
	}
	return 0;
}