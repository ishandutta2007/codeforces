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
const int ha = 1e9 + 7;
char str[MAXN];
int n;
int cnt[300];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int main(){
	scanf("%d",&n);scanf("%s",str+1);
	FOR(i,1,n) ++cnt[str[i]];
	int mx = std::max({cnt['A'],cnt['G'],cnt['C'],cnt['T']});
	int t = 0;
	FOR(i,1,299) if(cnt[i] == mx) ++t;
	printf("%d\n",qpow(t,n));
	return 0;
}