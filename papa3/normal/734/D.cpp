#include<bits/stdc++.h>

using namespace std;

pair<char, long long> t[10];

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    t[1].second = t[2].second = t[3].second = t[8].second = numeric_limits<long long>::max();
    t[4].second = t[5].second = t[6].second = t[7].second = -numeric_limits<long long>::max();
    long long n, x, y;
    cin >> n >> x >> y;
    char c;
    for( long long a, b, i=0; i<n; i++ ) {
        cin >> c >> a >> b;
        if( a == x ) {
            if( b > y ) {
                if( t[1].second > b ) {
                    t[1] = {c, b};
                }
            } else {
                if( t[5].second < b ) {
                    t[5] = {c, b};
                }
            }
        } else if( b == y ) {
            if( a > x ) {
                if( t[3].second > a ) {
                    t[3] = {c, a};
                }
            } else {
                if( t[7].second < a ) {
                    t[7] = {c, a};
                }
            }
        } if( a-x == b-y ) {
            if( b > y ) {
                if( t[8].second > b ) {
                    t[8] = {c, b};
                }
            } else {
                if( t[4].second < b ) {
                    t[4] = {c, b};
                }
            }
        } else if( a-x == y-b ) {
            if( b > y ) {
                if( t[2].second > b ) {
                    t[2] = {c, b};
                }
            } else {
                if( t[6].second < b ) {
                    t[6] = {c, b};
                }
            }
        }
    }
    bool czy = 0;
    for( int i =1; i<=8; i++) {
        if( i%2 ) {
            if( t[i].first == 'R' || t[i].first == 'Q' )
                czy = 1;
        } else {
            if( t[i].first == 'B' || t[i].first == 'Q' )
                czy = 1;
        }

    }
    if( czy ) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}