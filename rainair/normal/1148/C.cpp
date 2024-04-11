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
int a[MAXN],n;
std::vector<P> ans;
int ps[MAXN];

inline void work(int x,int y){
	if(x > y) std::swap(x,y);
	if(2*(y-x) >= n){
		ans.pb(MP(x,y));
		return;
	}
	if(x == 1 && y == n){
		ans.pb(MP(x,y));
		return;
	}
	if(x == 1){
		ans.pb(MP(1,n));
		ans.pb(MP(y,n));
		ans.pb(MP(1,n));	
		return;
	}
	if(y == n){
		ans.pb(MP(1,n));
		ans.pb(MP(1,x));
		ans.pb(MP(1,n));
		return;
	}
	if((x-1)*2 >= n && (y-1)*2 >= n){
		ans.pb(MP(1,x));
		ans.pb(MP(1,y));
		ans.pb(MP(1,x));
		return;
	}
	if((n-x)*2 >= n && (n-y)*2 >= n){
		ans.pb(MP(x,n));
		ans.pb(MP(y,n));
		ans.pb(MP(x,n));
		return;
	}
	ans.pb(MP(x,n));
	ans.pb(MP(1,y));
	ans.pb(MP(1,n));
	ans.pb(MP(x,n));
	ans.pb(MP(1,y));
}
int t[MAXN];
int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i),ps[a[i]] = i,t[i] = a[i];
	FOR(i,1,n){
		if(ps[i] == i) continue;
		work(i,ps[i]);
		// printf("%d %d\n",i,ps[i]);
		ps[a[i]] = ps[i];
		std::swap(a[i],a[ps[i]]);
		ps[i] = i;
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se),assert(2*(x.se-x.fi) >=n),std::swap(t[x.fi],t[x.se]);
	FOR(i,1,n) assert(t[i]==i);
	return 0;
}