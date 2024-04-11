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

int n,m,q,cnt;
ll a[100005],b[1005];

ll qpow(ll x,ll p,ll cys){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int getphi(int x){
	int ret=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ret=ret/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ret=ret/x*(x-1);
	return ret;
}

ll tpow(ll x,ll p,ll cys){
	ll ret=1;
	for(;p;p>>=1,x=x*x,x=x>=cys?cys:x) if(p&1) ret=ret*x,ret=ret>=cys?cys:ret;
	return ret;
}

ll check(int l,int r,int cys,int k){
	if(a[l]==1) return 1;
	if(k>=5) return cys;
	if(l==r) return a[l];
	ll tmp=check(l+1,r,cys,k+1);
	if(tmp>=cys) return cys;
	return tpow(a[l],tmp,cys);
}

ll solve(int l,int r,int t,bool knd){
	if(b[t]==1){
		if(knd==1) return 0;
		else return 1;
	}
	if(l==r){
		if(knd==1) return a[l]%b[t];
		else return a[l]%b[t]+(a[l]>=b[t]?b[t]:0);
	}
	if(knd==1) return qpow(a[l],solve(l+1,r,t+1,__gcd(a[l],b[t])==1),b[t]);
	else{
		ll tmp=solve(l+1,r,t+1,__gcd(a[l],b[t])==1),g=qpow(a[l],tmp,b[t]);
		if(check(l,r,b[t],0)<b[t]) return g;
		else return g+b[t];
	}
}

int main(){
	n=readint(); m=readint();
	b[1]=m,cnt=1;
	while(b[cnt]>1) b[cnt+1]=getphi(b[cnt]),cnt++;
	for(int i=1;i<=n;i++) a[i]=readint();
	q=readint();
	int l,r;
	while(q--){
		l=readint(); r=readint();
		printf("%lld\n",solve(l,r,1,1));
	}
	return 0;
}