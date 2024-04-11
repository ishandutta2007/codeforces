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

const int MAXN = 5000+5;
bool vis[MAXN];char str[233];

inline void query(int x){
	if(vis[x]) return;
	printf("? %d\n",x);std::fflush(stdout);
	scanf("%s",str+1);
	if(str[1]=='Y') vis[x] = 1;
}

inline void reset(){
	puts("R");std::fflush(stdout);
}

int main(){
	int n,k;scanf("%d%d",&n,&k);
	if(k == 1){
		FOR(i,1,n){
			FOR(j,i+1,n){
				reset();
				query(i);query(j);
			}
		}
	}
	else{
		FOR(i,1,n) query(i);
		for(int i = 1;i <= n;i += k){
			for(int j = 1;j < i;j += k){
				reset();
				FOR(l,i,i+k/2-1) query(l);
				FOR(l,j,j+k/2-1) query(l);
				FOR(l,i+k/2,i+k-1) query(l);
				reset();
				FOR(l,i,i+k/2-1) query(l);
				FOR(l,j+k/2,j+k-1) query(l);
				FOR(l,i+k/2,i+k-1) query(l);
			}
		}
	}
	int ans = 0;
	FOR(i,1,n) ans += !vis[i];
	printf("! %d\n",ans);std::fflush(stdout);
	return 0;
}