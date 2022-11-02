#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int tab[10010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
    }
    for( int i=n; i>0; i-- ) {
        tab[i] -= tab[i-1];
    }

    vector<int> res;
    for( int i=1; i<=n; i++ ) {
        bool czy=true;
        for( int j=1; j<=n; j+=i ) {
            for( int k=0; k<i && k+j<=n; k++ ) {
                if( tab[1+k] != tab[j+k] ) {
                    czy = false;
                    break;
                }
            }
        }
        if( czy ) res.push_back( i );
    }
    cout << res.size() << endl;
    for( int i : res ) cout << i << " ";

    return 0;
}/*

*/