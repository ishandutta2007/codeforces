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
int n,a[MAXN],b[MAXN];
std::vector<P<int,int> > res;

inline void Solve(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n) scanf("%d",b+i);
	res.clear();
	FOR(i,1,n){
		int p = i;
		FOR(j,i+1,n) p = a[p] < a[j] ? p : j;
		if(p != i){
			std::swap(a[i],a[p]);
			std::swap(b[i],b[p]);
			res.pb(i,p);
		}
	}
	for(int l = 1,r;l <= n;++l){
		r = l;while(r+1 <= n && a[r+1] == a[l]) ++r;
		FOR(i,l,r){
			int p = i;
			FOR(j,l+1,r) p = b[p] < b[j] ? p : j;
			if(p != i){
				std::swap(a[i],a[p]);
				std::swap(b[i],b[p]);
				res.pb(i,p);
			}
		}
	}
	bool flag = 1;
	FOR(i,2,n) flag &= (a[i-1] <= a[i] && b[i-1] <= b[i]);
	if(!flag){
		puts("-1");
		return;
	}
	printf("%d\n",SZ(res));
	for(auto x:res) printf("%d %d\n",x.fi,x.se);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}