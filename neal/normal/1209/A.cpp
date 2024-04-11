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
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int answer = 0;

    for (int i = 0; i < N; i++) {
        bool divisible = false;

        for (int j = 0; j < i; j++)
            if (A[i] % A[j] == 0)
                divisible = true;

        if (!divisible)
            answer++;
    }

    cout << answer << '\n';
}