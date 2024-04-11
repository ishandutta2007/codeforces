#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
char s[MAXN],t[MAXN];
int n,t1[3],t2[3];
int tmp[MAXN];

inline void Solve(){
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	CLR(t1,0);CLR(t2,0);
	FOR(i,1,n) ++t1[s[i]-'a'],++t2[t[i]-'a'];
	FOR(i,0,2) if(t1[i] != t2[i]){
		puts("NO");
		return;
	}
	int p = 0;
	FOR(i,1,n){
		if(s[i] == 'b') continue;
		tmp[++p] = s[i]-'a';
	}
	p = 0;
	FOR(i,1,n){
		if(t[i] == 'b') continue;
		if(tmp[++p] != t[i]-'a'){
			puts("NO");
			return;
		}
	}
	p = 0;
	FOR(i,1,n) if(s[i] == 'a'){
		tmp[++p] = i;
	}
	p = 0;
	FOR(i,1,n) if(t[i] == 'a'){
		if(tmp[++p] > i){
			puts("NO");
			return;
		}
	}
	p = 0;
	ROF(i,n,1) if(s[i] == 'c'){
		tmp[++p] = i;
	}
	p = 0;
	ROF(i,n,1) if(t[i] == 'c'){
		if(tmp[++p] < i){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}