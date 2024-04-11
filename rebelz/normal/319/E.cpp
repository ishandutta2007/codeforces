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
typedef vector<int> vi;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	vi vec;
}t[600000];

int n,m,cnt;
int opt[100005],x[100005],y[100005],p[200005],f[100005];
pii a[100005],b[100005];
bool vis[100005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void change(int id,int l,int r,int ql,int qr,int x){
	if(ql>qr) return;
	if(l==ql&&r==qr) return (void)(t[id].vec.push_back(x));
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,x);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,x);
	else change(id<<1,l,mid,ql,mid,x),change(id<<1|1,mid+1,r,mid+1,qr,x);
}

void query(int id,int l,int r,int x,vi &ret){
	if(l==r){
		for(auto r:t[id].vec) if(!vis[r]) ret.push_back(r);
		t[id].vec.clear();
		return;
	}
	int mid=(l+r)/2;
	for(auto r:t[id].vec) if(!vis[r]) ret.push_back(r);
	t[id].vec.clear();
	if(x<=mid) query(id<<1,l,mid,x,ret);
	else query(id<<1|1,mid+1,r,x,ret);
	return;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		opt[i]=readint(); x[i]=readint(); y[i]=readint();
		if(opt[i]==1) p[++m]=x[i],p[++m]=y[i];
	}
	sort(p+1,p+m+1); m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++) if(opt[i]==1) x[i]=lower_bound(p+1,p+m+1,x[i])-p,y[i]=lower_bound(p+1,p+m+1,y[i])-p;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(opt[i]==1){
			int l=x[i]+1,r=y[i]-1;
			vi tmp(0),tmp1(0);
			query(1,1,m,x[i],tmp),query(1,1,m,y[i],tmp1);
			tmp.insert(tmp.end(),tmp1.begin(),tmp1.end());
			for(auto t:tmp) vis[t]=1,chkmin(l,a[t].fi),chkmax(r,a[t].se),f[t]=cnt+1;
			a[++cnt]=mp(l,r),b[cnt]=mp(x[i],y[i]);
			change(1,1,m,l,r,cnt);
		}
		else{
			int fx=getf(y[i]);
			if((a[fx].fi<=b[x[i]].fi&&b[x[i]].fi<=a[fx].se)||(a[fx].fi<=b[x[i]].se&&b[x[i]].se<=a[fx].se)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}