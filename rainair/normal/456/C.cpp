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
int n,a[MAXN],m;
LL f[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int x;scanf("%d",&x);++a[x];m = std::max(m,x);
	}
	FOR(i,0,m) f[i] = 1e18;
	f[0] = 0;
	FOR(i,1,m){
		f[i] = f[i-1];
		f[i] = std::max(f[i],(i==1?0:f[i-2])+1ll*a[i]*i);
	}
	printf("%lld\n",f[m]);
	return 0;
}