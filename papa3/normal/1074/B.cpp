#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

struct algo {
    vector<vector<int> > drogi;
    vector<bool> wyb;
    set<int> s;
    algo() {
        int n;
        cin >> n;
        drogi.resize( n+10 );
        wyb.resize( n+10 );
        for( int a, b, i=1; i<n; i++ ) {
            cin >> a >> b;
            drogi[a].push_back( b );
            drogi[b].push_back( a );
        }
        int k;
        cin >> k;
        for( int a, i=1; i<=k; i++ ) {
            cin >> a;
            wyb[a] = true;
        }
        cin >> k;
        for( int a, i=1; i<=k; i++ ) {
            cin >> a;
            s.insert( a );
        }
        int gdzie;
        cout << "B " << *s.begin() << endl;
        cin >> gdzie;
        int a = dfs( gdzie );
        cout << "A " << a << endl;
        cin >> gdzie;
        if( s.find( gdzie ) != s.end() ) cout << "C " << a << endl;
        else cout << "C -1" << endl;
    }

    int dfs( int gdzie, int skad=-1 ) {
        if( wyb[gdzie] ) return gdzie;
        for( int i : drogi[gdzie] ) {
            if( i == skad ) continue;
            int x = dfs( i, gdzie );
            if( x!=-1 ) return x;
        }
        return -1;
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int t;
    cin >> t;
    while( t-- ) algo p;
    return 0;
}/*

*/