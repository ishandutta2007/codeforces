#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int query(int student) {
    cout << "? " << student << endl;
    int value;
    cin >> value;
    return value;
}

void finish(int answer) {
    cout << "! " << answer << endl;
    exit(0);
}

int sign(int number) {
    return number > 0 ? +1 : -1;
}

int main() {
    int N;
    cin >> N;
    assert(N % 2 == 0);
    N /= 2;

    int difference = query(1) - query(N + 1);

    if (difference == 0)
        finish(1);

    if (difference % 2 != 0)
        finish(-1);

    int low = 2, high = N;

    while (low <= high) {
        int mid = (low + high) / 2;
        int diff = query(mid) - query(N + mid);

        if (diff == 0)
            finish(mid);

        if (sign(diff) == sign(difference))
            low = mid + 1;
        else
            high = mid - 1;
    }

    assert(false);
    return 0;
}