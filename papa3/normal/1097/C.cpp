#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double
const long long mod = 1000000007ll;
const long long INF = 1000000000000000000ll;

int tttt[2000000];
int * tab = &tttt[1000000];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    string s;
    for( int i=1; i<=n; i++ ) {
        cin >> s;
        int mi=0;
        int akt=0;
        for( char c : s ) {
            if( c == '(' ) akt++;
            else akt--;
            mi = min( akt, mi );
        }
        if( akt>=0 && mi>=0 ) tab[akt]++;
        else if( akt<=0 && mi>=akt ) tab[akt]++;
    }
    int res=0;
    for( int i=1; i<=700000; i++ ) {
        res += min( tab[i], tab[-i] );
    }
    res += tab[0]/2;
    cout << res;

    return 0;
}/*

*/