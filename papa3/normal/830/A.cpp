#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> v;
vector<int> v2;
int p;

bool algo( int x ) {
    int gdzie=0;
    for( int i : v ) {
        while( gdzie < v2.size() && abs( i-v2[gdzie] )+abs( p-v2[gdzie] ) > x ) {
            gdzie++;
        }
        if( gdzie == v2.size() ) return false;
        gdzie++;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, k;
    cin >> n >> k >> p;

    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    for( int a, i=1; i<=k; i++ ) {
        cin >> a;
        v2.push_back( a );
    }
    sort( v.begin(), v.end() );
    sort( v2.begin(), v2.end() );

    //cout << algo( 7 );

    int pocz=-1, kon=1000000000000000ll;
    int sr;
    while( kon-pocz > 1 ) {
        sr = (pocz+kon)/2;
        if( algo( sr ) ) {
            kon = sr;
        } else {
            pocz = sr;
        }
    }
    cout << kon;

    return 0;
}