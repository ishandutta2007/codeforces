#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

vector<int> seq;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int m, n;
    cin >> m >> n;
    for( int a, i=0; i<n; i++ ) {
        cout << 1 << endl;
        cin >> a;
        if( a==0 ) return 0;
        seq.push_back( a );
    }

    int pocz=1, kon=m+1, sr;
    int a;
    int it=0;
    while( kon-pocz>1 ) {
        sr = (pocz+kon)/2;
        cout << sr << endl;
        cin >> a;
        a *= seq[it%n];
        it++;
        if( a==0 ) return 0;
        if( a==-1 ) kon = sr;
        else pocz = sr+1;
    }
    cout << pocz << endl;
    cin >> a;

    return 0;
}