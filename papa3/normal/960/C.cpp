#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

vector<int> wy;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int x, d;
    cin >> x >> d;
    for( int i=1; ; i+=d+1 ) {
        int a=2;
        int n=1;
        while( a*2-1 <= x ) {
            a*=2;
            n++;
        }
        x -= a-1;
        for( int j=0; j<n; j++ ) {
            wy.push_back( i );
        }
        if( x==0 ) break;
    }
    cout << wy.size() << "\n";
    for( int i : wy ) {
        cout << i << " ";
    }

    return 0;
}
/*

*/