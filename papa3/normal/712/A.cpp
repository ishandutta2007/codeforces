#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    long long n, a, b;
    cin >> n >> a;
    for( int i=1; i<n; i++ ) {
        cin >> b;
        cout << a+b << ' ';
        swap( a, b );
    }
    cout << a;
    return 0;
}