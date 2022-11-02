#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

vector<vector<int> > z, j;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    string s;
    cin >> s;
    for( int i=0; i<s.size(); i++ ) {
        if( s[i] == '0' ) {
            if( j.size() ) {
                j.back().push_back( i );
                z.push_back( {} );
                swap( j.back(), z.back() );
                j.pop_back();
            } else {
                z.push_back( {} );
                z.back().push_back( i );
            }
        } else {
            if( z.size() ) {
                z.back().push_back( i );
                j.push_back( {} );
                swap( j.back(), z.back() );
                z.pop_back();
            } else {
                cout << -1;
                return 0;
            }
        }
    }

    if( j.size() ) {
        cout << -1;
        return 0;
    }

    cout << z.size() << "\n";
    for( auto & i : z ) {
        cout << i.size();
        for( int j : i ) {
            cout << " " << j+1;
        }
        cout << "\n";
    }

    return 0;
}