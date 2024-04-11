#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long R, G, B;
    cin >> R >> G >> B;
    long long maximum = max({R, G, B});
    cout << (maximum > R + G + B - maximum + 1 ? "No" : "Yes") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}