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

int a[3][3];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		bool flag = 0;
		FOR(i,1,n){
			FOR(x,1,2) FOR(y,1,2) scanf("%d",&a[x][y]);
			flag |= (a[1][2]==a[2][1]);
		}
		if(m&1){
			puts("NO");
			continue;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}