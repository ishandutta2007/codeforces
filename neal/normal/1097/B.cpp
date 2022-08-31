#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    bool possible = false;

    for (int mask = 0; mask < 1 << N; mask++) {
        int sum = 0;

        for (int i = 0; i < N; i++)
            sum += mask & 1 << i ? A[i] : -A[i];

        if (abs(sum) % 360 == 0)
            possible = true;
    }

    puts(possible ? "YES" : "NO");
}