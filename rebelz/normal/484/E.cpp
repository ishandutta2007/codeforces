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
	int lch,rch,ls,rs,maxa;
}t[10000000];

int n,q,tot,ans;
int vs[100005],a[100005];

void build(int id,int l,int r){
	t[id].ls=t[id].rs=t[id].maxa=r-l+1;
	if(l==r) return;
	int mid=(l+r)/2;
	build(t[id].lch=++tot,l,mid);
	build(t[id].rch=++tot,mid+1,r);
}

int change(int id,int l,int r,int x){
	int rt=++tot,mid=(l+r)/2;
	t[rt]=t[id];
	if(l==r){
		t[rt].ls=t[rt].rs=t[rt].maxa=0;
		return rt;
	}
	if(x<=mid) t[rt].lch=change(t[id].lch,l,mid,x);
	else t[rt].rch=change(t[id].rch,mid+1,r,x);
	if(t[t[rt].lch].ls==mid-l+1) t[rt].ls=mid-l+1+t[t[rt].rch].ls;
	else t[rt].ls=t[t[rt].lch].ls;
	if(t[t[rt].rch].rs==r-mid) t[rt].rs=r-mid+t[t[rt].lch].rs;
	else t[rt].rs=t[t[rt].rch].rs;
	t[rt].maxa=max(t[t[rt].lch].rs+t[t[rt].rch].ls,max(t[t[rt].lch].maxa,t[t[rt].rch].maxa));
	return rt;
}

node query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id].rch,mid+1,r,ql,qr);
	node lson=query(t[id].lch,l,mid,ql,mid),rson=query(t[id].rch,mid+1,r,mid+1,qr),ret;
	if(lson.ls==mid-ql+1) ret.ls=mid-ql+1+rson.ls;
	else ret.ls=lson.ls;
	if(rson.rs==qr-mid) ret.rs=qr-mid+lson.rs;
	else ret.rs=rson.rs;
	ret.maxa=max(lson.rs+rson.ls,max(lson.maxa,rson.maxa));
	return ret;
}

void divide(int l,int r,int x,int y,int z){
	if(l>r) return;
	int mid=(l+r)/2;
//	cout<<"TEST "<<mid<<' '<<x<<' '<<y<<' '<<query(vs[mid],1,n,x,y).maxa<<' '<<z<<endl;
	if(query(vs[mid],1,n,x,y).maxa>=z){
		ans=mid;
		divide(mid+1,r,x,y,z);
	}
	else divide(l,mid-1,x,y,z);
}

struct tmp{int id,x;bool operator<(const tmp c)const{return x<c.x;}}k[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) k[i].x=a[i]=readint(),k[i].id=i;
	sort(k+1,k+n+1);
	build(vs[0]=0,1,n);
	for(int i=1;i<=n;i++) vs[i]=change(vs[i-1],1,n,k[i].id);
	q=readint();
	int x,y,z;
	while(q--){
		x=readint(); y=readint(); z=readint();
		divide(0,n,x,y,z);
		printf("%d\n",k[ans+1].x);
	}
	return 0;
}