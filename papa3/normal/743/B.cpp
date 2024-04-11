#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long n, k, dl=1;
    cin >> n >> k;
    for( int i=0; i<n; i++ ) {
        dl *= 2;
    }
    dl--;
    if( k > dl/2 ) {
        k = dl-k+1;
    }
    while( k != (dl+1)/2 ) {
        dl/=2;
        n--;
        if( k > dl/2 ) {
            k = dl-k+1;
        }
    }
    cout << n;


    return 0;
}