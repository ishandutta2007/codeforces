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

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m,x=0,y=0;
		scanf("%d",&n);
		FOR(i,1,n){
			int v;scanf("%d",&v);
			x = std::max(x,v);
		}
		scanf("%d",&m);
		FOR(i,1,m){
			int v;scanf("%d",&v);
			y = std::max(y,v);
		}
		if(x > y){
			printf("Alice\nAlice\n");
		}
		else if(x < y){
			printf("Bob\nBob\n");
		}
		else{
			printf("Alice\nBob\n");
		}
	}
	return 0;
}