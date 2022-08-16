#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long long N, P, W, D;
    cin >> N >> P >> W >> D;
 
    for (long long draws = 0; draws < W; draws++) {
        long long remain = P - draws * D;
 
        if (remain >= 0 && remain % W == 0 && draws + remain / W <= N) {
            cout << remain / W << ' ' << draws << ' ' << N - (remain / W) - draws << '\n';
            return 0;
        }
    }
 
    cout << -1 << '\n';
    return 0;
}