#include<bits/stdc++.h>

using namespace std;

//#define int long long

vector<int> v;
int tab[200];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        v.push_back( tab[i] );
    }
    sort( v.begin(), v.end() );
    v.push_back( v.front() );
    for( int i=1; i<=n; i++ ) {
        for( int j=0; ; j++ ) {
            if( v[j] == tab[i] ) {
                cout << v[j+1] << " ";
                break;
            }
        }
    }

    return 0;
}