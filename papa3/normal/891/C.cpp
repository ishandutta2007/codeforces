#include <map>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#ifndef d
#define d(...)
#endif
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<typename t>using V=vector<t>;

struct Edge
{
    int p, q, wg;
    Edge( int p, int q, int wg ) : p( p ), q( q ), wg( wg ) {}
};

inline bool operator< ( const Edge& mn, const Edge& wc )
{
    return mn.wg < wc.wg;
}

struct Node
{
    int lid, siz = 1;
};

struct Ev
{
    int id, wg;
    V< Edge > tab;
    Ev( int id, int wg, V< Edge > tab ) : id( id ), wg( wg ), tab( tab ) {}
};

inline bool operator< ( const Ev& mn, const Ev& wc )
{
    return mn.wg < wc.wg;
}

int n, t, m, q;
V< Ev > ilo;
V< Edge > tab;
V< Node > graf;
V< bool > odp;
V< int > odw;

inline int find ( int v )
{
    return graf[v].lid == graf[graf[v].lid].lid? graf[v].lid : graf[v].lid = find( graf[v].lid );
}

void add ( const Edge& ed )
{
    if ( find( ed.p ) == find( ed.q ) ) return;
    int a = find( ed.p );
    int b = find( ed.q );
    if ( graf[a].siz < graf[b].siz ) 
        swap( a, b );
    graf[a].siz += graf[b].siz;
    graf[b].lid = a;
}

inline bool dfs ( int v, int oj, map< int, V< int > >& M )
{
    odw[v] = t;
    V< int >& sas = M[v];
    for ( auto s : sas )
        if ( s == oj ) continue;
        else if ( odw[s] == t ) return false;
        else if ( dfs( s, v, M ) == false ) return false;
    return true;
}

bool spr ( const Ev& v )
{
    ++t;
    map< int, V< int > > M;
    for ( auto& ed : v.tab ) 
    {
        M[find( ed.p )].emplace_back( find( ed.q ) );
        M[find( ed.q )].emplace_back( find( ed.p ) );
    }
//    d( v.id << ' ' << v.wg << '\n' );
//    for ( auto& i : M )
//    {
//        d( i.first << ": " );
//        for ( auto s : i.second )
//            d( s << ' ' );
//        d( '\n' );
//    }
    for ( auto& v : M )
        if ( odw[v.first] < t )
            if ( dfs( v.first, -1, M ) == false )
                return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    odw.resize( n + 1 );
    graf.resize( n + 1 );
    for ( int i = 1; i <= n; ++i )
        graf[i].lid = i;
    tab.emplace_back( -1, -1, INT_MAX );
    for ( int i = 1; i <= m; ++i )
    {
        int p, p2, wg; cin >> p >> p2 >> wg;
        tab.emplace_back( p, p2, wg );
    }
    cin >> q;
    odp.resize( q + 1, true );
    for ( int i = 1; i <= q; ++i )
    {
        int k; cin >> k;
        map< int, V< Edge > > M;
        while ( k-- )
        {
            int p; cin >> p;
            M[tab[p].wg].emplace_back( tab[p] );
        }
        for ( auto& v : M )
            ilo.emplace_back( i, v.first, v.second );  
    }
    sort( ALL( ilo ) );
    sort( ALL( tab ) );
    int pt = 0;
    for ( auto& v : ilo )
    {
        while ( tab[pt].wg < v.wg )
        {
            add( tab[pt] );
            ++pt;
        }
        if ( spr( v ) == false )
            odp[v.id] = false;          
    }
	while ( pt < tab.size() - 1 )
	{
		add( tab[pt] ); ++pt;
	}
	
	bool fl = true;
//	int wz = find( 1 );
//	for ( int i = 2; i <= n; ++i )
//		if ( find( i ) != wz )
//			fl = false;
//    
    for ( int i = 1; i <= q; ++i )
        cout << ( odp[i] and fl? "YES" : "NO" ) << '\n';
}