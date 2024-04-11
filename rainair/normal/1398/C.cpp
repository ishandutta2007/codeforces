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

const int MAXN = 2e5 +5;

char str[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL ans = 0;
		int n;scanf("%d",&n);scanf("%s",str+1);
		std::map<int,int> S;
		S[0] = 1;int sm = 0;
		FOR(i,1,n){
			sm += str[i]-'0';
			ans += S[sm-i];
			S[sm-i]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}