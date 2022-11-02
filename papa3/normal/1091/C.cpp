#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

set<int> res;
int n;

int foo( int x ) {
    return (1+(1+n-x))*(n/x)/2;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n;
    int x = sqrt( n )+10;
    for( int i=1; i<=x; i++ ) {
        if( n%i == 0 ) {
            res.insert( foo( i ) );
            res.insert( foo( n/i ) );
        }
    }
    for( int i : res ) {
        cout << i << " ";
    }

    return 0;
}/*

*/