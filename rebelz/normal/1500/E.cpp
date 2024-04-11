#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q;
ll a[200005],p[400005],opt[200005],b[200005],siz[1100000],sum[1100000],sl[1100000],sr[1100000];

void update(int id){
	siz[id]=siz[id<<1]+siz[id<<1|1];
	sum[id]=sum[id<<1]+sum[id<<1|1];
	sr[id]=sr[id<<1]+sr[id<<1|1]+siz[id<<1]*sum[id<<1|1];
	sl[id]=sl[id<<1]+sl[id<<1|1]+siz[id<<1|1]*sum[id<<1];
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(sum[id]+=c*p[l],sr[id]+=c*p[l],sl[id]+=c*p[l],siz[id]+=c);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	update(id);
}

ll getmin(int id,int l,int r,int x){
	if(!x) return 0;
	if(l==r) return sum[id];
	int mid=(l+r)/2;
	if(x>=siz[id<<1]) return getmin(id<<1|1,mid+1,r,x-siz[id<<1])+sum[id<<1];
	else return getmin(id<<1,l,mid,x);
}

ll getmax(int id,int l,int r,int x){
	if(!x) return 0;
	if(l==r) return sum[id];
	int mid=(l+r)/2;
	if(x>=siz[id<<1|1]) return getmax(id<<1,l,mid,x-siz[id<<1|1])+sum[id<<1|1];
	else return getmax(id<<1|1,mid+1,r,x);
}

ll queryl(int id,int l,int r,int x){
	if(!x) return 0;
	if(l==r) return x*sum[id];
	int mid=(l+r)/2;
	if(x>=siz[id<<1]) return queryl(id<<1|1,mid+1,r,x-siz[id<<1])+sl[id<<1]+(x-siz[id<<1])*sum[id<<1];
	else return queryl(id<<1,l,mid,x);
}

ll queryr(int id,int l,int r,int x){
	if(!x) return 0;
	if(l==r) return x*sum[id];
	int mid=(l+r)/2;
	if(x>=siz[id<<1|1]) return queryr(id<<1,l,mid,x-siz[id<<1|1])+sr[id<<1|1]+(x-siz[id<<1|1])*sum[id<<1|1];
	else return queryr(id<<1|1,mid+1,r,x);
}

ll getans(){
	ll ret=sr[1]-sl[1];
	int l=1,r=(n+1)/2,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(getmax(1,1,m,mid-1)-getmin(1,1,m,mid)>0) res=mid,r=mid-1;
		else l=mid+1;
	}
	if(res){
		ret-=queryr(1,1,m,n-res)-queryl(1,1,m,n-res+1);
		if(res>1) ret+=queryr(1,1,m,res-2)-queryl(1,1,m,res-1);
	}
	return ret;
}

int main(){
	m=n=readint(); q=readint();
	for(int i=1;i<=n;i++) p[i]=a[i]=readint();
	for(int i=1;i<=q;i++) opt[i]=readint(),p[++m]=b[i]=readint();
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
	for(int i=1;i<=q;i++) b[i]=lower_bound(p+1,p+m+1,b[i])-p;
	for(int i=1;i<=n;i++) change(1,1,m,a[i],1);
	printf("%lld\n",getans());
	for(int i=1;i<=q;i++){
		if(opt[i]==1) change(1,1,m,b[i],1),n++;
		else change(1,1,m,b[i],-1),n--;
		printf("%lld\n",getans());
	}
	return 0;
}