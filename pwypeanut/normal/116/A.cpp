#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int curr = 0;
    for ( int i = 0; i < n; i++ ) {
        int a, b;
        cin >> a >> b;
        curr += b-a;
        if ( curr > ans ) ans = curr;
    }
    cout << ans << endl;
    return 0;
}