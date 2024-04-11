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
const int MAXN = 5e5 + 5;
int n,a[MAXN];
int st[MAXN],tp;
int pre[MAXN],suf[MAXN];

inline void work(int f[]){
	tp = 0;CLR(st,0);
	int sm = 0;
	FOR(i,1,n){
		while(tp && a[st[tp]] >= a[i]){
			int len = tp==1 ? st[tp] : (st[tp]-st[tp-1]);
			sm -= (a[st[tp]]-a[i])*len;
			tp--;
		}
		st[++tp] = i;sm += a[i];
		f[i] = sm;
	}
}
int A[MAXN];
inline void Solve(){
	scanf("%lld",&n);FOR(i,1,n) scanf("%lld",a+i);
	int ans = 0;
	work(pre);std::reverse(a+1,a+n+1);
	
	work(suf);std::reverse(a+1,a+n+1);std::reverse(suf+1,suf+n+1);
	// FOR(i,1,n) DEBUG(suf[i]);
	// FOR(i,1,n) DEBUG(pre[i]);
	int ps = 0;
	FOR(i,1,n){
		// DEBUG(pre[i]+suf[i]-a[i]);
		if(ans < pre[i]+suf[i]-a[i]){
			ans = pre[i]+suf[i]-a[i];
			ps = i;
		}
	}
	// DEBUG(ps);
	A[ps] = a[ps];
	ROF(i,ps-1,1){
		A[i] = std::min(A[i+1],a[i]);
	}
	FOR(i,ps+1,n) A[i] = std::min(a[i],A[i-1]);
	FOR(i,1,n) printf("%lld ",A[i]);puts("");
}

signed main(){
	Solve();
	return 0;
}