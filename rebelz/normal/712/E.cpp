#include<bits/stdc++.h>

#define pdd pair<double,double>
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	double x,y;
}t[300000];

int n,q;
int a[100005],b[100005];

void update(int id){
	t[id].x=t[id<<1].x*t[id<<1|1].x/(1-(1-t[id<<1|1].x)*t[id<<1].y);
	t[id].y=t[id<<1|1].y+(1-t[id<<1|1].y)*t[id<<1].y*t[id<<1|1].x/(1-(1-t[id<<1|1].x)*t[id<<1].y);
}

void build(int id,int l,int r){
	if(l==r) return(void)(t[id].x=t[id].y=1.0*a[l]/b[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void change(int id,int l,int r,int p,double c){
	if(l==p&&r==p) return (void)(t[id].x=t[id].y=c);
	int mid=(l+r)/2;
	if(p<=mid) change(id<<1,l,mid,p,c);
	else change(id<<1|1,mid+1,r,p,c);
	update(id);
}

pdd query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return mp(t[id].x,t[id].y);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	pdd lson=query(id<<1,l,mid,ql,mid),rson=query(id<<1|1,mid+1,r,mid+1,qr),ans;
	ans.fi=lson.fi*rson.fi/(1-(1-rson.fi)*lson.se);
	ans.se=rson.se+(1-rson.se)*lson.se*rson.fi/(1-(1-rson.fi)*lson.se);
	return ans;
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint();
	build(1,1,n);
	int opt,x,y;
	while(q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1) change(1,1,n,x,1.0*y/readint());
		else printf("%.10lf\n",query(1,1,n,x,y).fi);
	}
	return 0;
}