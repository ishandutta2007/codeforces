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

int n,s1,s2,m;
int a[100005],p[100005],t[300000],tag[300000];

void build(int id,int l,int r){
	tag[id]=0;
	if(l==r){
		if(l==s1) t[id]=1;
		else t[id]=0;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]|t[id<<1|1];
}

void pushdown(int id){if(tag[id]) tag[id<<1]=tag[id<<1|1]=1,t[id<<1]=t[id<<1|1]=tag[id]=0;}

void clear(int id,int l,int r,int ql,int qr){
	if(ql>qr) return;
	if(l==ql&&r==qr) return (void)(tag[id]=1,t[id]=0);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) clear(id<<1,l,mid,ql,qr);
	else if(ql>mid) clear(id<<1|1,mid+1,r,ql,qr);
	else clear(id<<1,l,mid,ql,mid),clear(id<<1|1,mid+1,r,mid+1,qr);
	t[id]=t[id<<1]|t[id<<1|1];
}

void change(int id,int l,int r,int x){
	if(l==r) return (void)(t[id]=1);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
	t[id]=t[id<<1]|t[id<<1|1];
}

int main(){
	n=readint(); s1=readint(); s2=readint();
	for(int i=1;i<=n;i++) p[i]=a[i]=readint();
	m=n,p[++m]=s1,p[++m]=s2;
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
	s1=lower_bound(p+1,p+m+1,s1)-p,s2=lower_bound(p+1,p+m+1,s2)-p;
	a[0]=s2;
	int l=abs(p[s1]-p[s2]),r=1e9,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		build(1,1,m);
		for(int i=1;i<=n;i++){
			int tmp=t[1];
			clear(1,1,m,1,lower_bound(p+1,p+m+1,p[a[i]]-mid)-p-1);
			clear(1,1,m,upper_bound(p+1,p+m+1,p[a[i]]+mid)-p,m);
			if(abs(p[a[i-1]]-p[a[i]])<=mid&&tmp) change(1,1,m,a[i-1]);
		}
		if(t[1]) res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",res);
	return 0;
}