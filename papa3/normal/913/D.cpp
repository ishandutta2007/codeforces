#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
//#define x first
//#define y second
//#define ilo( a, b, c ) ( (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) )
#define kwadrat( a ) ( (a)*(a) )
#define odleglosc( a, b ) ( kwadrat( a.x-b.x )+kwadrat( a.y-b.y ) )

int tab[100];
int tab2[100];

struct moj {
    int a, t, id;

    bool operator < ( const moj & other ) const {
        return t < other.t;
    }
};

vector<moj> v;
int n, t;

int algo( int x, bool wypisz=false ) {
    int res=0;
    int czas=0;
    vector<int> wy;
    for( auto & i : v ) {
        if( i.a < x ) continue;
        if( czas+i.t <= t ) {
            czas+=i.t;
            res++;
            if( wypisz ) wy.push_back( i.id );
        }
    }
    res = min( res, x );
    if( !wypisz ) return res;

    cout << res << "\n" << res << "\n";
    for( int i=0; i<res; i++ ) cout << wy[i] << " ";
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> t;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        v.push_back( {a, b, i} );
    }
    sort( v.begin(), v.end() );

    int pocz=0, kon=n+100, sr;
    while( kon-pocz>1 ) {
        sr = (pocz+kon)/2;
        if( algo( sr ) < algo( sr+1 ) )
            pocz = sr;
        else
            kon = sr;
    }
    algo( pocz+1, 1 );

    return 0;
}