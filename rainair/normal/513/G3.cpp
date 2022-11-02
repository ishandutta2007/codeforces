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

double f[2][105][105];
int a[205],n,k;

inline int C2(int x){
    if(x <= 1) return 0;
    return x*(x-1)/2;
}
std::mt19937 g(1919810);
int main(){
	scanf("%d%d",&n,&k);
    k = std::min(k,1000);
//    FOR(i,1,n) a[i] = i;std::shuffle(a+1,a+n+1,g);
	FOR(i,1,n) scanf("%d",a+i);
	int now = 0;
	FOR(i,1,n) FOR(j,i+1,n) if(a[i] > a[j]) f[now][i][j] = 1;
	FOR(i,1,k){
		CLR(f[now^1],0);
		FOR(x,1,n){
			FOR(y,x+1,n){// 
				double p = 1.0/(n*(n+1)/2);
                // 
                f[now^1][x][y] += f[now][x][y]*p*(C2(x-1)+C2(n-y)+C2(y-x-1)+n-2);
                // 
                // l in [1,x],r in [x,y-1]
                // tx = r+l-x
                FOR(len,x+1,x+y-1){
                    int ll = std::max(len-y+1,1),rr = std::min(len-x,x);
                    assert(ll <= rr);
                    f[now^1][len-x][y] += f[now][x][y]*p*(rr-ll+1);
                }
                // 
                // l in [x+1,y],r in [y,n]
                // ty = r+l-x
                FOR(len,x+y+1,y+n){
                    int ll = std::max(x+1,len-n),rr = std::min(y,len-y);
                    assert(ll <= rr);
                    f[now^1][x][len-y] += f[now][x][y]*p*(rr-ll+1);
                }
                // 
                // l in [1,x] r in [y,n]
                // tx = r+l-x ty = r+l-y
                FOR(len,y+1,x+n){
                    int ll = std::max(1,len-n),rr = std::min(x,len-y);
                    assert(ll <= rr);
                    f[now^1][len-y][len-x] += (1-f[now][x][y])*p*(rr-ll+1);
                }
			}
		}
		now ^= 1;
	}
	double ans = 0;
	FOR(i,1,n){
		FOR(j,i+1,n){
			ans += f[now][i][j];
		}
	}
	printf("%.10f\n",ans);
	return 0;
}
/*
 (u,v)
 f[i][a][b] i,(u,v)
 
*/