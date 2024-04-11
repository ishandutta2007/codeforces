#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

bool a[1000000], b[1000000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, s;
    cin >> n >> s;
    s--;
    bool x;
    bool czy=false;
    for( int i=0; i<n; i++ ) {
        cin >> x;
        a[i] = x;
    }
    for( int i=0; i<n; i++ ) {
        cin >> x;
        b[i] = x;
        if( i>=s ) {
            if( x && a[i] ) czy = true;
        }
    }
    if( a[0] == 0 ) {
        if( s==0 ) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if( a[s] ) {
        cout << "YES";
        return 0;
    } else if( b[s] && czy ) {
        cout << "YES";
        return 0;
    }
    cout << "NO";


    return 0;
}/*

*/