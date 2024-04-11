#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    auto query = [](int c) -> int {
        cout << "+ " << c << endl;
        int ans;
        cin >> ans;
        return ans;
    };

    int prev_value = 0, prev_offset = 0;
    for (int jump = 1 << (32 - __builtin_clz(n - 1) - 1); jump > 0; jump /= 2) {
        int cur_jump = prev_offset + jump;
        int cur_value = query(cur_jump);
        if (cur_value != prev_value) {
            prev_offset = n - jump;
        } else {
            prev_offset = 0;
        }
        prev_value = cur_value;
    }

    cout << "! ";
    if (prev_offset > 0) {
        cout << n * prev_value << endl;
    } else {
        cout << n * (prev_value + 1) - 1 << endl;
    }
    return 0;
}