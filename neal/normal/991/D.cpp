#include <iostream>
#include <string>
using namespace std;

int N;
string board[2];

bool is_clear(int row, int col) {
    return board[row][col] == '0';
}

bool is_clear(int row, int col, int len) {
    return board[row].substr(col, len).find('X') == string::npos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> board[0] >> board[1];
    N = board[0].size();

    int position = 0;
    int count = 0;

    while (position + 1 < N) {
        if (position + 2 < N && is_clear(0, position, 3) && is_clear(1, position, 3)) {
            position += 3;
            count += 2;
            continue;
        }

        if (is_clear(0, position, 2) && (is_clear(1, position) || is_clear(1, position + 1))) {
            position += 2;
            count++;
            continue;
        }

        if (is_clear(1, position, 2) && (is_clear(0, position) || is_clear(0, position + 1))) {
            position += 2;
            count++;
            continue;
        }

        position++;
    }

    cout << count << '\n';
    return 0;
}