#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll

vector<int> v;

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    multiset<int> s;
    int a;
    int suma=0;
    for( int i : v ) {
        cin >> a;
        s.insert( i+suma );
        suma += a;
        int res=0;
        while( *s.begin() < suma ) {
            res += *s.begin()-suma+a;
            s.erase( s.begin() );
        }
        res += s.size()*a;
        cout << res << " ";
    }

    return 0;
}