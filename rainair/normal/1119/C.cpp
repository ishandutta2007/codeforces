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
int n,m;
int a[MAXN][MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	FOR(i,1,n) FOR(j,1,m){
		int x;scanf("%d",&x);a[i][j] ^= x;
	}
	FOR(i,1,n){
		int sm = 0;
		FOR(j,1,m) sm += a[i][j];
		if(sm&1){
			puts("No");
			return 0;
		}
	}
	FOR(i,1,m){
		int sm = 0;
		FOR(j,1,n){
			sm += a[j][i];
		}
		if(sm&1){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}