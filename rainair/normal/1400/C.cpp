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
int ans[MAXN],x,n;
char str[MAXN];

inline bool chk(){
	FOR(i,1,n){
		int p1 = i-x <= 0 ? 0 : i-x;
		int p2 = i+x > n ? 0 : i+x;
		if(str[i] == '1'){
			if((ans[p1]|ans[p2]) == 0) return 0;
		}
		else{
			if((ans[p1]&ans[p2]) == 1) return 0;
		}
	}
	return 1;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);n = strlen(str+1);
		scanf("%d",&x);
		FOR(i,1,n) ans[i] = 1;
		FOR(i,1,n){
			if(str[i] == '0'){
				if(i-x >= 1) ans[i-x] = 0;
				if(i+x <= n) ans[i+x] = 0;
			}
		}
		if(!chk()) puts("-1");
		else{
			FOR(i,1,n) printf("%d",ans[i]);puts("");
		}
	}
	return 0;
}