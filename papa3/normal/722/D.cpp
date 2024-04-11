#include<bits/stdc++.h>

using namespace std;

set<int> s;
map<int, bool> m;

bool zwal( int co ) {
    co/=2;
    if( m[co] == 1 ) {
        return 0;
    }
    auto it2 = s.find( co );
    if( it2 != s.end() ) {
        if( zwal( co ) ) {
            return 1;
        } else {
            m[co] = 1;
            return 0;
        }
    } else {
        s.insert( co );
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        s.insert( a );
    }
    m[0] = 1;
    int x;
    set<int>::iterator it;
    while( 69 ) {
        it = s.end();
        it--;
        x = *it;
        s.erase( it );
        if( !zwal( x ) ) {
            s.insert( x );
            break;
        }
    }
    for( int i : s ) {
        cout << i << " ";
    }
    return 0;
}
/*
4
1 2 3 5
*/