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
typedef long double ld;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ld eps=1e-12,pi=acos(-1);
int n,m;
pii a[5005];
int x[2505],y[2505];

int place(pii x){
	if(x.fi>=0&&x.se>=0) return 3;
	else if(x.fi>=0) return 2;
	else if(x.se<=0) return 1;
	else return 4;
}

bool cmp(pii x,pii y){
	int px=place(x),py=place(y);
	if(px!=py) return px<py;
	else return 1ll*x.fi*y.se-1ll*x.se*y.fi>0;
}

bool check(int x,int y){
	int px=place(a[x])+2,py=place(a[y]);
	if(y>m) py+=4;
	if(px!=py) return px>py;
	else return -1ll*a[y].fi*a[x].se+1ll*a[y].se*a[x].fi>0;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint();
	ll ans=1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/24;
	for(int i=1;i<=n;i++){
		m=0;
		for(int j=1;j<=n;j++) if(i!=j) a[++m]=mp(x[j]-x[i],y[j]-y[i]);
		sort(a+1,a+m+1,cmp);
		for(int j=1;j<=m;j++) a[j+m]=a[j];
		int pl=1;
		for(int j=1;j<=m;j++){
			while(check(j,pl)) pl++;
			ans-=1ll*(pl-j-1)*(pl-j-2)*(pl-j-3)/6;
		}
	}
	printf("%lld\n",ans);
	return 0;
}