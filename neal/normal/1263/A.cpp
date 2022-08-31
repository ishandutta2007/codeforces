#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int R, G, B;
    cin >> R >> G >> B;
    int option1 = (R + G + B) / 2;
    int option2 = R + G + B - max({R, G, B});
    cout << min(option1, option2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}