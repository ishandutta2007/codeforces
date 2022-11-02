#include<bits/stdc++.h>

using namespace std;

int main() {
    //ios_base::sync_with_stdio( 0 );
    //cin.tie( NULL );

    int n;
    cin >> n;
    if( n == 1 ) {
        cout << "YES\n2 1\n1 2";
        return 0;
    }
    if( n%2 ) {
        cout << "YES\n";
        cout << n+n+4 << " " << 6*n-3+(n-1)*(n-2)-n+1 << "\n";
        cout << "1 2\n";
        for( int i=3; i<n+2; i++ ) {
            cout << i << " 1\n";
            cout << i << " " << n+2 << "\n";
            cout << i << " " << n+3 << "\n";
            if( i%2 == 0 && i<n+1 ) {
                cout << i << " " << i+1 << "\n";
            }
            for( int j=i+2; j<n+2; j++ ) {
                cout << i << " " << j << "\n";
            }
        }
        cout << n+2 << " " << n+3 << "\n";
        for( int i=n+4; i<n+n+3; i++ ) {
            cout << i << " 2\n";
            cout << i << " " << n+n+3 << "\n";
            cout << i << " " << n+n+4 << "\n";
            if( i%2 == (n+n+4)%2 && i<n+n+2 ) {
                cout << i << " " << i+1 << "\n";
            }
            for( int j=i+2; j<n+n+3; j++ ) {
                cout << i << " " << j << "\n";
            }
        }
        cout << n+n+4 << " " << n+n+3 << "\n";
    } else {
        cout << "NO";
    }

    return 0;
}/*
5
1 7
2 9
3 5
4 8
6 10

3
1 3
4 6
2 5
*/