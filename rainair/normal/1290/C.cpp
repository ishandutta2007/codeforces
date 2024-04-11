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

const int MAXN = 6e5 + 5;

int f[MAXN],val[MAXN];

inline int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

inline void merge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx == fy) return;
	f[fy] = fx;val[fx] += val[fy];
}

std::vector<int> G[MAXN];
int n,k,ans;
char str[MAXN];

inline int get(int x){
	return std::min(val[find(x)],val[find(x+k)]);
}

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",str+1);
	FOR(i,1,k){
		int t;scanf("%d",&t);
		while(t--){
			int x;scanf("%d",&x);
			G[x].pb(i);
		}
	}
	FOR(i,1,2*k) f[i] = i;FOR(i,1,k) val[i] = 1;// i+n 
	int S = 2*k+1;f[S] = S;val[S] = 1e9;
	FOR(i,1,n){
		if(G[i].size() == 1){
			ans -= get(G[i][0]);
			merge(G[i][0]+(str[i]=='0')*k,S);
			ans += get(G[i][0]);
		}
		if(G[i].size() == 2){
			if(str[i] == '0' && find(G[i][0]) != find(G[i][1]+k)){
				ans -= get(G[i][0])+get(G[i][1]);
				merge(G[i][0],G[i][1]+k);
				merge(G[i][0]+k,G[i][1]);
				ans += get(G[i][0]);
			}
			if(str[i] == '1' && find(G[i][0]) != find(G[i][1])){
				ans -= get(G[i][0])+get(G[i][1]);
				merge(G[i][0],G[i][1]);
				merge(G[i][0]+k,G[i][1]+k);
				ans += get(G[i][0]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}