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
	ll val,siz;
}t[600000];

int n;
int a[200005],p[200005];
ll ans[200005];

void change(int id,int l,int r,int x){
	if(l==r) return (void)(t[id].val=x,t[id].siz=1);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
	t[id].val=t[id<<1].val+t[id<<1|1].val;
	t[id].siz=t[id<<1].siz+t[id<<1|1].siz;
}

int ask(int id,int l,int r,int x){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(x<=t[id<<1].siz) return ask(id<<1,l,mid,x);
	else return ask(id<<1|1,mid+1,r,x-t[id<<1].siz);
}

ll query(int id,int l,int r,int ql,int qr,ll c){
	if(ql>qr) return 0;
	if(l==ql&&r==qr) return c>0?c*t[id].siz-t[id].val:t[id].val+c*t[id].siz;
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,c);
	else return query(id<<1,l,mid,ql,mid,c)+query(id<<1|1,mid+1,r,mid+1,qr,c);
}

int qsize(int id,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(l==ql&&r==qr) return t[id].siz;
	int mid=(l+r)/2;
	if(qr<=mid) return qsize(id<<1,l,mid,ql,qr);
	else if(ql>mid) return qsize(id<<1|1,mid+1,r,ql,qr);
	else return qsize(id<<1,l,mid,ql,mid)+qsize(id<<1|1,mid+1,r,mid+1,qr);
}

ll f(ll x){return x*(x+1)/2;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+qsize(1,1,n,p[i]+1,n);
		change(1,1,n,p[i]);
		int pl=ask(1,1,n,(i+1)/2);
		printf("%lld ",query(1,1,n,1,pl-1,pl)-f((i-1)/2)+query(1,1,n,pl+1,n,-pl)-f(i/2)+ans[i]);
	}
	printf("\n");
	return 0;
}