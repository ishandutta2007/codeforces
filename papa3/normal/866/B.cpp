#include<bits/stdc++.h>

using namespace std;

#define int long long

priority_queue<pair<int, int> > kol[2];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int res=0;
    int n, s;
    cin >> n >> s;
    int ile=0;
    for( int a, b, c, i=1; i<=n; i++ ) {
        cin >> a >> b >> c;
        res += a*min( b, c );
        ile += a;
        if( b>c )
            kol[0].push( {b-c, a} );
        else
            kol[1].push( {c-b, a} );
    }
    pair<int, int> p{0, 0};
    while( !kol[0].empty() ) {
        if( p.second + kol[0].top().second >= s ) {
            res += p.first+kol[0].top().first*( s-p.second );
            pair<int, int> x = kol[0].top();
            x.second = x.second+p.second-s;
            res += x.first*( (x.second/s)*s );
            p = {x.first*( x.second%s ), x.second%s};
        } else {
            p.first += kol[0].top().first*kol[0].top().second;
            p.second += kol[0].top().second;
        }
        kol[0].pop();
    }
    pair<int, int> p2 = p;
    p = {0, 0};
    swap( kol[0], kol[1] );
    while( !kol[0].empty() ) {
        if( p.second + kol[0].top().second >= s ) {
            res += p.first+kol[0].top().first*( s-p.second );
            pair<int, int> x = kol[0].top();
            x.second = x.second+p.second-s;
            res += x.first*( (x.second/s)*s );
            p = {x.first*( x.second%s ), x.second%s};
        } else {
            p.first += kol[0].top().first*kol[0].top().second;
            p.second += kol[0].top().second;
        }
        kol[0].pop();
    }
    if( p.second+p2.second > s ) {
        res += p.first+p2.first;
    }
    else {
        res += max( p.first, p2.first );
    }
    cout << res;

    return 0;
}