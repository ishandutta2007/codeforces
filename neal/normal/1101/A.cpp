#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0) {
        int L, R, D;
        cin >> L >> R >> D;
        cout << (L > D ? D : R + D - R % D) << '\n';
    }
}