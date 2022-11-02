#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
//#define x first
//#define y second
//#define ilo( a, b, c ) ( (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) )
#define kwadrat( a ) ( (a)*(a) )
#define odleglosc( a, b ) ( kwadrat( a.x-b.x )+kwadrat( a.y-b.y ) )



int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, m;
    cin >> n >> m;
    if( n > 30 ) {
        cout << m;
    } else {
        cout << m%(1<<n);
    }
    return 0;
}