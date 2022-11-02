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

const int MAXN = 3e5 + 5;
int n;
LL val[MAXN],msk[MAXN];
/*
0/1
O(n)
*/
const int MAXM = 61;
std::vector<int> G[MAXM+1];

int main(){
	scanf("%d",&n);
	LL sm = 0;
	FOR(i,1,n){
		scanf("%lld%lld",val+i,msk+i),sm += val[i];
		ROF(j,MAXM,0) if((msk[i]>>j)&1) {G[j].pb(i);break;}
	}
	LL ans = 0;
	while(true){
		FOR(i,0,MAXM){
			LL t = 0;
			for(auto x:G[i]) t += val[x];
			if(t == 0) continue;
			if((sm > 0) ^ (t > 0)) continue;
			ans ^= (1ll<<i);
			FOR(j,1,n) if((msk[j]>>i)&1) val[j] = -val[j];
		}
		LL chk = 0;
		FOR(i,1,n) chk += val[i];
		if((chk>0)^(sm>0)) break;
	}
	// assert((chk>0)^(sm>0));
	printf("%lld\n",ans);
	return 0;
}