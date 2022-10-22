#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    int p, y; cin >> p >> y;
    for (int i = y; i > p; --i){
        bool c = true;
        for (int j = 2; j * j <= i and j <= p; ++j){
            if (i % j == 0){
                c = false;
                break;
            }
        }
        if (c) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}