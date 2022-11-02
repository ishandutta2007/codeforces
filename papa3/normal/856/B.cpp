#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define mod 1000000009

struct algo {
    int n;
    map<pair<int, int>, int > v1;
    //set<pair<int, int> > czy;
    vector<vector<int> > drogi;
    vector<pair<int, int> > tab;
    vector<pair<int, int> > wy;
    algo() {
        cin >> n;
        string s;
        int li=0;
        tab.push_back( {} );
        for( long long a, b, i=1; i<=n; i++ ) {
            cin >> s;
            a = b = 0;
            for( int j=0; j<s.size(); j++ ) {
                a = (a*33+s[j]-'a'+1)%mod;
                if( j!=0 ) b = (b*33+s[j]-'a'+1)%mod;
                if( v1.find( {a, j+1} ) != v1.end() ) continue;
                //czy.insert( {a, j+1} );
                v1[{a, j+1}] = ++li;
                tab.push_back( {b, j} );
                //v2[{b, j+1}].push_back( li );
            }
        }
        drogi.resize( li+10 );
        for( int i=1; i<=li; i++ ) {
            drogi[ v1[ tab[i] ] ].push_back( i );
        }
        wy.resize( li+10 );
        cout << dfs().second << "\n";
    }

    pair<int, int> dfs( int gdzie=0 ) {
        if( wy[gdzie].second != 0 ) return wy[gdzie];
        int x=0, y=0;
        pair<int, int> p;
        for( int i : drogi[gdzie] ) {
            p = dfs( i );
            x += p.first;
            y += p.second;
        }
        return wy[gdzie] = {max(y+1, x), x};
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