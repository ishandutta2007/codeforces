#include<cstdio>
const int maxn=500000;
int n,q;
struct node{
	int l,r,val;
}a[maxn*4+10];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void build(int p,int l,int r){
	a[p].l=l; a[p].r=r;
	if(l==r) scanf("%d",&a[p].val);
	else{
		int mid=(l+r)/2;
		build(p*2,l,mid); build(p*2+1,mid+1,r);
		a[p].val=gcd(a[p*2].val,a[p*2+1].val);
	}
}
void change(int p,int k,int v){
	if(a[p].l==a[p].r) a[p].val=v;
	else{
		int mid=(a[p].l+a[p].r)/2;
		if(k<=mid) change(p*2,k,v); else change(p*2+1,k,v);
		a[p].val=gcd(a[p*2].val,a[p*2+1].val);
	}
}
int query(int p,int l,int v){
	if(l==a[p].l&&a[p].val%v==0) return a[p].r;
	if(a[p].l==a[p].r) return l-1;
	int mid=(a[p].l+a[p].r)/2;
	if(l<=mid){
		int t=query(p*2,l,v);
		if(t==a[p*2].r) return query(p*2+1,a[p*2+1].l,v);
		else return t;
	}else return query(p*2+1,l,v);
}
int main(){
	scanf("%d",&n); build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int op,l,r,v; scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			scanf("%d",&v); int pos=query(1,l,v);
			if(pos>=r) printf("YES\n");
			else if(query(1,pos+2,v)>=r) printf("YES\n");
			else printf("NO\n");
		}else change(1,l,r);
	}
	return 0;
}