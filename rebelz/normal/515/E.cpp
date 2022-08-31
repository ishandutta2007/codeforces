#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll ls,rs,maxa;
}t[600000];

int n,m;
ll a[200005],h[200005],s[200005];

void build(int id,int l,int r){
	if(l==r){
		t[id].ls=2*h[l]-s[l],t[id].rs=2*h[l]+s[l];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].ls=max(t[id<<1].ls,t[id<<1|1].ls);
	t[id].rs=max(t[id<<1].rs,t[id<<1|1].rs);
	t[id].maxa=max(t[id<<1].ls+t[id<<1|1].rs,max(t[id<<1].maxa,t[id<<1|1].maxa));
}

node query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	node lson=query(id<<1,l,mid,ql,mid),rson=query(id<<1|1,mid+1,r,mid+1,qr),ans;
	ans.ls=max(lson.ls,rson.ls);
	ans.rs=max(lson.rs,rson.rs);
	ans.maxa=max(lson.ls+rson.rs,max(lson.maxa,rson.maxa));
	return ans;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=2;i<=n+1;i++) s[i]=s[i-1]+a[i-1];
	for(int i=2;i<=n;i++) s[i+n]=s[n+1]+s[i];
	for(int i=1;i<=n;i++) h[i]=h[i+n]=readint();
	build(1,1,2*n);
	int x,y;
	while(m--){
		x=readint(); y=readint();
		if(x<=y) printf("%lld\n",query(1,1,2*n,y+1,x+n-1).maxa);
		else printf("%lld\n",query(1,1,2*n,y+1,x-1).maxa);
	}
	return 0;
}