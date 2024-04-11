#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

#define MAXN 200010
VI Map[MAXN];

PII dfs1(int u, int fa = -1) {
	int res0 = 1, res1 = 1, res2 = 1;
	REP(i,Map[u].size()) {
		int v = Map[u][i];
		if(v == fa) continue;
		PII p = dfs1(v, u);
		int r0 = res0 + p.Y;
		int r1 = res1 + p.Y;
		int r2 = res2 + p.Y;
		r1 = min(r1, res0 + p.X - 1);
		r2 = min(r2, res1 + p.X - 1);
		res0 = r0;
		res1 = r1;
		res2 = r2;
	}
	return MP(res1, res2);
}

int D[MAXN];
int cnt0 = 0, cnt1 = 0;

void dfs2(int u, int fa = -1, int d = 0) {
	D[u] = d;
	if(d == 0) cnt0++;
	if(d == 1) cnt1++;
	REP(i,Map[u].size()) {
		int v = Map[u][i];
		if(v == fa) continue;
		dfs2(v, u, d^1);
	}
}

int main()
{
#ifdef LOCAL
	   //freopen("x.in","r",stdin);
	   //freopen("x.out","w",stdout);
#endif
	int n, x, y;
	scanf("%d%d%d",&n,&x,&y);
	REP(i,n-1) {
		int u,v;
		scanf("%d%d",&u,&v);
		u--; v--;
		Map[u].PB(v);
		Map[v].PB(u);
	}
	if(x < y) {
		PII p = dfs1(0);
		printf("%I64d\n", 1LL * (n-p.Y)*x + 1LL*(p.Y-1)*y);
	}else{
		dfs2(0);
		int ok = 0;
		REP(u,n) {
			int c = 0;
			REP(j,Map[u].size()) {
				int v = Map[u][j];
				if(D[u] != D[v]) c++; 
			}
			if(D[u] == 0 && c < cnt1) ok = 1;
			if(D[u] == 1 && c < cnt0) ok = 1;
		}
		if(ok == 1)
			printf("%I64d\n", 1LL*y*(n-1));
		else
			printf("%I64d\n", 1LL*y*(n-2)+x);	
	}
	return 0;
}