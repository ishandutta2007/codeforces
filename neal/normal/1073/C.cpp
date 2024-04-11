#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, X, Y;
string str;

void modify(int &x, int &y, char change, int direction) {
    if (change == 'U')
        y += direction;
    else if (change == 'D')
        y -= direction;
    else if (change == 'R')
        x += direction;
    else if (change == 'L')
        x -= direction;
    else
        assert(false);
}

bool possible(int length) {
    int x = 0, y = 0;

    for (int i = length; i < N; i++)
        modify(x, y, str[i], +1);

    for (int i = 0; i + length <= N; i++) {
        if (abs(X - x) + abs(Y - y) <= length)
            return true;

        if (i < N)
            modify(x, y, str[i], +1);

        if (i + length < N)
            modify(x, y, str[i + length], -1);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> str >> X >> Y;
    int sum = abs(X) + abs(Y);

    if (sum > N || sum % 2 != N % 2) {
        cout << -1 << '\n';
        return 0;
    }

    int low = 0, high = N;

    while (low < high) {
        int mid = (low + high) / 2;

        if (possible(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}