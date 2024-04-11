#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define MAX_N 300010

bitset<100> tab[100];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int i=0; i<n; i++ ) {
        for( int j=0; j<m; j++ ) {
            char c;
            cin >> c;
            if( c == '#' ) tab[i][j] = 1;
        }
    }

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ ) {
            if( (tab[i] & tab[j]).any() ) {
                if( tab[i] != tab[j] ) {
                    cout << "No";
                    //cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    cout << "Yes";

    return 0;
}