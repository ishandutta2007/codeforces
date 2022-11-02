#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007ll
//#define x first
//#define y second
//#define ilo( a, b, c ) ( ((b).x-(a).x)*((c).y-(a).y)-((c).x-(a).x)*((b).y-(a).y) )

int n, m;
vector<int> drogi[1000010];
vector<int> trans[1000010];
bool visited[1000010];
bool czy[1000010];
int res;
int gdzie = 1;
void foo() {
    while( gdzie <= n && visited[gdzie] ) gdzie++;
    int i = gdzie;
    if( gdzie>n ) return;
    visited[i] = true;
    for( int j : drogi[i] ) {
        visited[j] = true;
    }
    gdzie++;
    foo();
    czy[i] = 1;
    for( int j : trans[i] ) {
        if( czy[j] ) czy[i] = 0;
    }
    res += czy[i];
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    cin >> n >> m;
    for( int a, b, i=1; i<=m; i++ ) {
        cin >> a >> b;
        drogi[a].push_back( b );
        trans[b].push_back( a );
    }
    foo();
    cout << res << "\n";
    for( int i=1; i<=n; i++  ) {
        if( czy[i] ) cout << i << " ";
    }

    return 0;
}
/*

*/