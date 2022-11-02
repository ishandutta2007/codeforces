#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    long long n, akt=2;
    cin >> n;
    cout << "2\n";
    for( long long i=2; i<=n; i++ ) {
        cout << i*i*i+2*i*i+1 << "\n";
    }

    return 0;
}