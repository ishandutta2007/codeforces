#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int &a : A)
            cin >> a;

        int minimum = 1e9 + 5, count = 0;

        for (int i = N - 1; i >= 0; i--)
            if (A[i] > minimum)
                count++;
            else
                minimum = A[i];

        cout << count << '\n';
    }
}