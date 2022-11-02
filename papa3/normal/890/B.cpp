#include<bits/stdc++.h>

using namespace std;

#define int long long

int tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        tab[a] = i;
    }
    int res = numeric_limits<int>::max(), odp;
    for( int i=0; i<=200000; i++ ) {
        if( tab[i] < res && tab[i] != 0 ) {
            res = tab[i];
            odp = i;
        }
    }
    cout << odp;

    return 0;
}