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
        long long A, B, C;
        cin >> A >> B >> C;
        cout << (A + B + C) / 2 << '\n';
    }
}