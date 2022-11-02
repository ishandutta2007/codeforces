#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int res[1000010];
int   a[1000010];
int   x[1000010];
int suma;

vector<int> v;
vector<int> pref;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int b, c, i=1; i<=n; i++ ) {
        cin >> b >> c;
        a[i] = b; suma += a[i];
        x[i] = c-b;
        v.push_back( x[i] );
    }
    sort( v.begin(), v.end() );
    for( int i : v ) {
        pref.push_back( i );
    }
    for( int i=1; i<pref.size(); i++ ) {
        pref[i] += pref[i-1];
    }
    for( int i=1; i<=n; i++ ) {
        res[i] = suma-a[i]+a[i]*(n-1);
        int it = lower_bound( v.begin(), v.end(), x[i] )-v.begin();
        if( it>0 ) res[i] += pref[it-1];
        res[i] += x[i]*(n-(it+1));
    }

    for( int b, c, i=1; i<=m; i++ ) {
        cin >> b >> c;
        res[b] -= a[b]+a[c]+min( x[b], x[c] );
        res[c] -= a[b]+a[c]+min( x[b], x[c] );
    }
    for( int i=1; i<=n; i++ ) {
        cout << res[i] << " ";
    }

    return 0;
}/*

*/