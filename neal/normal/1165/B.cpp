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
    vector<int> contests(N);

    for (auto &x : contests)
        cin >> x;

    sort(contests.rbegin(), contests.rend());
    int low = 0, high = N;

    while (low < high) {
        int mid = (low + high + 1) / 2;
        bool good = true;

        for (int i = 0; i < mid; i++)
            if (contests[i] < mid - i)
                good = false;

        if (good)
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
}