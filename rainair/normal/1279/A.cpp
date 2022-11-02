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
		std::vector<int> v;
		FOR(i,1,3){
			int x;scanf("%d",&x);v.pb(x);
		}
		std::sort(all(v));
		if(v[2] <= v[0]+v[1]+1) puts("Yes");
		else puts("No");
	}
	return 0;
}