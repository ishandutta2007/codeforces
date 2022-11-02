#include<bits/stdc++.h>

using namespace std;

#define int long long

int tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n=6, suma=0;
    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        suma += tab[i];
    }
    if( suma%2 ) {
        cout << "NO";
        return 0;
    }
    for( int i=1; i<=n; i++ ) {
        for( int j=i+1; j<=n; j++ ) {
            for( int k=j+1; k<=n; k++ ) {
                if( tab[i]+tab[j]+tab[k] == suma/2 ) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";

    return 0;
}