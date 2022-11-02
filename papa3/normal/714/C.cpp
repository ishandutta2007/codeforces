#include<bits/stdc++.h>

using namespace std;

multiset<pair<long long, long long> > l;
int wy[1000010];

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int n;
    long long a, x;
    char q;
    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> q >> a;
        if( q == '+' ) {
            x=1;
            while( a ) {
                x = x*2 + ((a%10)%2);
                a/=10;
            }
            while( x ) {
                wy[x]++;
                if( x%2 == 1 ) {
                    break;
                } else {
                    x/=2;
                }
            }
        } else if( q == '-' ) {
            x=1;
            while( a ) {
                x = x*2 + ((a%10)%2);
                a/=10;
            }
            while( x ) {
                wy[x]--;
                if( x%2 == 1 ) {
                    break;
                } else {
                    x/=2;
                }
            }
        } else {
            x=1;
            while( a ) {
                x = x*2 + ((a%10)%2);
                a/=10;
            }
            cout << wy[x] << "\n";
        }
    }

    /*long long a, b, c, x;
    long long rep;
    char q;
    for( int i=0; i<n; i++ ) {
        cin >> q >> a;
        if( q == '+' ) {
            b=0;
            c = a;
            x=1;
            while( c ) {
                b += ( (c%10)%2 )*x;
                x*=10;
                c/=10;
            }
            l.insert( {b, a} );
        } else if( q == '-' ) {
            b=0;
            c = a;
            x=1;
            while( c ) {
                b += ( (c%10)%2 )*x;
                x*=10;
                c/=10;
            }
            auto it = l.find( {b, a} );
            l.erase( it );
        } else {
            b=0;
            c = a;
            x=1;
            while( c ) {
                b += ( (c%10)%2 )*x;
                x*=10;
                c/=10;
            }
            auto it1 = l.upper_bound( {b-1, numeric_limits<long long>::max()} );
            auto it2 = l.upper_bound( {b, numeric_limits<long long>::max()} );
            cout << it2-it1 << "\n";
        }
    }*/
    return 0;
}