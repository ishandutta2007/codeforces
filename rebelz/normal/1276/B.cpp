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

int n,m,a,b;
int f[200005],siz[200005],x[500005],y[500005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return;
	f[fx]=fy,siz[fy]+=siz[fx];
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint(); a=readint(); b=readint();
		for(int i=1;i<=m;i++) x[i]=readint(),y[i]=readint();
		ll ans1=0,ans2=0;
		for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
		for(int i=1;i<=m;i++) if(x[i]!=a&&y[i]!=a) merge(x[i],y[i]);
		for(int i=1;i<=n;i++) if(i!=a&&getf(i)==i&&getf(b)!=i) ans1+=siz[i];
		for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
		for(int i=1;i<=m;i++) if(x[i]!=b&&y[i]!=b) merge(x[i],y[i]);
		for(int i=1;i<=n;i++) if(i!=b&&getf(i)==i&&getf(a)!=i) ans2+=siz[i];
		printf("%lld\n",ans1*ans2);
	}
	return 0;
}