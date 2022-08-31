#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    while (Q-- > 0) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int &a : A)
            cin >> a;

        sort(A.begin(), A.end());
        bool adjacent = false;

        for (int i = 0; i < N - 1; i++)
            if (A[i + 1] - A[i] == 1)
                adjacent = true;

        cout << (adjacent ? 2 : 1) << '\n';
    }
}