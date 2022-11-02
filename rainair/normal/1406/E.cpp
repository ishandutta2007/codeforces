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
int prime[MAXN],cnt,n;
bool p[MAXN];

inline void prework(){
	FOR(i,2,100000){
		if(!p[i]) prime[++cnt] = i;
		for(int j = 1;j <= cnt && i*prime[j] < MAXN;++j){
			p[i*prime[j]] = 1;
			if(!(i%prime[j])) break;
		}
	}
}

inline int A(int x){
	if(x > n) return 0;
	printf("A %d\n",x);std::fflush(stdout);
	int res;scanf("%d",&res);return res;
}

inline int B(int x){
	if(x > n) return 0;
	printf("B %d\n",x);std::fflush(stdout);
	int res;scanf("%d",&res);return res;
}

int main(){
	prework();
	scanf("%d",&n);
	int q = std::sqrt(1.0*n);
	FOR(i,1,cnt) if(prime[i] <= q) B(prime[i]);
	int ans = 1;
	FOR(i,1,cnt){
		if(prime[i] > q) break;
		int t = 1;
		while(A(t*prime[i])) t *= prime[i];
		ans *= t;
	}
	std::vector<int> dec;dec.pb(1);
	FOR(i,1,cnt){
		if(prime[i] <= q) continue;
		if(prime[i] > n) break;
		dec.pb(prime[i]);
	}
	if(ans == 1){
		int l = 1,r = (int)dec.size()-1;
		while(l <= r){
			int mid = (l + r) >> 1;
			FOR(i,l,mid) B(dec[i]);
			int t = A(1);
			if(t == r-mid+1) l = mid+1;
			else{
				FOR(i,l,mid) if(B(dec[i])){
					ans *= dec[i];break;
				}
				break;
			}
		}
	}
	else{
		for(auto x:dec){
			if(x == 1) continue;
			if(1ll*ans*x > n) break;
			if(A(ans*x)){
				ans *= x;break;
			}
		}
	}
	printf("C %d\n",ans);std::fflush(stdout);
	return 0;
}