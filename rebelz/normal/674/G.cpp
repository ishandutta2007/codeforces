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
 
int n,m,p,k;
int a[150005];
 
struct node{
	int num,lazy;
	pii a[11];
	node operator+(const node c)const{
		node ret=*this; ret.lazy=0;
		for(int i=1;i<=c.num;i++){
			bool fl=false;
			for(int j=1;j<=ret.num;j++){
				if(c.a[i].se==ret.a[j].se){
					ret.a[j].fi+=c.a[i].fi,fl=true;
					break;
				}
			}
			if(!fl) ret.a[++ret.num]=c.a[i];
		}
		sort(ret.a+1,ret.a+ret.num+1);
		reverse(ret.a+1,ret.a+ret.num+1);
		for(int i=ret.num;i>=k+1;i--,ret.num--){
			if(ret.a[i].fi<=0) continue;
			for(int j=1;j<=i-1;j++) ret.a[j].fi-=ret.a[i].fi;
		}
		while(ret.num>0&&ret.a[ret.num].fi<=0) ret.num--;
		return ret;
	}
}t[600000];
 
void build(int id,int l,int r){
	if(l==r) return (void)(t[id].a[++t[id].num]=mp(1,a[l]));
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]+t[id<<1|1];
}
 
void pushdown(int id,int l,int r){
	if(t[id].lazy){
		int mid=(l+r)/2;
		t[id<<1].lazy=t[id<<1|1].lazy=t[id].lazy;
		t[id<<1].num=t[id<<1|1].num=1;
		t[id<<1].a[1]=mp(mid-l+1,t[id].lazy);
		t[id<<1|1].a[1]=mp(r-mid,t[id].lazy);
		t[id].lazy=0;
	}
}
 
void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		t[id].num=1,t[id].lazy=c,t[id].a[1]=mp(r-l+1,c);
		return;
	}
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	t[id]=t[id<<1]+t[id<<1|1];
}
 
node query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id];
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}
 
int main(){
	n=readint(); m=readint(); p=readint(); k=100/p;
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	int opt,x,y;
	for(int i=1;i<=m;i++){
		opt=readint(); x=readint(); y=readint();
		if(opt==1) change(1,1,n,x,y,readint());
		else{
			node tmp=query(1,1,n,x,y);
			printf("%d ",tmp.num);
			for(int i=1;i<=tmp.num;i++) printf("%d ",tmp.a[i].se);
			printf("\n");
		}
	}
	return 0;
}