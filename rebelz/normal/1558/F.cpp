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

int n;
int a[200005],p[200005],lazy[600000],maxa[600000],num[600000];
bool vis[200005];

void build(int id,int l,int r){
	lazy[id]=num[id]=0,maxa[id]=-(1<<30);
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void pushdown(int id){
	if(lazy[id]){
		lazy[id<<1]+=lazy[id],maxa[id<<1]+=lazy[id];
		lazy[id<<1|1]+=lazy[id],maxa[id<<1|1]+=lazy[id];
		lazy[id]=0;
	}
}

void add(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return (void)(lazy[id]+=c,maxa[id]+=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) add(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) add(id<<1|1,mid+1,r,ql,qr,c);
	else add(id<<1,l,mid,ql,mid,c),add(id<<1|1,mid+1,r,mid+1,qr,c);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(maxa[id]=c,num[id]=1);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	num[id]=num[id<<1]+num[id<<1|1];
}

int query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return num[id];
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i,vis[i]=0;
		int ans=0,mina=n,now=n;
		build(1,1,n);
		for(int i=n;i>=1;i--){
			int x=p[i];
			if(x>1) add(1,1,n,1,x-1,-2);
			int pl=query(1,1,n,x,n)+1;
			vis[x]=1;
			change(1,1,n,x,n-2*pl+1-x+(x%2==0));
			while(vis[now]){
				change(1,1,n,now,-(1<<30));
				now--;
			}
			chkmax(ans,maxa[1]+(n-i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}