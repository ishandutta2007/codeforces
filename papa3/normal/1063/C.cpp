#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000ll

string t[100];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    cout << "0 0" << endl;
    cin >> t[0];
    int pocz=0, kon=2*INF-10, sr;
    for( int i=1; i<n; i++ ) {
        sr = (pocz+kon)/2;
        if( sr<=INF ) {
            cout << INF << " " << sr << endl;
        } else {
            cout << 2*INF-sr << " " << INF << endl;
        }
        cin >> t[i];
        if( t[i] == t[0] ) pocz = sr;
        else kon = sr;
    }
    sr = (pocz+kon)/2;
    cout << "0 1 ";
    if( sr<=INF ) {
        cout << INF << " " << sr << endl;
    } else {
        cout << 2*INF-sr << " " << INF << endl;
    }
    return 0;
}/*

*/