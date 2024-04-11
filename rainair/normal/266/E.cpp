#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
const int ha = 1e9 + 7;

int sm[6][MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void pushup(int x){
	FOR(i,0,5) sm[i][x] = (sm[i][lc]+sm[i][rc])%ha;
}

int pw[6][MAXN];

inline void cover(int x,int l,int r,int d){
	// DEBUG(l);DEBUG(r);DEBUG(d);
	FOR(i,0,5) sm[i][x] = (pw[i][r]-pw[i][l-1]+ha)%ha*d%ha;//,DEBUG(sm[i][x]);
	tag[x] = d;
}

inline void pushdown(int x,int l,int r){
	if(tag[x] != -1){
		int mid = (l + r) >> 1;
		cover(lc,l,mid,tag[x]);
		cover(rc,mid+1,r,tag[x]);
		tag[x] = -1;
	}
}

inline void modify(int x,int l,int r,int L,int R,int d){
	// DEBUG(l);DEBUG(r);DEBUG(L);DEBUG(R);
	if(l == L && r == R){
		cover(x,l,r,d);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	pushup(x);
}

inline int query(int x,int l,int r,int L,int R,int k){
	if(l == L && r == R) return sm[k][x];
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(R <= mid) return query(lc,l,mid,L,R,k);
	if(L > mid) return query(rc,mid+1,r,L,R,k);
	return (query(lc,l,mid,L,mid,k)+query(rc,mid+1,r,mid+1,R,k))%ha;
}

int n,m;
int fac[MAXN],inv[MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	} 
	return res;
}

inline void prework(){
	FOR(i,1,n){
		pw[0][i] = 1;FOR(j,1,5) pw[j][i] = 1ll*pw[j-1][i]*i%ha;
		FOR(j,0,5) (pw[j][i] += pw[j][i-1])%=ha;
	}
	fac[0] = 1;
	FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
	inv[MAXN-1] = qpow(fac[MAXN-1]);
	ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
	return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

char str[233];

signed main(){
	CLR(tag,-1);
	scanf("%lld%lld",&n,&m);
	prework();
	FOR(i,1,n){
		int x;scanf("%lld",&x);
		modify(1,1,n,i,i,x);
	}
	// FOR(i,1,n) DEBUG(query(1,1,n,i,i,3));
	// exit(0);
	FOR(i,1,m){
		scanf("%s",str);
		int l,r,k;scanf("%lld%lld%lld",&l,&r,&k);
		if(str[0] == '='){
			modify(1,1,n,l,r,k);
		}
		else{
			int ans = 0;
			FOR(j,0,k){
				int gx = C(k,j);
				gx = 1ll*gx*((qpow(-(l-1),k-j)+ha)%ha)%ha;
				int t = query(1,1,n,l,r,j);
				gx = 1ll*gx*t%ha;
				// DEBUG(gx);
				if(gx < 0) gx = ha-gx;
				(ans += gx) %= ha;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}