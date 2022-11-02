#include <iostream>

using namespace std;

int main()
{
    long long x1, x2, y1, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    y1 = min( y1, y2 );
    x1 = max( x1, x2 );
    if( y1 < x1 ) {
        cout << 0;
        return 0;
    }
    if( k >= x1 && k <= y1 ) {
        cout << y1-x1;
    } else {
        cout << y1-x1+1;
    }
    return 0;
}