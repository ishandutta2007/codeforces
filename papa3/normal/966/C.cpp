#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<int> t[100];
list<int> res;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        for( int j=60; j>=0; j-- ) {
            if( (1ll<<j) & a ) {
                t[j].push_back( a );
                break;
            }
        }
    }

    auto it = res.end();
    for( int j=60; j>=0; j-- ) {
        int x=0;
        it = res.begin();
        for( int i : t[j] ) {
            while( (x^i) < x && it != res.end() ) {
                x ^= *it;
                it++;
            }
            if( (x^i) < x ) {
                cout << "No";
                return 0;
            } else {
                it = res.insert( it, i );
                it++;
                x ^= i;
            }
        }
    }
    cout << "Yes\n";
    for( int i : res ) {
        //x = x^i;
        cout << i << " ";
    }

    return 0;
}
/*

*/