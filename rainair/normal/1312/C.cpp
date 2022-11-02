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

int n,k;
int t[233];

inline void Solve(){
	scanf("%d%d",&n,&k);CLR(t,0);
	FOR(i,1,n){
		LL x;scanf("%lld",&x);int len=0;
		while(x){
			t[len++]+=x%k;x /= k;
		}
	}
			FOR(i,0,232) if(t[i] > 1){
			puts("NO");return;
		}
			puts("YES");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}