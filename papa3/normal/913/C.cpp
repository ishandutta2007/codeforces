#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
//#define x first
//#define y second
//#define ilo( a, b, c ) ( (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y) )
#define kwadrat( a ) ( (a)*(a) )
#define odleglosc( a, b ) ( kwadrat( a.x-b.x )+kwadrat( a.y-b.y ) )

int tab[100];
int tab2[100];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, l;
    cin >> n >> l;
    for( int a, i=0; i<n; i++ ) {
        cin >> tab[i];
        tab2[i] = tab[i];
    }

    for( int i=1; i<=30; i++ ) {
        if( tab[i] == 0 ) tab[i] = tab[i-1]*2;
        tab[i] = min( tab[i], tab[i-1]*2 );
    }

    tab2[31] = numeric_limits<int>::max();
    for( int i=30; i>=0; i-- ) {
        if( tab2[i] == 0 ) tab2[i] = numeric_limits<int>::max();
        tab2[i] = min( tab2[i], tab2[i+1] );
    }

    int res=0;
    int a=1, b=0;
    while( a < l ) {a*=2; b++;}
    int res2 = min( tab[b], tab2[b] );
    while( l ) {
        int x=1;
        int y=0;
        while( x*2 <= l ) {x*=2; y++;}
        res2 = min( res2, res+min( tab[y+1], tab2[y+1] ) );
        res += min( tab[y], tab2[y] );
        l-=x;
    }
    cout << min( res, res2 );


    return 0;
}