#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define INF 1000000000000000000ll
#define mod 1000000007ll
//#define x first
//#define y second
//#define ilo( a, b, c ) ( ((b).x-(a).x)*((c).y-(a).y)-((c).x-(a).x)*((b).y-(a).y) )

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    if( n%4 != 0 ) {
        cout << "! -1";
        return 0;
    }
    int pocz=1, kon=1+n/2, sr;
    int a, b;
    cout << "? " << pocz << endl;
    cin >> a;
    cout << "? " << pocz+n/2 << endl;
    cin >> b;
    if( a==b ) {
        cout << "! " << pocz;
        return 0;
    }
    bool jak=0;
    if( a>b ) jak=1;
    while( kon-pocz > 1 ) {
        sr = (pocz+kon)/2;
        cout << "? " << sr << endl;
        cin >> a;
        cout << "? " << sr+n/2 << endl;
        cin >> b;
        if( a==b ) {
            cout << "! " << sr;
            return 0;
        }
        if( a>b && jak ) pocz = sr;
        else if( a<b && !jak ) pocz = sr;
        else kon = sr;
    }


    return 0;
}
/*

*/