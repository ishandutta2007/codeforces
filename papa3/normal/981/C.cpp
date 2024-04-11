#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000ll

int ile[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, b, i=1; i<n; i++ ) {
        cin >> a >> b;
        ile[a]++;
        ile[b]++;
    }
    if( n==2 ) {
        cout << "Yes\n1\n1 2";
        return 0;
    }
    int x=0;
    int gdzie=0;
    for( int i=1; i<=n; i++ ) {
        if( ile[i] > 2 ) {
            x++;
            gdzie = i;
        } else if( ile[i] > 1 && gdzie == 0 ) gdzie = i;
    }

    if( x>1 ) {
        cout << "No";
    } else {
        cout << "Yes\n" << ile[gdzie] << "\n";
        for( int i=1; i<=n; i++ ) {
            if( ile[i] == 1 ) {
                cout << i << " " << gdzie << "\n";
            }
        }
    }


    return 0;
}
/*

*/