#include<bits/stdc++.h>

using namespace std;

//#define int long long

pair<long long, int> ddpp[15000100];
int tab[5010];
long long pref[5010];
int n;

pair<long long, int> & dp( int a, int b ) {
    b-=a;
    int x = (n+2)*(n+1)/2-(n-a+2)*(n-a+1)/2;
    return ddpp[x+b-1];
}

pair<long long, int> foo( int a, int b ) {
    if( dp( a, b ).second != 0 ) return dp( a, b );
    if( a+1 == b ) return dp( a, b ) = max( make_pair(tab[a], b), make_pair(-tab[a], a) );
    pair<long long, int> x = foo( a, b-1 );
    return dp( a, b ) = max( make_pair(x.first-tab[b-1], x.second), make_pair(pref[b-1]-pref[a-1], b) );
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    //cout << sizeof( ddpp ); return 0;
    cin >> n;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        pref[i] = tab[i]+pref[i-1];
    }

    long long wy = numeric_limits<long long>::max()+1;
    pair<long long, int> a, b;
    int x, y, z;
    for( int i=1; i<=n; i++ ) {
        a = foo( 0, i );
        b = foo( i, n+1 );
        if( a.first+b.first > wy ) {
            wy = a.first+b.first;
            x = a.second;
            y = i;
            z = b.second;
        }
    }
    cout << x-1 << " " << y-1 << " " << z-1;

    return 0;
}