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

const int MAXN = 200+5;
int R,G,B;
int r[MAXN],g[MAXN],b[MAXN];
LL f[MAXN][MAXN][MAXN];

int main(){
	scanf("%d%d%d",&R,&G,&B);
	FOR(i,1,R) scanf("%d",r+i);
	FOR(i,1,G) scanf("%d",g+i);
	FOR(i,1,B) scanf("%d",b+i);
	std::sort(r+1,r+R+1);std::reverse(r+1,r+R+1);
	std::sort(g+1,g+G+1);std::reverse(g+1,g+G+1);
	std::sort(b+1,b+B+1);std::reverse(b+1,b+B+1);
	LL ans = 0;
	FOR(i,0,R){
		FOR(j,0,G){
			FOR(k,0,B){
				ans = std::max(ans,f[i][j][k]);
				if(i+1 <= R && j+1 <= G) f[i+1][j+1][k] = std::max(f[i+1][j+1][k],f[i][j][k]+r[i+1]*g[j+1]);
				if(i+1 <= R && k+1 <= B) f[i+1][j][k+1] = std::max(f[i+1][j][k+1],f[i][j][k]+r[i+1]*b[k+1]);
				if(j+1 <= G && k+1 <= B) f[i][j+1][k+1] = std::max(f[i][j+1][k+1],f[i][j][k]+g[j+1]*b[k+1]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}