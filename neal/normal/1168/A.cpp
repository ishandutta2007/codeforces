#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;

bool in_range(int a, int move, int current) {
    if (current >= a && current <= a + move)
        return true;

    if (a + move >= M && current <= a + move - M)
        return true;

    return false;
}

bool works(int move) {
    int current = 0;

    for (int a : A) {
        while (current < M && !in_range(a, move, current))
            current++;

        if (current >= M)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    int low = 0, high = M;

    while (low < high) {
        int mid = (low + high) / 2;

        if (works(mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}