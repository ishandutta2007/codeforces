#include<bits/stdc++.h>

using namespace std;

set<int> l;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int n;
    cin >> n;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        l.insert( a );
    }
    if( l.size() > 3 ) {
        cout << "NO";
    } else if ( l.size() < 3 ) {
        cout << "YES";
    } else {
        int a, b, c;
        auto it = l.begin();
        a = *it;
        it++;
        b = *it;
        it++;
        c = *it;
        if( a+c == b+b ) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
}