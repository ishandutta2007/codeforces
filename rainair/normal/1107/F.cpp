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

const int MAXN = 500+5;

struct Node{
	LL a,b,k;
	
	inline bool operator < (const Node &t) const {
		return b > t.b;
	}
}v[MAXN];
int n;
LL f[MAXN][MAXN];
// i ,j

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld%lld%lld",&v[i].a,&v[i].b,&v[i].k);
	std::sort(v+1,v+n+1);
	CLR(f,-0x3f);
	f[0][0] = 0;
	FOR(i,1,n){
		FOR(j,0,i){
			f[i][j] = f[i-1][j];
			f[i][j] = std::max(f[i][j],f[i-1][j]+v[i].a-v[i].k*v[i].b);
			if(j-1 >= 0) f[i][j] = std::max(f[i][j],f[i-1][j-1]+v[i].a-std::min((LL)(j-1),v[i].k)*v[i].b);
		}
		// DEBUG(f[i][0]);
	}
	LL ans = -1e18;
	FOR(i,0,n) ans = std::max(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}