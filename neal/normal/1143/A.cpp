#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int last_zero = 0, last_one = 0;

    for (int i = 1; i <= N; i++) {
        int door;
        cin >> door;

        if (door == 0)
            last_zero = i;
        else
            last_one = i;
    }

    cout << min(last_zero, last_one) << '\n';
}