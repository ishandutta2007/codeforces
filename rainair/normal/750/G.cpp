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

LL s;
const int MAXN = 50+5;
LL pw[MAXN+3];
LL f[MAXN+3][MAXN*2+3][2];

inline LL work(LL h1,LL h2,LL n,LL r){
	if(r&1) return 0;
	CLR(f,0);f[0][0][0] = 1;
	FOR(i,0,MAXN-2){
		FOR(j,0,std::min(2ll*i,n)){
			FOR(k,0,1){
				if(!f[i][j][k]) continue;
				FOR(a,0,(i+1<=h1)){
					FOR(b,0,(i+1<=h2)){
						if(((r>>(i+1))&1) == (a+b+k)%2){
							f[i+1][j+a+b][(k+a+b)/2] += f[i][j][k];
						}
					}
				}
			}
		}
	}
	return f[MAXN-1][n][0]+f[MAXN-1][n][1];
}

int main(){
	scanf("%lld",&s);
	FOR(i,0,MAXN-1) pw[i] = 1ll<<i;
	LL ans = 0;
	FOR(h,1,50){
		LL x = s/(pw[h]-1);
		if(x <= 0) break;
		LL r = s-x*(pw[h]-1);
		ROF(i,h-1,1){
			LL gx = pw[i]-1;
			if(r >= gx) r -= gx;
		}
		ans += (!r);
	}
	// DEBUG(work(1,0,0,0));
	// exit(0);
	FOR(h1,1,50-1){
		FOR(h2,1,50-1){
			LL x = s-pw[h2]+1;
			if(x < 0) break;
			x = x/(pw[h1+1]+pw[h2+1]-3);
			if(x > 0){
				FOR(n,0,h1+h2-2){
					LL r = s-((pw[h1+1]+pw[h2+1]-3)*x+pw[h2]-1)+n;
					ans += work(h1-1,h2-1,n,r);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}