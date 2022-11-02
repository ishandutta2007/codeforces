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
#define int LL
int c[2][23];
int t[7][7];
int d[23];
std::mt19937 g(time(NULL));

signed main(){
	int T;scanf("%lld",&T);
	t[1][3] = 2;t[1][5] = 6;
	t[2][4] = 3;t[2][6] = 1;
	t[3][5] = 4;t[4][6] = 5;
	while(T--){
		int x,y;scanf("%lld%lld",&x,&y);
		int now = 0;
		// FOR(i,1,6) scanf("%lld",&c[now][i]);
		scanf("%lld%lld%lld%lld%lld%lld",&c[now][1],&c[now][6],&c[now][5],&c[now][4],&c[now][3],&c[now][2]);
		FOR(i,1,10){
			FOR(j,1,6) c[now^1][j] = c[now][j];
			// int id[10];
			// FOR(i,1,6) id[i] = i;
			// std::shuffle(id+1,id+6+1,g);
			FOR(j,1,6){
				FOR(k,j+1,6){
					if(t[j][k]) c[now^1][t[j][k]] = std::min(c[now^1][t[j][k]],c[now][j]+c[now][k]);
				}
			}
			now ^= 1;
		}
		FOR(i,1,6) d[i] = c[now][i];
		if(x < 0 && y < 0){
			if(x > y){
				printf("%lld\n",d[4]*(-x)+d[3]*(x-y));
			}
			else{
				printf("%lld\n",d[4]*(-y)+d[5]*(y-x));
			}
		}
		else if(x >= 0 && y >= 0){
			if(x > y){
				printf("%lld\n",d[1]*y+d[2]*(x-y));
			}
			else{
				printf("%lld\n",d[1]*x+d[6]*(y-x));
			}
		}
		else if(x >= 0 && y < 0){
			printf("%lld\n",d[2]*x-y*d[3]);
		}
		else{
			printf("%lld\n",y*d[6]-d[5]*x);
		}
	}
	return 0;
}