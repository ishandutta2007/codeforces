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
	int d[20];
}t[1100000];

int n,q;
int a[300005];

void build(int id,int l,int r){
	if(l==r){
		for(int i=0;i<=19;i++) t[id].d[i]=(a[l]&(1<<i))?a[l]:(1<<i);
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	for(int i=0;i<=19;i++)
		for(int j=0;j<=19;j++)
			if(t[id<<1].d[i]&(1<<j)) t[id].d[i]|=t[id<<1|1].d[j];
}

int query(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		int ret=0;
		for(int i=0;i<=19;i++) if(c&(1<<i)) ret|=t[id].d[i];
		return ret;
	}
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,c);
	int lson=query(id<<1,l,mid,ql,mid,c);
	return query(id<<1|1,mid+1,r,mid+1,qr,lson);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	int x,y;
	while(q--){
		x=readint(); y=readint();
		int tmp=query(1,1,n,x,y,a[x]),fl=0;
		for(int i=0;i<=19;i++) if((tmp&(1<<i))&&(a[y]&(1<<i))) fl=1;
		if(fl) printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}