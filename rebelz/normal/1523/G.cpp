#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,id;
	bool operator<(const node c)const{return r-l+1>c.r-c.l+1;}
}a[100005],b[100005];

int n,m,ncnt,res;
int mina[10000005],lch[10000005],rch[10000005],ans[50005],rt[3000005];

void change(int &id,int l,int r,int x,int c){
	if(!id) id=++ncnt,mina[id]=m+1;
	if(l==r) return (void)(chkmin(mina[id],c));
	int mid=(l+r)/2;
	if(x<=mid) change(lch[id],l,mid,x,c);
	else change(rch[id],mid+1,r,x,c);
	mina[id]=min(mina[lch[id]],mina[rch[id]]);
}

int query(int id,int l,int r,int ql,int qr){
	if(!id) return mina[id];
	if(l==ql&&r==qr) return mina[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(lch[id],l,mid,ql,qr);
	else if(ql>mid) return query(rch[id],mid+1,r,ql,qr);
	else return min(query(lch[id],l,mid,ql,mid),query(rch[id],mid+1,r,mid+1,qr));
}

void add(int x,int y,int z){
	for(;y<=n;y+=(y&(-y))) change(rt[y],1,n,x,z);
}

int ask(int x,int y){
	int ret=m+1;
	for(;y;y-=(y&(-y))) chkmin(ret,query(rt[y],1,n,x,n));
	return ret;
}
//x>=l, y<=r
void solve(int l,int r){
	int t=ask(l,r);
	if(t>m) return;
	res+=b[t].r-b[t].l+1;
	if(l!=b[t].l) solve(l,b[t].l-1);
	if(r!=b[t].r) solve(b[t].r+1,r);
}

int main(){
	n=readint(); m=readint();
	mina[0]=m+1;
	for(int i=1;i<=m;i++) a[i].l=readint(),a[i].r=readint(),a[i].id=i,b[i]=a[i];
	sort(a+1,a+m+1);
	int pl=1;
	for(int i=n;i>=1;i--){
		while(pl<=m&&a[pl].r-a[pl].l+1>=i) add(a[pl].l,a[pl].r,a[pl].id),pl++;
		res=0;
		solve(1,n);
		ans[i]=res;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}