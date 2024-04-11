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
    vector<long long> A(N);
    vector<int> counts(64, 0);

    for (long long &a : A) {
        cin >> a;

        for (int bit = 0; bit < 60; bit++)
            if (a >> bit & 1)
                counts[bit]++;
    }

    int highest = -1, best = -1;

    for (int i = 0; i < N; i++) {
        for (int bit = 0; bit < 60; bit++)
            if (A[i] >> bit & 1)
                if (counts[bit] == 1)
                    if (bit > highest) {
                        highest = bit;
                        best = i;
                    }
    }

    if (best >= 0)
        swap(A[0], A[best]);

    for (int i = 0; i < N; i++)
        cout << A[i] << (i < N - 1 ? ' ' : '\n');
}