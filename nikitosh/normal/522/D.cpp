#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#define FNAME "1"

const int INF = 1e9;          
const int MAXN = 5e5 + 5;

int n, m, N, a[MAXN], ans[MAXN], t[6 * MAXN];
unordered_map <int, int> last;

void update (int v, int vl, int vr, int ind, int dlt)
{
	if (ind < vl || ind >= vr)
		return;
	if (ind == vl && ind == vr - 1)
	{
		t[v] += dlt;
		return;
	}
	update(2 * v, vl, (vl + vr) / 2, ind, dlt);
	update(2 * v + 1, (vl + vr) / 2, vr, ind, dlt);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get (int v, int vl, int vr, int l, int r)
{
	if (vl >= r || l >= vr)
		return INF;
	if (vl >= l && vr <= r)
		return t[v];
	return min(get(2 * v, vl, (vl + vr) / 2, l, r), get(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

struct Query
{
	int l, r, ind;
	Query(): l(0), r(0), ind(0) {}
	void read (int i)
	{
		scanf("%d%d", &l, &r);
		l--;
		r--;
		ind = i;
	}
	bool operator < (const Query &a) const
	{
		if (r == a.r)
		{
			if (l == a.l)
				return ind < a.ind;
			return l < a.l;
		}
		return r < a.r;
	}
};

Query query[MAXN];

int main()
{
    //freopen(FNAME".in", "r", stdin);
    //freopen(FNAME".out", "w", stdout); 
	scanf("%d%d", &n, &m);
	N = 1;
	while (N < n)
		N <<= 1;
	for (int i = 0; i <= 2 * N; i++)
		t[i] = INF;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		query[i].read(i);
	sort(query, query + m);
	int it = 0;
	for (int i = 0; i < n; i++)
	{   
		int k = last[a[i]];
		if (k != 0)
			update(1, 0, N, k - 1, -INF + i - (k - 1));
		last[a[i]] = i + 1;
		while (it < m && query[it].r == i)
		{
			ans[query[it].ind] = get(1, 0, N, query[it].l, query[it].r + 1);
			it++;
		}
	} 
	for (int i = 0; i < m; i++)
		if (ans[i] == INF)
			printf("%d\n", -1);
		else
			printf("%d\n", ans[i]);
    return 0;
}