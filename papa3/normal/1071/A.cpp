#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<int> x, y;
bool used[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int a, b;
    bool czy=false;
    cin >> a >> b;
    if( a>b ) {
        czy = true;
        swap( a, b );
    }

    for( int i=1; ; i++ ) {
        if( i > a ) {
            break;
        }
        x.push_back( i );
        a -= i;
        used[i] = true;
    }
    while( a ) {
        for( int i=(int)x.size()-1; i>=0; i-- ) {
            if( a==0 ) break;
            used[x[i]] = false;
            x[i]++;
            used[x[i]] = true;
            a--;
        }
    }
    for( int i=1; ; i++ ) {
        if( used[i] ) continue;
        if( i > b ) {
            break;
        }
        y.push_back( i );
        b -= i;
    }
    if( czy ) swap( x, y );
    cout << x.size() << "\n";
    for( int i : x ) cout << i << " ";
    cout << "\n";
    swap( x, y );
    cout << x.size() << "\n";
    for( int i : x ) cout << i << " ";
    cout << "\n";

    return 0;
}/*

*/