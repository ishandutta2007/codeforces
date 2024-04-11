#include<bits/stdc++.h>

using namespace std;

int wy[1010], n;
vector<int> nr;
bool czy[1010];

void zeruj() {
    for( int i=1; i<=n; i++ ) {
        czy[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    cin >> n;
    for( int i=1; i<=n; i++ ) {
        wy[i] = numeric_limits<int>::max();
    }
    int pod=1;
    int x;
    while( pod < n ) {
        zeruj();
        nr.clear();
        for( int i=1; i<=n; i+=pod+pod ) {
            for( int j=i; j<i+pod && j<=n; j++ ) {
                nr.push_back( j );
                czy[j] = 1;
            }
        }
        cout << nr.size() << "\n";
        for( int i : nr ) {
            cout << i << " ";
        }
        cout << endl;
        for( int i=1; i<=n; i++ ) {
            cin >> x;
            if( czy[i] == 0 ) {
                wy[i] = min( wy[i], x );
            }
        }
        zeruj();
        nr.clear();
        for( int i=1+pod; i<=n; i+=pod+pod ) {
            for( int j=i; j<i+pod && j<=n; j++ ) {
                nr.push_back( j );
                czy[j] = 1;
            }
        }
        cout << nr.size() << "\n";
        for( int i : nr ) {
            cout << i << " ";
        }
        cout << endl;
        for( int i=1; i<=n; i++ ) {
            cin >> x;
            if( czy[i] == 0 ) {
                wy[i] = min( wy[i], x );
            }
        }
        pod *= 2;
    }
    cout << "-1\n";
    for( int i=1; i<=n; i++ ) {
        cout << wy[i] << " ";
    }
    cout << endl;

    return 0;
}