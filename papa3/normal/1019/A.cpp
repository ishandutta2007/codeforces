#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007ll
//#define x first
//#define y second
//#define ilo( a, b, c ) ( ((b).x-(a).x)*((c).y-(a).y)-((c).x-(a).x)*((b).y-(a).y) )

vector<pair<int, int> > v[10000];
vector<pair<int, int> > tab;
bool used[10000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    for( int a, b, i=1; i<=n; i++ ) {
        cin >> a >> b;
        v[a].push_back( {b, i} );
        if( a!=1 )
            tab.push_back( {b, i} );
    }
    sort( tab.begin(), tab.end() );
    for( int i=0; i<=m; i++ ) sort( v[i].begin(), v[i].end() );

    int res=INF;
    int ile=0;
    for( int i=0; i<n; i++ ) {
        ile = v[1].size();
        int pom=0;
        for( int i=0; i<=n; i++ ) {
            used[i] = 0;
        }
        for( int j=2; j<=m; j++ ) {
            for( int k=0; k+i<v[j].size(); k++ ) {
                pom += v[j][k].first;
                used[v[j][k].second] = 1;
                ile++;
                if( ile>i+1 ) break;
            }
            if( ile>i+1 ) break;
        }
        if( ile>i+1 ) continue;
        int gdzie=0;
        while( ile < i+1 && gdzie < tab.size() ) {
            while( gdzie < tab.size() && used[tab[gdzie].second] ) gdzie++;
            if( gdzie == tab.size() ) break;
            pom += tab[gdzie].first;
            gdzie++;
            ile++;
        }
        if( ile == i+1 )
        res = min( res, pom );
    }
    cout << res;
    return 0;
}
/*

*/