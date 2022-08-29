#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
vector<int> A;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    cin >> S;
    long long total = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && S[i] == S[j])
            j++;

        sort(A.begin() + i, A.begin() + j);
        reverse(A.begin() + i, A.begin() + j);

        for (int k = i; k < min(j, i + K); k++)
            total += A[k];
    }

    cout << total << '\n';
}