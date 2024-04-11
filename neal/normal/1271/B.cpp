#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int black = 0, white = 0;

    for (int i = 0; i < N; i++)
        if (S[i] == 'B')
            black++;
        else
            white++;

    if (black % 2 != 0 && white % 2 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    char color = (black % 2 != 0 ? 'B' : 'W');
    vector<int> ops;

    for (int i = 0; i < N - 1; i++)
        if (S[i] != color) {
            ops.push_back(i + 1);
            S[i] = 'B' + 'W' - S[i];
            S[i + 1] = 'B' + 'W' - S[i + 1];
        }

    assert(S.back() == color);
    cout << ops.size() << '\n';

    for (int i = 0; i < (int) ops.size(); i++)
        cout << ops[i] << (i < (int) ops.size() - 1 ? ' ' : '\n');
}