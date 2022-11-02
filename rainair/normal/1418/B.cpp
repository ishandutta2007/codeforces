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

int a[MAXN],l[MAXN],n;
LL sm[MAXN];

inline void Solve(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n) scanf("%d",l+i);
	std::vector<int> S;
	FOR(i,1,n) if(!l[i]) S.pb(a[i]);
	std::sort(all(S));std::reverse(all(S));int t = 0;
	FOR(i,1,n) if(!l[i]) a[i] = S[t],++t;
	FOR(i,1,n) printf("%d ",a[i]);puts("");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}