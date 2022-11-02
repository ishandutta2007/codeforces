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

struct Node{
	int x,d,id;
	Node(int x=0,int d=0,int id=0) : x(x),d(d),id(id) {}

	bool operator < (const Node &t) const {
		return x == t.x ? d < t.d : x < t.x;
	}
}a[MAXN];

int n,m,k,N;
int pc[(1<<15)+3];
//  f[i][S]  i  S 
//   1 
int pos[MAXN];// 
int g[MAXN];// 
int f[2][(1<<15)+3];
int now = 0;

inline int find0(int x){
	FOR(i,0,9) if(!((x>>i)&1)) return i;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,(1<<15)) pc[i] = pc[i>>1]+(i&1);
	FOR(i,1,n){
		int l,r;scanf("%d%d",&l,&r);
		a[++N] = Node(l,1,i);a[++N] = Node(r+1,-1,i);
	}
	std::sort(a+1,a+N+1);
	FOR(i,0,N-1){
		int dis = a[i+1].x-a[i].x;
		if(i == 0) dis = 0;
		// DEBUG(dis);
		if(a[i+1].d == 1){
			int t = find0(g[i]);
			pos[a[i+1].id] = t;
			g[i+1] = g[i]|(1<<t);
			FOR(S,0,(1<<k)-1){
				if((S|g[i]) != g[i]) continue;
				f[now^1][S] = std::max(f[now^1][S],f[now][S]+(pc[S]&1 ? dis : 0));
				f[now^1][S|(1<<t)] = std::max(f[now^1][S|(1<<t)],f[now][S]+(pc[S]&1 ? dis : 0));
			}
		}
		else{
			int t = pos[a[i+1].id];
			g[i+1] = g[i]^(1<<t);
			FOR(S,0,(1<<k)-1){
				if((S|g[i]) != g[i]) continue;
				// f[i+1][S] = std::max(f[i+1][S],f[i][S]+(pc[S]&1?dis:0));
				// if(i == 4 && S == 2)
				if(!((S>>t)&1)) f[now^1][S] = std::max(f[now^1][S],f[now][S]+(pc[S]&1?dis:0));
				else f[now^1][S^(1<<t)] = std::max(f[now^1][S^(1<<t)],f[now][S]+(pc[S]&1?dis:0));
			}
		}
		now ^= 1;
	}
	// DEBUG(f[4][0]);
	int ans = 0;
	FOR(S,0,(1<<k)-1){
		if((S|g[N]) != g[N]) continue;
		ans = std::max(ans,f[now][S]);
	}
	printf("%d\n",ans);
	return 0;
}