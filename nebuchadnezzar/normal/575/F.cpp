#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > pii;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second       
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)



LL getlen(LL x, int l, int r) {
	if (x >= l && x <= r)
		return 0;
	else if (x < l)
		return (LL)l - x;
	else
		return (LL)x - r;
}

const int N = 5000;
int n, x;
int k;

vector < LL > pts;
vector < pii > segs;
    

LL dp[2][N * 2 + 1 + 7];

LL back[N * 2 + 1 + 7], front[N * 2 + 1 + 7];

int wherex;

int main() {
	scanf("%d%d", &n, &x);
	pts.pb(x);
	forn(i, n) {
		pii q;
		scanf("%d%d", &q.ff, &q.ss);	
		segs.pb(q);
		pts.pb((LL)q.ff), pts.pb((LL)q.ss);
	}
	sort(pts.begin(), pts.end());
	k = pts.size();

	int r = 0;
	forn(i, k) {
		dp[r][i] = getlen(pts[i], segs[n - 1].ff, segs[n - 1].ss);
	//	printf("%d ", dp[n - 1][i]);
		if (pts[i] == x)
			wherex = i;
	}
	//printf("\n\n");
	for (int i = n - 2; i >= 0; --i) {
		int nr = r;
		r = 1 - r;
		forn(j, k)
			dp[r][j] = dp[nr][j] + getlen(pts[j], segs[i].ff, segs[i].ss);
		
		back[0] = dp[r][0];
		for (int j = 1; j < k; ++j)
			back[j] = min(dp[r][j], back[j - 1] + pts[j] - pts[j - 1]);
		
		front[k - 1] = dp[r][k - 1];
		for (int j = k - 2; j >= 0; --j)
			front[j] = min(dp[r][j], front[j + 1] + pts[j + 1] - pts[j]);
	
		forn(j, k)
			dp[r][j] = min(back[j], front[j]);

	}


	printf("%I64d\n", dp[r][wherex]);

	return 0;
}