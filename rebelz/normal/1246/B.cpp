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

int n,m,k;
ll a[200005],cnt[200005];

namespace k2{
	void solve(){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=sqrt(a[i]);j++){
				if(a[i]%j!=0) continue;
				while(a[i]%j==0&&a[i]/j%j==0) a[i]/=j*j;
			}
			ans+=cnt[a[i]];
			cnt[a[i]]++;
		}
		printf("%lld\n",ans);
	}
}

namespace kn{
	const ll N=100000;
	ll pw[200005];
	ll qpow(ll x,ll p){
		ll ret=1;
		for(;p;p>>=1,x=x*x){
			if(p&1){
				if((N*N+100)/x<ret) return 1ll<<60;
				ret=ret*x;
			}
			if(p>1&&(N*N+100)/x<x) return 1ll<<60;
		}
		return ret;
	}
	void solve(){
		for(int i=1;i<=N;i++){
			if(qpow(i,k)<=N*N) pw[++m]=qpow(i,k);
			else break;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(pw[j]/a[i]>N+10) break;
				if(pw[j]%a[i]!=0) continue;
				ans+=cnt[pw[j]/a[i]];
			}
			cnt[a[i]]++;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	if(k==2) k2::solve();
	else kn::solve();
	return 0;
}