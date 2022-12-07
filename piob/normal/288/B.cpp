#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

/*
int P[8];
int vis[8];

bool dfs(int u){
	vis[u] = 1;
	if(vis[P[u]] == 2) return 1;
	if(vis[P[u]] == 1) return 0;
	if(!dfs(P[u])) return 0;
	vis[u] = 2;	
	return 1;
}

int n, k, p, m;

bool test(){
	FWD(i,0,k) vis[i] = 0;
	vis[0] = 2;
	FWD(i,1,k) if(!dfs(i)) return 0;
	FWD(i,0,k) printf("%d ", P[i]);
	printf("\n");
	return 1;
}

*/

int n, k;
long long r;

int main(){
	scanf("%d %d", &n, &k);
	r = 1;
	FWD(i,0,k-1) r = (r * k) % 1000000007LL;
	FWD(i,0,n-k) r = (r* (n-k))% 1000000007LL;
	printf("%d\n", (int)r);
	return 0;
}