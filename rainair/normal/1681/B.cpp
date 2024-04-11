#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		FOR(i,1,n) scanf("%d",a+i);
		int s = 0,m;scanf("%d",&m);
		FOR(i,1,m){
			int x;scanf("%d",&x);
			(s += x) %= n;
		}
		printf("%d\n",a[s+1]);
	}
	return 0;
}