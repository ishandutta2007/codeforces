#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if ( x == 0 || y == 0 ) return 1;
    while ( x != y ) {
          if ( x > y ) {
               x -= y;
          }
          else {
               y -= x;
          }
    }
    return x;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    for (;;) {
        n -= gcd(a, n);
        if ( n < 0 ) {
             cout << "1" << endl;
             break;
        }
        n -= gcd(b, n);
        if ( n < 0 ) {
             cout << "0" << endl;
             break;
        }
    }
    return 0;
}