#include<bits/stdc++.h>

using namespace std;

int t[100010];
long long sum[100010];
set<pair<int, int> > s;
multiset<long long> wy;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> t[i];
        sum[i] = sum[i-1]+t[i];
        //cout << sum[i] << " ";
    }
    s.insert( make_pair( 1, n ) );
    wy.insert( 0 );
    wy.insert( sum[n]-sum[0] );
    pair<int, int> p;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        auto it = s.lower_bound( make_pair( a, numeric_limits<int>::max() ) );
        it--;
        p = *it;
        //p = *( s.begin() );
        //cout << p.first << " " << p.second << "  ";
        s.erase( it );
        //cout << "asdf" << endl;
        auto it2 = wy.lower_bound( sum[p.second] - sum[p.first-1] );
        //cout << *it2 << "   ";
        wy.erase( it2 );
        if( p.first < a ) {
            s.insert( {p.first, a-1} );
            wy.insert( sum[a-1]-sum[p.first-1] );
            //cout << sum[a-1]-sum[p.first-1] << "  ";
        }
        if( a < p.second ) {
            s.insert( {a+1, p.second} );
            wy.insert( sum[p.second]-sum[a] );
            //cout << sum[p.second]-sum[a] << "   " << p.second << " " << a << " ";
        }
        auto it3 = wy.end();
        it3--;
        cout << *it3 << "\n";
    }
    return 0;
}
/*
4
1 2 3 5
*/