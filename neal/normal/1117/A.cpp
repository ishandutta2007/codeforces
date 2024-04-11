#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    int most = *max_element(A.begin(), A.end());
    int answer = 0, count = 0;

    for (int i = 0; i < N; i++)
        if (A[i] == most)
            answer = max(answer, ++count);
        else
            count = 0;

    cout << answer << '\n';
}