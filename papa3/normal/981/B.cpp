#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000ll

map<int, int> m;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        m[a] = max( m[a], b );
    }
    cin >> n;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        m[a] = max( m[a], b );
    }
    int res=0;
    for( pair<int, int> i : m ) {
        res += i.second;
    }
    cout << res;

    return 0;
}
/*

*/