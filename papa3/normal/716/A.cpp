#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, c;
    vector<int> v;
    cin >> n >> c;
    for( int a, i=0; i<n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    int wy=1;
    for( int i=v.size()-1; i>0; i-- ) {
        if( v[i] - v[i-1] <= c ) {
            wy++;
        } else {
            break;
        }
    }
    cout << wy;
    return 0;
}