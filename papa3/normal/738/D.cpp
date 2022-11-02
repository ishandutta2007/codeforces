#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    char x;
    int licz=0;
    for( int i=1; i<=n; i++ ) {
        cin >> x;
        if( x == '1' ) {
            licz = 0;
        } else {
            licz++;
            if( licz == b ) {
                v.push_back( i );
                licz=0;
            }
        }
    }
    cout << v.size()-a+1 << "\n";
    for( int i=0; i<v.size()-a+1; i++ ) {
        cout << v[i] << " ";
    }
    return 0;
}