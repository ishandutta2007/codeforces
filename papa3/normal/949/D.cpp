#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

struct moj {
    int gdzie, suma, wy;
};

moj l[1000010], r[1000010]; // gdzie, wy

int tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n, d, b;
    cin >> n >> d >> b;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
    }

    l[0] = {1, 0, 0};
    for( int x, i=1; i<=n; i++ ) {
        l[i] = l[i-1];
        x = i/(d+1);
        if( x*(d+1) < i ) x++;
        l[i].gdzie = max( l[i].gdzie, x );
        l[i].suma += tab[i];
        while( l[i].suma >= b && l[i].gdzie <= n/2 ) {
            l[i].gdzie++;
            l[i].suma-=b;
            l[i].wy++;
        }
        //cout << l[i].gdzie << " " << l[i].suma << " " << l[i].wy << "\n";
    }
    reverse( tab+1, tab+n+1 );
    r[0] = {1, 0, 0};
    for( int x, i=1; i<=n; i++ ) {
        r[i] = r[i-1];
        x = i/(d+1);
        if( x*(d+1) < i ) x++;
        r[i].gdzie = max( r[i].gdzie, x );
        r[i].suma += tab[i];
        while( r[i].suma >= b && r[i].gdzie <= n/2 ) {
            r[i].gdzie++;
            r[i].suma-=b;
            r[i].wy++;
        }
        //cout << r[i].gdzie << " " << r[i].suma << " " << r[i].wy << "\n";
    }
    reverse( tab+1, tab+n+1 );
    r[n+1] = {1, 0, 0};
    reverse( r+1, r+n+1 );
    moj a, c;
    int res = 0;
    for( int x, i=1; i<=n; i++ ) {
        a = l[i-1], c = r[i+1];
        x = i/(d+1);
        if( x*(d+1) < i ) x++;
        a.gdzie = max( a.gdzie, x );
        x = (n-i+1)/(d+1);
        if( x*(d+1) < n-i+1 ) x++;
        c.gdzie = max( c.gdzie, x );
        if( a.wy > c.wy ) swap( a, c );

        tab[i] += a.suma;
        int y = min( tab[i]/b, c.wy-a.wy+1 );
        y = min( y, n/2-a.gdzie+1 );
        a.wy += y;
        a.gdzie += y;
        a.suma = 0;
        tab[i] -= y*b;

        if( tab[i]+c.suma >= b && c.gdzie <= n/2 ) {
            c.gdzie++;
            c.wy++;
            tab[i] = tab[i]+c.suma-b;
            c.suma = 0;
        }

        res = max( res, min( a.wy, c.wy )+min( tab[i]/(2*b), n/2-max( a.gdzie, c.gdzie )+1 ) );
        //cout << res << "\n";
    }
    cout << n/2-res;

    return 0;
}
/*
5 2 2
10 0 0 0 0


*/