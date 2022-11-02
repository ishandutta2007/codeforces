#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<int> l, e;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    for( int a, i=1; i<=cl; i++ ) {
        cin >> a;
        l.push_back( a );
    }
    for( int a, i=1; i<=ce; i++ ) {
        cin >> a;
        e.push_back( a );
    }
    l.push_back( -INF );
    l.push_back( INF );
    e.push_back( -INF );
    e.push_back( INF );
    sort( l.begin(), l.end() );
    sort( e.begin(), e.end() );

    int q;
    int res;
    cin >> q;
    for( int a, b, c, d, i=1; i<=q; i++ ) {
        cin >> b >> a >> d >> c;
        res = INF;
        if( a>c ) swap( a, c );
        if( b>d ) swap( b, d );
        if( b==d ) {
            cout << abs( c-a ) << "\n";
            continue;
        }
        auto it = lower_bound( e.begin(), e.end(), a );
        res = min( res, abs(a-*it)+abs(c-*it)+(d-b-1)/v+1 );
        it--;
        res = min( res, abs(a-*it)+abs(c-*it)+(d-b-1)/v+1 );

        it = lower_bound( l.begin(), l.end(), a );
        res = min( res, abs(a-*it)+abs(c-*it)+d-b );
        it--;
        res = min( res, abs(a-*it)+abs(c-*it)+d-b );
        cout << res << "\n";
    }

    return 0;
}
/*

*/