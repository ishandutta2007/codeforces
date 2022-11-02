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

const int MAXN = 1e5 + 5;
const int MAXM = 1e7 + 5;

bool p[MAXM];
int prime[MAXM],cnt;

inline void prework(){
	FOR(i,2,MAXM-1){
		if(!p[i]) prime[++cnt] = i;
		for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXM;++j){
			p[i*prime[j]] = 1;
			if(!(i%prime[j])) break;
		}
	}
}

int n,k;
int a[MAXN];
std::vector<int> G[MAXN],v[MAXM];

inline void reduce(int i){
	int x = a[i],q = std::sqrt(1.0*x);
	FOR(j,1,cnt){
		int p = prime[j];
		if(p > x || p > q) break;
		if(!(x%p)){
			int c = 0;v[j].pb(i);G[i].pb(p);
			while(!(x%p)) ++c,x /= p;
			--c;while(c--) a[i] /= p;
		}
	}
	if(x != 1){
		G[i].pb(x);
		int p = std::lower_bound(prime+1,prime+cnt+1,x)-prime;
		v[p].pb(i);
	}
}

int f[MAXM];
//  gcd
int b[MAXN];

inline int deg(int i){
	int sz = G[i].size(),res = 0;
	FOR(S,1,(1<<sz)-1){
		int t = 1;
		FOR(j,0,sz-1){
			if((S>>j)&1) t *= G[i][j];
		}
		int gx = f[t];
		if((__builtin_popcount(S)-1)&1) gx = -gx;
		res += gx;
	}
	return res-1;
}

inline void add(int i,int d){
	int sz = G[i].size();
	FOR(S,1,(1<<sz)-1){
		int t = 1;
		FOR(j,0,sz-1){
			if((S>>j)&1) t *= G[i][j];
		}
		f[t] += d;
	}
}

int m;

inline int chk(int x){
	FOR(i,x+1,m) add(b[i],-1);
	int c = 0;
	FOR(i,1,x) c += (deg(b[i]) == x-1);
	FOR(i,x+1,m) add(b[i],1);
	return x-c+3;
}

bool vis[MAXN];
std::mt19937 g(19260);
int tt[MAXN];

int main(){
	prework();
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i),tt[i] = a[i],reduce(i);
	FOR(i,1,cnt){
		if(v[i].size() >= k){
			FOR(j,0,k-1) printf("%d ",v[i][j]);
			puts("");
			return 0;
		}
	}
	FOR(i,1,n) add(i,1);
	int u=-1,v=-1,w=-1;
	FOR(i,1,n){
		if(n-1-deg(i) >= 2){
			v = i;
			FOR(j,1,n){
				if(j == i) continue;
				if(std::__gcd(a[i],a[j]) > 1) continue;
				if(u == -1) u = j;
				else w = j;
			}
			break;
		}
	}
	add(u,-1);add(v,-1);add(w,-1);
	if(k == 3){
		printf("%d %d %d\n",u,v,w);
		return 0;
	}
	FOR(i,1,n){
		if(i == u || i == v || i == w) continue;
		b[++m] = i;
	}
	int c = 0;
	FOR(i,1,m) if(deg(b[i]) == m-1) ++c;
	if(c >= k){
		c = 0;
		FOR(i,1,m){
			if(deg(b[i]) == m-1) ++c,printf("%d ",b[i]);
			if(c == k) break;
		}
		puts("");
		return 0;
	}
	int l = 1,r = m,ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(chk(mid) >= k) ans = mid,r = mid-1;
		else l = mid+1;
	}
	int _ = chk(ans),t = _-chk(ans-1)-2,d = _-k;
	FOR(i,ans+1,m) add(b[i],-1);
	FOR(i,1,ans) vis[i] = (deg(b[i]) != ans-1);
	FOR(i,1,ans-1){
		if(!d) break;
		if(t <= 0) break;
		if(!vis[i]) continue;
		if(std::__gcd(a[b[i]],a[b[ans]]) != 1) continue;
		if(deg(b[i]) != ans-2) continue;
		--d;--t;vis[i] = 0;
	}
	FOR(i,1,ans) if(vis[i]) printf("%d ",b[i]);
	if(!d) printf("%d ",u);
	printf("%d %d\n",v,w);
	return 0;
}