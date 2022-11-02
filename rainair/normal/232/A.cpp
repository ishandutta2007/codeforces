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

inline int C(int n,int m){
	if(n < m) return 0;
	int ans = 1;
	FOR(i,1,m) ans *= (n-i+1);
	FOR(i,1,m) ans /= i;
	return ans;
}
const int MAXN = 100+5;
int a[MAXN][MAXN];

int main(){
	int m;scanf("%d",&m);
	int n = 0;
	while(C(n+1,3) <= m) ++n;
	int r = m-C(n,3);std::vector<int> S;
	while(r){
		ROF(i,n-1,2){
			if(C(i,2) <= r){
				r -= C(i,2);
				S.pb(i);
				break;
			}
		}
	}
	int N = 0;
	printf("%d\n",N=n+(int)S.size());
	FOR(i,1,n) FOR(j,1,n) if(i != j) a[i][j] = 1;
	int t = n+1;
	for(auto x:S){
		FOR(j,1,x) a[t][j] = a[j][t] = 1;
		++t;
	}
	FOR(i,1,N){
		FOR(j,1,N) putchar(a[i][j]+'0');
		puts("");
	}
	return 0;
}