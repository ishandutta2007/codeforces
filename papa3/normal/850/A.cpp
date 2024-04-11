#include<bits/stdc++.h>

using namespace std;

//#define int long long

struct moj {
    int t[5];
    int ilo( moj & a, moj & b ) {
        int res = 0;
        for( int i=0; i<5; i++ ) {
            res += (a.t[i]-t[i])*(b.t[i]-t[i]);
        }
        return res;
    }
};

vector<moj> v;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int i=0; i<n; i++ ) {
        v.push_back( {} );
        for( int j=0; j<5; j++ ) {
            cin >> v.rbegin()->t[j];
        }
    }
    vector<int> res;
    bool czy=true;
    for( int i=0; i<n; i++ ) {
        czy = true;
        for( int j=0; j<n; j++ ) {
            for( int k=0; k<n; k++ ) {
                if( i==j || i==k || j==k ) continue;
                if( v[i].ilo( v[j], v[k] ) > 0 ) {
                    czy = false;
                    break;
                }
            }
            if( !czy ) break;
        }
        if( czy ) res.push_back( i+1 );
    }
    cout << res.size() << "\n";
    for( int i : res ) {
        cout << i << "\n";
    }

    return 0;
}