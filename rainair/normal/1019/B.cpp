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

inline int query(int x){
	printf("? %d\n",x);std::fflush(stdout);
	int res;scanf("%d",&res);return res;
}

int n;

inline bool chk(int x){ // 1-based
	--x;int t1 = query(x+1),t2 = query((x+n/2)%n+1);
	if(t1 == t2){
		printf("! %d\n",x+1);std::fflush(stdout);exit(0);
	}
	return t1-t2 < 0;
}

int main(){
	scanf("%d",&n);
	if(n%4){
		printf("! -1\n");std::fflush(stdout);
		return 0;
	}
	bool t = chk(1);
	int l = 2,r = n/2,ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(chk(mid) == t) ans = mid,l = mid+1;
		else r = mid-1;
	}
	return 0;
}