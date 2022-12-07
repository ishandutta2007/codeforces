#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000009;
const LL INF = 2000000000LL * 2000000000LL;

int n, m, r;
vector<int> E[100010];
bool vis[100010];
set<int> S;

void dfs(int u){
	if(E[u].size() != 2){
		S.insert(u);
		return;
	}
	vis[u] = 1;
	for(int v : E[u]) if(!vis[v]) dfs(v);
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	FWD(i,1,n+1) if(E[i].size()&1) ++r;
	FWD(i,1,n+1) if(E[i].size() == 2 && !vis[i]){
		S.clear();
		dfs(i);
		if(S.size() <= 1)
			r += 2;
	}
	printf("%d %d\n", r/2, m);
	return 0;
}