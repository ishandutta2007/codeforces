#include <stdio.h>
#include <vector>

#define N 100010
#define MOD 1000000007

#define BLACK 1
#define WHITE 0

#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LL long long

using namespace std;

typedef pair<LL, LL> pll;

vector<int> adj[N];
int col[N];
int n;

pll dfs(int u, int p) {
	LL dp1 = 1, dp2 = 0;
	vector<LL> ls1;
	vector<LL> ls2;
	vector<LL> s1, s2;
	
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(v == p) continue;
		pll r = dfs(v, u);
		ls1.PB(r.A);
		ls2.PB(r.B);
		s1.PB(0);
		s2.PB(0);
	}
	for(int i = 0;i < ls1.size();i++) {
		dp1 = (dp1 * ls1[i]) % MOD;
	}
	if(col[u] == BLACK) {
		return MP(dp1, dp1);
	}
	for(int i = 0;i < s1.size();i++) {
		if(i == 0) {
			s1[i] = ls1[i];
		}else {
			s1[i] = (s1[i-1] * ls1[i]) % MOD;
		}
	}
	for(int i = s2.size()-1;i >= 0;i--) {
		if(i == s2.size()-1) {
			s2[i] = ls1[i];
		}else {
			s2[i] = (s2[i+1] * ls1[i]) % MOD;
		}
	}
	for(int i = 0;i < ls2.size();i++) {
		if(i == 0 && i == ls2.size()-1) {
			dp2 += ls2[i];
		}else if(i == 0) {
			dp2 += s2[i+1] * ls2[i];
		}else if(i == ls2.size()-1) {
			dp2 += s1[i-1] * ls2[i];
		}else {
			dp2 += ((s1[i-1] * s2[i+1]) % MOD) * ls2[i];
		}
		dp2 %= MOD;
	}
	dp1 = (dp1 + dp2) % MOD;
	return MP(dp1, dp2);
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n-1;i++) {
		int p;
		scanf("%d", &p);
		adj[p].push_back(i+1);
		adj[i+1].push_back(p);
	}
	for(int i = 0;i < n;i++) {
		scanf("%d", &col[i]);
	}
	pll r = dfs(0, -1);
	printf("%I64d\n", r.B);
	return 0;
}