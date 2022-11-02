#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000ll

int res;

void foo( string & s ) {
    for( int i=0; i<s.size(); i++ ) {
        if( s[i] != s[s.size()-1-i] ) {
            res = max( res, (int)s.size() );
            break;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    res = 0;
    string s;
    cin >> s;
    string a;
    for( int i=0; i<s.size(); i++ ) {
        a.clear();
        for( int j=i; j<s.size(); j++ ) {
            a = a+s[j];
            foo( a );
        }
    }
    cout << res;

    return 0;
}
/*

*/