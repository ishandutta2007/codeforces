#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+1;
vector <int> graf[N], buds;

//1 -- cos, 0 -- nic, for root -- num of leaves
int dfs (int a, int b)
{
	int cnt = 0;
	for (int s: graf[a]) if (s!=b) {
		cnt += dfs(s, a);
	}
	
	if (a == 1) return cnt;

	if (cnt == 0) return 1; //we are a leaf
	else { //we are a bud
		buds.pb(cnt);
		return 0;
	}
}

int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		rep(i,1,n+1) graf[i].clear();
		buds.clear();
		
		rep(i,1,n) {
			int a, b;
			scanf ("%d %d", &a, &b);
			graf[a].pb(b);
			graf[b].pb(a);
		}
		
		int leaves = dfs(1,0);
		
		int sum = 0;
		for (int l: buds) sum += l;
		
		if (leaves == 0) printf ("%d\n", sum - (int)buds.size() + 1);
		else printf ("%d\n", leaves + sum - (int)buds.size());
	}
}