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

int main(){
	int n,k;scanf("%d%d",&n,&k);
	int ans = 0;
	int r = 4*60 - k;
	FOR(i,1,n){
		if(i*5 <= r) r -= i*5,++ans;
	}
	printf("%d\n",ans);
	return 0;
}