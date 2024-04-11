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

const int MAXN = 100+5;
int n;
char str[MAXN];

inline void Solve(){
	scanf("%d",&n);scanf("%s",str+1);
	FOR(i,1,n) printf("%d",str[n]-'0');puts("");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}