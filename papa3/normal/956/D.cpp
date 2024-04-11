#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define MAX_N 300010

struct moj {
    int a, b, id, v;
    bool jak;

    bool operator < ( const moj & other ) const {
        if( a*other.b == other.a*b ) {
            if( !jak ) {
                if( v/abs(v) == other.v/abs(other.v) )
                    return other.v < v;
                return v < 0;
            } else {
                if( v/abs(v) == other.v/abs(other.v) )
                    return v < other.v;
                return v > 0;
            }
        }
        return a*other.b < other.a*b;
    }
};

vector<moj> p[2];

int nr[1000010];

const int baza = 1<<17;
int drz[baza*2];

void dodaj( int gdzie ) {
    gdzie+=baza;
    while( gdzie ) {
        drz[gdzie]++;
        gdzie/=2;
    }
}

int czytaj( int pyt_pocz, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_pocz <= pocz ) { return drz[gdzie]; }
    if( pyt_pocz >= kon ) { return 0; }
    int sr = (pocz+kon)/2;
    return  czytaj( pyt_pocz, pocz, sr, gdzie*2 )+
            czytaj( pyt_pocz, sr, kon, gdzie*2+1 );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, w;
    cin >> n >> w;
    for( int s, v, i=1; i<=n; i++ ) {
        cin >> s >> v;
        p[0].push_back( {s, w-v, i, v, false} );
        p[1].push_back( {s, -w-v, i, v, true} );
    }
    for( auto & i : p[0] ) {
        i.a = abs( i.a );
        i.b = abs( i.b );
    }
    for( auto & i : p[1] ) {
        i.a = abs( i.a );
        i.b = abs( i.b );
    }
    sort( p[0].begin(), p[0].end() );
    sort( p[1].begin(), p[1].end() );
    int li=0;
    for( auto i : p[0] ) {
        nr[i.id] = ++li;
        //cout << i.id << " ";
    }

    int res=0;
    for( auto i : p[1] ) {
        res += czytaj( nr[i.id] );
        dodaj( nr[i.id] );
        //cout << nr[i.id] << " ";
    }
    cout << res;

    return 0;
}
/*

3 1
3 -4
4 -5
5 -6

*/