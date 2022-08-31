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
	int mina,num,lazy;
}t[1100000];

int n;
int a[300005],q1[300005],q2[300005];

void update(int id){
	if(t[id<<1].mina==t[id<<1|1].mina) t[id].mina=t[id<<1].mina,t[id].num=t[id<<1].num+t[id<<1|1].num;
	else if(t[id<<1].mina<t[id<<1|1].mina) t[id].mina=t[id<<1].mina,t[id].num=t[id<<1].num;
	else t[id].mina=t[id<<1|1].mina,t[id].num=t[id<<1|1].num;
}

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].mina=l,t[id].num=1);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy,t[id<<1].mina+=t[id].lazy;
		t[id<<1|1].lazy+=t[id].lazy,t[id<<1|1].mina+=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return (void)(t[id].mina+=c,t[id].lazy+=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

pii operator+(const pii x,const pii y){return x.fi==y.fi?mp(x.fi,x.se+y.se):x.fi<y.fi?x:y;}

pii query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return mp(t[id].mina,t[id].num);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[readint()]=readint();
	build(1,1,n);
	int f1=0,r1=0,f2=0,r2=0; ll ans=0;
	q1[r1++]=0,q2[r2++]=0;
	for(int i=1;i<=n;i++){
		int lst=i-1;
		while(f1+1<r1&&a[i]>a[q1[r1-1]]) change(1,1,n,q1[r1-2]+1,lst,a[i]-a[q1[r1-1]]),lst=q1[r1-2],r1--;
		lst=i-1;
		while(f2+1<r2&&a[i]<a[q2[r2-1]]) change(1,1,n,q2[r2-2]+1,lst,a[q2[r2-1]]-a[i]),lst=q2[r2-2],r2--;
		q1[r1++]=i,q2[r2++]=i;
		pii tmp=query(1,1,n,1,i);
		if(tmp.fi==i) ans+=tmp.se;
	}
	printf("%lld\n",ans);
	return 0;
}