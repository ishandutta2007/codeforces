#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
// source: CF 1129 D
#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int MAXM = 320 + 5;
const int ha = 998244353;
int BLO;
int bel[MAXN];
int n,k;
int g[MAXM][MAXN],val[MAXN],f[MAXN],sm[MAXN];
int tag[MAXN];// 
int l[MAXN],r[MAXN];

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

inline void clear(int x){
	FOR(i,l[x],r[x]) add(g[x][val[i]],ha-f[i-1]);
}

inline void build(int x){
	// FOR(i,0,2) assert(g[x][i]==0);
	FOR(i,l[x],r[x]) val[i] += tag[x];
	tag[x] = 0;sm[x] = 0;
	FOR(i,l[x],r[x]){
		add(g[x][val[i]],f[i-1]);
		if(val[i] <= k) add(sm[x],f[i-1]);
	}
}

inline void modify(int l,int r,int d){ // [0..n]
	if(l > r) return;
	++l;++r;
	// printf("%d %d %d\n",l,r,d);
	if(bel[l] == bel[r]){
		clear(bel[l]);FOR(i,l,r) val[i] += d;build(bel[l]);return;
	}
	clear(bel[l]);FOR(i,l,::r[bel[l]]) val[i] += d;build(bel[l]);
	FOR(i,bel[l]+1,bel[r]-1){
		if(d == 1) {if(k-tag[i] >= 0) add(sm[i],ha-g[i][k-tag[i]]);}
		else {if(k-tag[i]+1 >= 0) add(sm[i],g[i][k-tag[i]+1]);}
		tag[i] += d;
	}
	clear(bel[r]);FOR(i,::l[bel[r]],r) val[i] += d;build(bel[r]);
}

inline void upd(int p){
	clear(bel[p+1]);build(bel[p+1]);
	add(g[bel[p+1]][val[p+1]],f[p]);
	add(sm[bel[p+1]],f[p]);
}

int pre[MAXN],lst[MAXN],a[MAXN];

int main(){
//	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&k);
	BLO = std::sqrt(1.0*n);
	FOR(i,1,n) bel[i] = (i-1)/BLO+1;
	FOR(i,1,n) scanf("%d",a+i),pre[i] = lst[a[i]],lst[a[i]] = i;
	FOR(i,1,bel[n]) l[i] = (i-1)*BLO+1,r[i] = std::min(n,i*BLO);
	// FOR(i,1,bel[n+1]) build(i);
	f[0] = 1;upd(0);
	FOR(i,1,n){
		int p1 = pre[i],p2 = pre[p1];
		// [p1+1,i]
		modify(p1,i-1,1);
		// DEBUG(g[bel[1]][val[1]]),DEBUG(val[1]),DEBUG(f[0]);
		// exit(0);
		// [p2+1,p1]
		if(p1) modify(p2,p1-1,-1);
		int t = 0;
		FOR(j,1,bel[n]) add(t,sm[j]);
		if(t){
			f[i] = t;
			upd(i);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}