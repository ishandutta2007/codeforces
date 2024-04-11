#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
const long long mod = 1000000007ll;
const long long INF = 1000000000000000000ll;

vector<char> t {'A', 'C', 'G', 'T'};
vector<vector<char> > res;
vector<vector<char> > pom;
int d;
int n, m;
vector<vector<char> > v ;
int li;

void algo() {
    do {
        li++;
        int pom_d=0;
        int pom_d2=0;
        for( int i=0; i<n; i++ ) {
            int p=0, np=0;
            char a=t[0], b=t[1];
            if( i%2 ) {
                a=t[2], b=t[3];
            }
            for( int j=0; j<m; j++ ) {
                if( a == v[i][j] ) {
                    if( j%2 ) np++;
                    else p++;
                } else if( b == v[i][j] ) {
                    if( j%2 ) p++;
                    else np++;
                }
            }
            if( np>p ) swap( a, b );
            pom_d2 += m-max( np, p );
            for( int j=0; j<m; j++ ) {
                if( j%2 ) pom[i][j] = b;
                else pom[i][j] = a;
                if( pom[i][j] != v[i][j] ) pom_d++;
            }
        }
        if( d > pom_d ) {
            d = pom_d;
            res = pom;
        }
    } while( next_permutation( t.begin(), t.end() ) );
}

void algo2() {
    do {
        int pom_d=0;
        int pom_d2=0;
        for( int j=0; j<m; j++ ) {
            int p=0, np=0;
            char a=t[0], b=t[1];
            if( j%2 ) {
                a=t[2], b=t[3];
            }
            for( int i=0; i<n; i++ ) {
                if( a == v[i][j] ) {
                    if( i%2 ) np++;
                    else p++;
                } else if( b == v[i][j] ) {
                    if( i%2 ) p++;
                    else np++;
                }
            }
            if( np>p ) swap( a, b );
            pom_d2 += m-max( np, p );
            for( int i=0; i<n; i++ ) {
                if( i%2 ) pom[i][j] = b;
                else pom[i][j] = a;
                if( pom[i][j] != v[i][j] ) pom_d++;
            }
        }
        if( d > pom_d ) {
            d = pom_d;
            res = pom;
        }
    } while( next_permutation( t.begin(), t.end() ) );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    d = INF;
    cin >> n >> m;
    for( int i=1; i<=n; i++ ) {
        v.push_back( {} );
        pom.push_back( {} );
        char c;
        for( int i=1; i<=m; i++ ) {
            cin >> c;
            v.back().push_back( c );
            pom.back().push_back( 'a' );
        }
    }
    algo();
    algo2();

    //cout << li << endl;
    //cout << d << endl;
    for( auto & i : res ) {
        for( char j : i ) {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}/*
5
1 2 3 1
1 -1 2 -1 10


*/