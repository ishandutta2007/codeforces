#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
const int ha = 998244353;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

std::vector<int> a[MAXN];
int cnt[MAXN];
int n;

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int k,x;scanf("%d",&k);
		while(k--){
			scanf("%d",&x);++cnt[x];a[i].pb(x);
		}
	}
	int invn = qpow(n),ans = 0;
	FOR(i,1,n){
		int invi = qpow((int)a[i].size());
		for(auto x:a[i]){
			(ans += 1ll*cnt[x]*invi%ha*invn%ha) %= ha;
		}
	}
	printf("%lld\n",1ll*ans*invn%ha);
	return 0;
}