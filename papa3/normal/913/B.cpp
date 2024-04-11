#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
//#define x first
//#define y second
//#define ilo( a, b, c ) ( (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) )
#define kwadrat( a ) ( (a)*(a) )
#define odleglosc( a, b ) ( kwadrat( a.x-b.x )+kwadrat( a.y-b.y ) )

vector<int> drogi[1000010];
bool nie;

bool dfs( int gdzie=1 ) {
    if( drogi[gdzie].size() == 0 ) return 1;

    int x=0;
    for( int i : drogi[gdzie] ) {
        x += dfs( i );
    }
    if( x<3 ) nie = 1;

    return 0;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, b, i=2; i<=n; i++ ) {
        cin >> a;
        drogi[a].push_back( i );
    }
    dfs();
    if( nie ) cout << "No";
    else cout << "Yes";

    return 0;
}