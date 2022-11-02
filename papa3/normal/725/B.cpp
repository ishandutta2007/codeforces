#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    long long n;
    char c;
    cin >> n >> c;
    long long wy = (n-1)/4;
    wy *= 16;
    n = (n-1)%4+1;
    if( n == 2 || n == 4 ) {
        wy += 7;
    }
    switch( c ) {
    case 'a':
        wy += 4;
        break;
    case 'b':
        wy += 5;
        break;
    case 'c':
        wy += 6;
        break;
    case 'd':
        wy += 3;
        break;
    case 'e':
        wy += 2;
        break;
    case 'f':
        wy += 1;
        break;

    }
    cout << wy;
    return 0;
}