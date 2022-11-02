#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define MAX_N 300010

int tab[1000010];
int v[1000010];
int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        v[i] = tab[i];
    }
    for( int i=n; i>1; i-- ) {
        tab[i-1] = max( tab[i-1], tab[i]-1 );
    }
    int res=0;
    for( int i=2; i<=n; i++ ) {
        tab[i] = max( tab[i], tab[i-1] );
        res += tab[i]-v[i];
        //cout << res << " ";
    }
    cout << res;

    return 0;
}