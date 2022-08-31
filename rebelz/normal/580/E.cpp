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
	int lazy,h;
}t[300000];

const int cys=1000000009;
int n,m,k;
int bas[100005],sbas[100005];
char a[100005];

int mod(int x){return x>=cys?x-cys:x;}

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].h=a[l]-'0'+1);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].h=mod(1ll*t[id<<1].h*bas[r-mid]%cys+t[id<<1|1].h);
}

void pushdown(int id,int l,int r){
	if(t[id].lazy){
		int mid=(l+r)/2;
		t[id<<1].lazy=t[id].lazy,t[id<<1].h=1ll*t[id].lazy*sbas[mid-l]%cys;
		t[id<<1|1].lazy=t[id].lazy,t[id<<1|1].h=1ll*t[id].lazy*sbas[r-mid-1]%cys;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		t[id].lazy=c+1,t[id].h=1ll*(c+1)*sbas[r-l]%cys;
		return;
	}
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	t[id].h=mod(1ll*t[id<<1].h*bas[r-mid]%cys+t[id<<1|1].h);
}

int query(int id,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(l==ql&&r==qr) return t[id].h;
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return mod(1ll*query(id<<1,l,mid,ql,mid)*bas[qr-mid]%cys+query(id<<1|1,mid+1,r,mid+1,qr));
}

int main(){
	n=readint(); m=readint(); k=readint();
	bas[0]=sbas[0]=1;
	for(int i=1;i<=n;i++) bas[i]=11ll*bas[i-1]%cys;
	for(int i=1;i<=n;i++) sbas[i]=mod(sbas[i-1]+bas[i]);
	scanf("%s",a+1);
	build(1,1,n);
	int opt,x,y,z;
	for(int i=1;i<=m+k;i++){
		opt=readint(); x=readint(); y=readint(); z=readint();
		if(opt==1) change(1,1,n,x,y,z);
		else if(query(1,1,n,x,y-z)==query(1,1,n,x+z,y)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}