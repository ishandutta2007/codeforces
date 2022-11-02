#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int tab[10000];
int pref[10000];
vector<pair<int, int> > prz;
int n, s, m, k;

int dp[1510][1510];

bool algo( int wy ) {
    auto it = prz.begin();
    set<pair<int, int> > s;
    for( int i=1; i<=n; i++ ) {
        pref[i] = pref[i-1];
        if( tab[i] <= wy ) pref[i]++;
        while( s.size() && s.begin()->second < i ) {
            s.erase( s.begin() );
        }
        while( it != prz.end() && it->first <= i ) {
            s.insert( *it );
            it++;
        }
        int pocz = i+1;
        if( s.size() ) pocz = s.begin()->first;
        for( int j=0; j<=m; j++ ) {
            dp[i][j] = dp[i-1][j];
            if( j )
                dp[i][j] = max( dp[i][j], dp[pocz-1][j-1]+pref[i]-pref[pocz-1] );
            if( dp[i][j] >= k ) return true;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> s >> m >> k;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
    }
    for( int a, b, i=1; i<=s; i++ ) {
        cin >> a >> b;
        prz.push_back( {a, b} );
    }
    sort( prz.begin(), prz.end() );

    int pocz=0, kon = 1000000001, sr;
    while( kon-pocz > 1 ) {
        sr = (pocz+kon)/2;
        if( algo( sr ) ) kon = sr;
        else pocz = sr;
    }
    if( algo( kon ) )
        cout << kon;
    else
        cout << -1;

    return 0;
}/*

*/