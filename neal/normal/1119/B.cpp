#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, H;
vector<int> bottles;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H;
    bottles.resize(N);

    for (int i = 0; i < N; i++)
        cin >> bottles[i];

    int best = 0;

    for (int count = 1; count <= N; count++) {
        sort(bottles.begin(), bottles.begin() + count);
        long long total_height = 0;

        for (int i = count - 1; i >= 0; i -= 2)
            total_height += bottles[i];

        if (total_height <= H)
            best = count;
    }

    cout << best << '\n';
}