#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N, A, B, C;
    string str;
    cin >> N >> A >> B >> C >> str;
    int x = 0, y = 0, z = 0;

    for (char c : str)
        if (c == 'R')
            x++;
        else if (c == 'P')
            y++;
        else if (c == 'S')
            z++;

    int counts[3] = {min(A, z), min(B, x), min(C, y)};
    int beat = counts[0] + counts[1] + counts[2];

    if (2 * beat < N) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    string answer(N, '.');

    for (int i = 0; i < N; i++)
        if (str[i] == 'S') {
            if (counts[0]-- > 0)
                answer[i] = 'R';
        } else if (str[i] == 'R') {
            if (counts[1]-- > 0)
                answer[i] = 'P';
        } else if (str[i] == 'P') {
            if (counts[2]-- > 0)
                answer[i] = 'S';
        }

    A -= min(A, z);
    B -= min(B, x);
    C -= min(C, y);

    for (int i = 0; i < N; i++)
        if (answer[i] == '.') {
            if (A-- > 0)
                answer[i] = 'R';
            else if (B-- > 0)
                answer[i] = 'P';
            else if (C-- > 0)
                answer[i] = 'S';
        }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}