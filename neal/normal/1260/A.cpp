#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int C, S;
    cin >> C >> S;
    int floor = S / C;
    int above = floor + 1;
    int count_above = S % C;
    int count_floor = C - count_above;
    cout << count_floor * floor * floor + count_above * above * above << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}