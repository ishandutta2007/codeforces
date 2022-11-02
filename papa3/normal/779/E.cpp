#include<bits/stdc++.h>

using namespace std;

#define int long long

map<string, int> m;
string co[10010], mi, ma;
string op[10010], co2[10010];
bool jak[10010];
int n, k;

int res( int nr ) {
    int sum=0;
    for( int i=1; i<=n; i++ ) {
        if( op[i].size() == 0 ) {
            jak[i] = co[i][nr]-'0';
        } else if( op[i] == "XOR" ) {
            jak[i] = jak[ m[co[i]] ] ^ jak[ m[co2[i]] ];
        } else if( op[i] == "OR" ) {
            jak[i] = jak[ m[co[i]] ] | jak[ m[co2[i]] ];
        } else {
            jak[i] = jak[ m[co[i]] ] & jak[ m[co2[i]] ];
        }
        sum += jak[i];
    }
    return sum;
}

int32_t main() {///zera wiodace!!!
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );


    cin >> n >> k;
    string s;
    m[ "?" ] = 0;
    for( int i=1; i<=n; i++ ) {
        cin >> s;
        m[s] = i;
        cin >> s;
        cin >> co[i];
        if( co[i][0] != '0' && co[i][0] != '1' ) {
            cin >> op[i] >> co2[i];
        }
    }
    for( int x, y, i=0; i<k; i++ ) {
        jak[0] = 0; x = res( i );
        jak[0] = 1; y = res( i );
        if( x > y ) {
            ma.push_back( '0' );
            mi.push_back( '1' );
        } else if( x < y ) {
            ma.push_back( '1' );
            mi.push_back( '0' );
        } else {
            ma.push_back( '0' );
            mi.push_back( '0' );
        }
    }
    cout << mi << "\n" << ma;

    return 0;
}