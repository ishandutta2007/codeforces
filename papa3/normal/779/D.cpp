#include<bits/stdc++.h>

using namespace std;

#define int long long

string a, b;
vector<int> v;
int tab[1000010];

bool algo( int kon ) {
    int j=0;
    for( int i=0; i<a.size(); i++ ) {
        if( tab[ i ] > kon && a[i] == b[j] ) {
            j++;
            if( j == b.size() ) {
                return 1;
            }
        }
    }
    return 0;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    cin >> a >> b;
    for( int x, i=1; i<=a.size(); i++ ) {
        cin >> x;
        tab[x-1] = i;
        v.push_back( x-1 );
    }
    int pocz=0, kon=a.size(), sr;
    while( kon-pocz > 1 ) {
        sr = (pocz+kon)/2;
        if( algo( sr ) ) {
            pocz = sr;
        } else {
            kon = sr;
        }
    }
    cout << pocz;
    return 0;
}