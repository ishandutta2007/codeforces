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

struct node{
	ll mina,lazy;
}t[300000];

ll n,p;
ll a[100005],ans[100005];

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].mina=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
}

void change(int id,int l,int r,int ql,int qr,ll x){
	if(ql>qr) return;
	if(l==ql&&r==qr) return (void)(chkmax(t[id].lazy,x),chkmax(t[id].mina,x));
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,x);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,x);
	else change(id<<1,l,mid,ql,mid,x),change(id<<1|1,mid+1,r,mid+1,qr,x);
	t[id].mina=max(t[id].lazy,min(t[id<<1].mina,t[id<<1|1].mina));
}

int query(int id,int l,int r,ll x){
	if(l==r) return l;
	chkmax(x,t[id].lazy);
	int mid=(l+r)/2;
	if(max(t[id<<1].mina,x)==max(t[id].mina,x)) return query(id<<1,l,mid,x);
	else return query(id<<1|1,mid+1,r,x);
}

int main(){
	n=readint(); p=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	ll now=0;
	for(int i=1;i<=n;i++){
		int tmp=query(1,1,n,0);
//		cout<<"test "<<t[1].mina<<' '<<tmp<<endl;
		ans[tmp]=max(now,t[1].mina)+p;
		change(1,1,n,tmp+1,n,ans[tmp]);
		change(1,1,n,tmp,tmp,1ll<<60);
		chkmax(now,ans[tmp]);
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}