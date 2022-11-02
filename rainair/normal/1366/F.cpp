#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000+5;
const int ha = 1e9 + 7;
const int inv2 = 500000004;
int n,m,q;

struct Edge{
	int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int f[MAXN][MAXN],mx[MAXN];// i,j
P seg[MAXN];
int stk[MAXN];

inline bool cmp(P a,P b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se > b.se;
}

inline double intersect(P a,P b){
	// y=a.fix+a.se
	// y=b.fix+b.se
	// a.fix+a.se=b.fix+b.se
	// (a.fi.b-fi)x=b.se-a.se
	return 1.0*(b.se-a.se)/(a.fi-b.fi);
}

inline bool chk(P a,P b,P c){
	return intersect(b,c) <= intersect(a,b);
}

inline int calc(P a,LL x){
	if(x <= 0) return 0;
	int res = 1ll*a.se%ha*x%ha;
	(res += 1ll*a.fi%ha*x%ha*(x+1)%ha*inv2%ha) %= ha;
	return res;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,m){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);mx[u] = std::max(mx[u],w);mx[v] = std::max(mx[v],w);
	}
	CLR(f,-1);f[0][1] = 0;
	FOR(c,0,m-1){
		FOR(v,1,n){
			if(f[c][v] == -1) continue;
			f[c+1][v] = std::max(f[c+1][v],0);
			for(int i = head[v];i;i = e[i].nxt){
				f[c+1][e[i].to] = std::max(f[c+1][e[i].to],f[c][v]+e[i].w);
			}
		}
	}
	if(q <= m){
		int ans = 0;
		FOR(i,1,q){
			int mx = 0;
			FOR(v,1,n) mx = std::max(mx,f[i][v]);
			(ans += mx%ha) %= ha;
		}
		printf("%d\n",ans);
		return 0;
	}
	int ans = 0;
	FOR(i,1,m){
		int mx = 0;
		FOR(v,1,n) mx = std::max(mx,f[i][v]);
		(ans += mx%ha) %= ha;
	}
	q -= m;
	FOR(i,1,n) seg[i] = MP(mx[i],f[m][i]);
	std::sort(seg+1,seg+n+1,cmp);
	int tp = 0;
	FOR(i,1,n){
		if(seg[i].fi == seg[i-1].fi) continue;
		// if(i == 4) DEBUG(tp),DEBUG(chk(seg[stk[tp-1]],seg[stk[tp]],seg[i]));
		while(tp >= 2 && chk(seg[stk[tp-1]],seg[stk[tp]],seg[i])) tp--;
		stk[++tp] = i;
	}
	// DEBUG(intersect(seg[stk[1]],seg[stk[2]]));
	// DEBUG(seg[stk[1]].fi);DEBUG(seg[stk[1]].se);
	// DEBUG(seg[stk[2]].fi);DEBUG(seg[stk[2]].se);
	// DEBUG(stk[3]);
	// DEBUG(intersect(seg[stk[2]],seg[stk[3]]));
	// DEBUG(chk(seg[stk[1]],seg[stk[2]],seg[stk[3]]));
	// DEBUG(tp);
	LL las = 0;
	// FOR(i,1,n) printf("%lld %lld\n",seg[i].fi,seg[i].se);
	// puts("---------------------");
	// FOR(i,1,tp) printf("%lld %lld\n",seg[stk[i]].fi,seg[stk[i]].se);
	// puts("---------------------");
	FOR(i,1,tp){
		LL r = i==tp?q:(LL)intersect(seg[stk[i]],seg[stk[i+1]]);
		// printf("%lld %lld\n",las,r);
		if(r <= las) continue;
		r = std::min(r,(LL)q);
		(ans += (calc(seg[stk[i]],r)-calc(seg[stk[i]],las)+ha)%ha) %= ha;
		las = r;
	}
	printf("%d\n",ans);
	return 0;
}