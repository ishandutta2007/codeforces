#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define ll long long

int n;
ll lev[64];

inline int hibit(ll x) {
	int ans=-1;
	while(x) x>>=1, ++ans;
	return ans;
}
inline void shift(int lv,ll k) {
	lev[lv]+=k&((1ll<<lv)-1);
	lev[lv]&=((1ll<<lv)-1);
}

int main() {
	scanf("%d",&n);
	F(i,1,n) {
		int t;
		ll x,k;
		scanf("%d%lld",&t,&x);
		if(t==1) {
			scanf("%lld",&k);
			shift(hibit(x),k);
		}
		if(t==2) {
			scanf("%lld",&k);
			F(j,hibit(x),61)
			shift(j,k<<(j-hibit(x)));
		}
		if(t==3) {
			int lv=hibit(x);
			ll y=(x-(1ll<<lv)+lev[lv])&((1ll<<lv)-1);
			dF(j,lv,0) printf("%lld ",((y-lev[j])&((1ll<<j)-1))+(1ll<<j)), y>>=1;
			puts("");
		}
	}
	return 0;
}