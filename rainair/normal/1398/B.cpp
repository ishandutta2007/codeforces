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

char str[MAXN];
int n;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);n = strlen(str+1);
		int cnt = 0;std::vector<int> S;
		FOR(i,1,n){
			if(str[i] == '1'){
				++cnt;
			}
			else{
				if(cnt) S.pb(cnt);
				cnt = 0;
			}
		}
		if(cnt) S.pb(cnt);
		std::sort(all(S));std::reverse(all(S));
		int ans = 0;
		for(int i = 0;i < S.size();i += 2) ans += S[i];
		printf("%d\n",ans);
	}
	return 0;
}