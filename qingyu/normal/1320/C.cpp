#include <bits/stdc++.h>

typedef long long ll;
const int	MAXN = 2e5 + 5;
ll	mx[MAXN << 2], tag[MAXN << 2];
#define lc	( (x) << 1)
#define int ll
#define rc	( (x) << 1 | 1)

inline void pushup( int x )
{
	mx[x] = std::max( mx[lc], mx[rc] );
}


inline void cover( int x, ll d )
{
	mx[x] += d; tag[x] += d;
}


inline void pushdown( int x )
{
	if ( tag[x] )
	{
		cover( lc, tag[x] ); cover( rc, tag[x] );
		tag[x] = 0;
	}
}


inline void modify( int x, int l, int r, int L, int R, ll d )
{
	if ( l == L && r == R )
	{
		cover( x, d ); return;
	}
	int mid = (l + r) >> 1; pushdown( x );
	if ( R <= mid )
		modify( lc, l, mid, L, R, d );
	else if ( L > mid )
		modify( rc, mid + 1, r, L, R, d );
	else modify( lc, l, mid, L, mid, d ), modify( rc, mid + 1, r, mid + 1, R, d );
	pushup( x );
}


inline ll query( int x, int l, int r, int L, int R )
{
	if ( l == L && r == R )
		return(mx[x]);
	pushdown( x ); int mid = (l + r) >> 1;
	if ( R <= mid )
		return(query( lc, l, mid, L, R ) );
	if ( L > mid )
		return(query( rc, mid + 1, r, L, R ) );
	return(std::max( query( lc, l, mid, L, mid ), query( rc, mid + 1, r, mid + 1, R ) ) );
}


std::pair<int, int> a[MAXN], b[MAXN];
inline void build( int x, int l, int r )
{
	if ( l == r )
	{
		mx[x] = -b[l].second; return;
	}
	int mid = (l + r) >> 1;
	build( lc, l, mid ); build( rc, mid + 1, r );
	pushup( x );
}


int		n, m, p;
std::pair<std::pair<int, int>, int>	c[MAXN];
std::vector<int>	G;

inline bool cmp( int a, int b )
{
	return(a <= b);
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
 
inline long long read()
{
	ll res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}


signed main()
{
	n = read(), m = read(), p = read();
	for (int i = 1; i <= n; ++i) a[i].first = read(), a[i].second = read();
	for (int i = 1; i <= m; ++i) 
	{
		b[i].first = read(), b[i].second = read();
		 G.push_back( b[i].first );
	}
	
	for (int i = 1; i <= p; ++i) 
	{
		c[i].first.first = read();
		c[i].first.second = read(); 
		c[i].second = read();
	}
	std::sort( a + 1, a + n + 1 ); std::sort( b + 1, b + m + 1 ); std::sort( c + 1, c + p + 1 ); build( 1, 1, m );
	std::sort(G.begin(), G.end());
	
	int ps = 1; ll ans = -1e18;
	for (int i = 1; i <= n; ++i)
	{
		while ( ps <= m && c[ps].first.first < a[i].first )
		{
			int p = std::lower_bound( G.begin(), G.end(), c[ps].first.second, cmp ) - G.begin();
			if ( p < m )
				modify( 1, 1, m, p + 1, m, c[ps].second );
			ps++;
		}
		ans = std::max( ans, mx[1] - a[i].second );
	}
	printf( "%lld\n", ans );
	
	return(0);
}