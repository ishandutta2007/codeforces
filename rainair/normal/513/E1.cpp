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

const int MAXN = 400+5;
int n,k;
// 
int f[55][405][405];// i [k,j]
int a[MAXN],sm[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i),sm[i] = sm[i-1]+a[i];
	CLR(f,-0x3f);
	FOR(i,1,n) FOR(j,1,i) f[1][i][j] = 0;
	FOR(i,2,::k){
		FOR(j,1,n){
			FOR(k,1,j){// [k,j]
				FOR(t,1,k-1){ // [t,k-1]
					f[i][j][k] = std::max(f[i][j][k],f[i-1][k-1][t]+std::abs((sm[j]-sm[k-1])-(sm[k-1]-sm[t-1])));
				}
			}
		}
	}
	DEBUG(f[k][5][5]);
	int ans = 0;
	FOR(i,1,n) FOR(j,1,i) ans = std::max(ans,f[k][i][j]);
	printf("%d\n",ans);
	return 0;
}