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

const int MAXN = 50000+5;
const int MAXM = 200+5;
int n,k;
// 
LL f[2][MAXM][3][3],g[MAXN][3][3];
int now;
// i,j,
LL mx[MAXN],mn[MAXN];int a[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i);
	// f[i][1][0/1/2][1/2];
	mx[0] = -1e18;mn[0] = 1e18;
	FOR(i,1,n){
		mx[i] = std::max(mx[i-1],0ll)+a[i];
		mn[i] = std::min(mn[i-1],0ll)+a[i];
	}
	FOR(i,1,n) mx[i] = std::max(mx[i],mx[i-1]),mn[i] = std::min(mn[i],mn[i-1]);
    CLR(f[now],-0x3f);
	FOR(i,1,n){
        now ^= 1;CLR(f[now],-0x3f);
        f[now][1][1][2] = mx[i];
        f[now][1][2][1] = -mn[i];
		FOR(j,2,k-1){
			f[now][j][0][1] = std::max({f[now^1][j][0][1],f[now^1][j-1][0][1],f[now^1][j-1][1][1],f[now^1][j-1][1][2]});
			f[now][j][0][2] = std::max({f[now^1][j][0][2],f[now^1][j-1][0][2],f[now^1][j-1][2][1],f[now^1][j-1][2][2]});
			f[now][j][1][2] = std::max({/*f[i-1][j][1][2],*/f[now^1][j][1][2]+2*a[i],f[now^1][j-1][2][1]+2*a[i],f[now^1][j-1][2][2]+2*a[i],f[now^1][j-1][0][2]+2*a[i]});
			f[now][j][2][1] = std::max({/*f[i-1][j][2][1],*/f[now^1][j][2][1]-2*a[i],f[now^1][j-1][1][1]-2*a[i],f[now^1][j-1][1][2]-2*a[i],f[now^1][j-1][0][1]-2*a[i]});
		}
        FOR(x,0,2) FOR(y,0,2) g[i][x][y] = f[now][k-1][x][y];
	}
	mx[n+1] = -1e18;mn[n+1] = 1e18;
	ROF(i,n,1){
		mx[i] = std::max(mx[i+1],0ll)+a[i];
		mn[i] = std::min(mn[i+1],0ll)+a[i];
	}
	ROF(i,n,1) mx[i] = std::max(mx[i],mx[i+1]),mn[i] = std::min(mn[i],mn[i+1]);
	LL ans = -1e18;
	// f[i-1][j-1][2][1]+2*a[i],f[i-1][j-1][2][2]+2*a[i]
	// FOR(i,1,n) 
	// DEBUG(f[2][1][2][1]);
	FOR(i,1,n) ans = std::max({ans,g[i][1][2]-mn[i+1],g[i][2][1]+mx[i+1],g[i][0][1]-mn[i+1],g[i][0][2]+mx[i+1]});
	printf("%lld\n",ans);
	return 0;
}