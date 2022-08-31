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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n;
ll l[200005],r[200005],p[200005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) l[i]=readint();
	for(int i=1;i<=n;i++) r[i]=readint();
	ll ans1=0,ans2=0;
	for(int i=1;i<n;i++){
		int tl=max(l[i],l[i+1]),tr=min(r[i],r[i+1]);
		if(tl<=tr) p[i]=(tr-tl+1)*qpow(r[i]-l[i]+1,cys-2)%cys*qpow(r[i+1]-l[i+1]+1,cys-2)%cys;
		if(tl<=tr) ans1=mod(ans1+p[i]);
	}
	ll all=1;
	for(int i=1;i<=n;i++) all=all*(r[i]-l[i]+1)%cys;
	ans2=ans1*ans1%cys;
	for(int i=2;i<n;i++){
		ans2=mod(ans2+cys-2ll*p[i-1]*p[i]%cys);
		int tl=max(max(l[i-1],l[i]),l[i+1]),tr=min(min(r[i-1],r[i]),r[i+1]);
		if(tl<=tr) ans2=(ans2+2ll*(tr-tl+1)*qpow(r[i-1]-l[i-1]+1,cys-2)%cys*qpow(r[i]-l[i]+1,cys-2)%cys*qpow(r[i+1]-l[i+1]+1,cys-2))%cys;
	}
	for(int i=1;i<n;i++){
		ans2=mod(ans2+cys-p[i]*p[i]%cys);
		ans2=(ans2+p[i])%cys;
	}
	printf("%lld\n",mod((1ll*n*n-2ll*n*ans1+ans2)%cys+cys));
	return 0;
}