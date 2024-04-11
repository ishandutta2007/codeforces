#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
const int ha = 1e9 + 7;
int k,n,m;
P a[2][MAXN];
std::vector<int> S;
int lim[2][MAXN];
int f[2][MAXN];
// 0/1  

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int main(){
	scanf("%d%d%d",&k,&n,&m);
	S.pb(0);S.pb(k);
	FOR(i,1,n){
		scanf("%d%d",&a[0][i].fi,&a[0][i].se);--a[0][i].fi;
		S.pb(a[0][i].fi);S.pb(a[0][i].se);
	}
	FOR(i,1,m){
		scanf("%d%d",&a[1][i].fi,&a[1][i].se);--a[1][i].fi;
		S.pb(a[1][i].fi);S.pb(a[1][i].se);
	}
	CLR(lim,-1);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n){
		a[0][i].fi = std::lower_bound(all(S),a[0][i].fi)-S.begin();
		a[0][i].se = std::lower_bound(all(S),a[0][i].se)-S.begin();
		lim[0][a[0][i].se] = std::max(lim[0][a[0][i].se],a[0][i].fi);
	}
	FOR(i,1,m){
		a[1][i].fi = std::lower_bound(all(S),a[1][i].fi)-S.begin();
		a[1][i].se = std::lower_bound(all(S),a[1][i].se)-S.begin();
		lim[1][a[1][i].se] = std::max(lim[1][a[1][i].se],a[1][i].fi);
	}
	int n = S.size();
	FOR(i,0,1) FOR(j,1,n) lim[i][j] = std::max(lim[i][j],lim[i][j-1]);
	f[0][0] = 1;int sm0 = 1,tp0 = 0,sm1 = 0,tp1 = 0;
	FOR(i,0,n-2){
		while(tp0 <= lim[1][i]) add(sm0,ha-f[0][tp0]),++tp0;
		while(tp1 <= lim[0][i]) add(sm1,ha-f[1][tp1]),++tp1;
		add(f[1][i],sm0);add(f[0][i],sm1);
		int gx = qpow(2,S[i+1]-S[i]-1);add(gx,ha-1);
		gx = 1ll*gx*(sm0+sm1)%ha;
		add(f[0][i+1],gx);add(f[1][i+1],gx);
		int t0 = sm0,t1 = sm1;
		add(sm0,t1);add(sm1,t0);
		add(sm0,gx);add(sm1,gx);
	}
	int ans = 0;
	FOR(i,0,n) if(i > lim[1][n]) add(ans,f[0][i]);
	FOR(i,0,n) if(i > lim[0][n]) add(ans,f[1][i]);
	printf("%d\n",ans);
	return 0;
}