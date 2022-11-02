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

const int MAXN = 5e5 + 5;
int n,a[MAXN];
LL res = 0;
int t[MAXN];
bool vis[MAXN];
LL cf[MAXN];
int gg[MAXN];

inline void work(int g){
	FOR(i,0,g) t[i] = 0;
	FOR(i,0,2*n-1) t[i%g] = std::max(t[i%g],a[i]);
	FOR(i,0,2*n-1) vis[i] = (a[i] == t[i%g]);
	int t = 0;
	FOR(i,0,n*2+1) cf[i] = 0;
	FOR(i,n,2*n-1){
		if(!vis[i]) break;
		++t;
	}
	ROF(i,n-1,0){
		if(!vis[i]){
			t = 0;
		}
		else{
			++t;
			cf[t]++;
		}
	}
	ROF(i,2*n,1) cf[i] += cf[i+1];
	FOR(i,1,n-1) if(gg[i] == g) res += cf[i];
}

int main(){
	scanf("%d",&n);
	FOR(i,0,n-1) scanf("%d",a+i);
	FOR(i,1,n) gg[i] = std::__gcd(n,i);
	FOR(i,n,2*n-1) a[i] = a[i-n];
	// work(1);
	// DEBUG(res);
	// exit(0);
	FOR(i,1,n-1){
		if(n%i == 0) work(i);
	}
	printf("%lld\n",res);
	return 0;
}