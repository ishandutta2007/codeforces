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

const int MAXN = 1e5 + 5;
int dep[MAXN],cnt[MAXN];
int n;

int main(){
	scanf("%d",&n);
	FOR(i,2,n){
		int f;scanf("%d",&f);
		dep[i] = dep[f]+1;
	}
	FOR(i,1,n) cnt[dep[i]]++;
	int ans = 0;
	FOR(i,0,n) ans += cnt[i]%2;
	printf("%d\n",ans);
	return 0;
}