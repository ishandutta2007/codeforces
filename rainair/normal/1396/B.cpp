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

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int sm = 0,mx = 0;
		FOR(i,1,n){
			int x;scanf("%d",&x);
			sm += x;mx = std::max(mx,x);
		}
		if(mx > sm/2){
			puts("T");
		}
		else puts(sm%2 ? "T" : "HL");
	}
	return 0;
}