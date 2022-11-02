#include<bits/stdc++.h>

using namespace std;

const int baza = 1<<20;

bool drz[2*baza];

void zmien( bool na_co, int gdzie ) {
    drz[gdzie] = na_co;
}

int czytaj() {
    int gdzie = 1;
    while( gdzie<baza ) {
        if( drz[gdzie*2] == 0 )
            gdzie*=2;
        else {
            gdzie = gdzie*2+1;
        }
    }
    return gdzie-baza;
}

struct algo {
    vector<int> zmiany;
    vector<int> tab;
    int n;
    algo() {
        cin >> n;
        vector<int> v;
        for( int a, i=1; i<=n; i++ ) {
            cin >> a;
            v.push_back( a );
        }
        for( int i=0; i<n; i++ ) {
            for( int j=i+1; j<n; j++ ) {
                tab.push_back( abs( v[i]-v[j] ) );
            }
        }
        vector<int> wy;
        int gdzie = 1;
        cout << "YES\n";
        int x=0;
        for( int i=1; i<=n; i++ ) {
            while( drz[gdzie] ) gdzie++;
            cout << gdzie << " ";
            for( int & i : tab ) {
                if( gdzie+i <= 1000000 ) {
                    drz[gdzie+i] = 1;
                    x = max( gdzie+i, x );
                }
            }
            gdzie++;
        }
        cout << "\n";
        for( int i=0; i<=x; i++ ) {
            drz[i] = 0;
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int t;
    cin >> t;
    while( t-- ) {
        algo p;
    }

    return 0;
}
/*

1 5 4 1 3
            */