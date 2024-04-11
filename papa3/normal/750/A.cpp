#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );

    int n, k;
    cin >> n >> k;
    int i=1, wy=0;
    while( i<=n && i*5+k <= 240 ) {
        k += i*5;
        i++;
        wy++;
    }
    cout << wy;

    return 0;
}