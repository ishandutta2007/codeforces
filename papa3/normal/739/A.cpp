#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, m, mi=numeric_limits<int>::max();
    cin >> n >> m;
    for( int a, b, i=0; i<m; i++ ) {
        cin >> a >> b;
        mi = min( mi, b-a+1 );
    }
    cout << mi << "\n";
    for( int i=0, j=0; i<n; i++, j++ ) {
        if( j == mi ) {
            j=0;
        }
        cout << j << " ";
    }

    return 0;
}