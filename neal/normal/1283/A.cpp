#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int H, M;
    cin >> H >> M;
    cout << 24 * 60 - 60 * H - M << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}