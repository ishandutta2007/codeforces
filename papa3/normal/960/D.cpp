#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000

int v[100], n[100];

void moduluj( int & co, int m ) {
    //cout << co << " " << m << "    ";
    if( co>=0 ) co = co%m;
    else co = m-abs(co)%m;
    //cout << co << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int q;
    int a, b, c;
    int gdzie;
    cin >> q;
    while( q-- ) {
        cin >> a >> b;
        if( a==3 ) {
            c = b;
            gdzie = 0;
            int x=1;
            while( c/=2 ) {
                gdzie++;
                x*=2;
            }
            //cout << gdzie << " " << x << endl;
            cout << b << " ";
            b = (b-v[gdzie]+x+n[gdzie])%x+x;
            b/=2;
            x/=2;
            gdzie--;
            while( b ) {
                cout << (b+v[gdzie])%x+x << " ";
                b = (b+n[gdzie])%x+x;
                b/=2;
                x/=2;
                gdzie--;
            }
            cout << "\n";
        } else {
            cin >> c;
            gdzie = 0;
            int x=1;
            while( b/=2 ) {
                gdzie++;
                x*=2;
            }
            if( a==1 ) {
                v[gdzie] -= c;
                moduluj( v[gdzie], x );
            } else {
                n[gdzie] += c;
                moduluj( n[gdzie], x );
            }
        }
    }

    return 0;
}
/*
2
2 4 12
3 14
*/