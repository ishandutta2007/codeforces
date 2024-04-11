#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;

int previous(int index) {
    return index == 0 ? N - 1 : index - 1;
}

void answer(const vector<long long> &A) {
    cout << "YES" << '\n';

    for (int i = 0; i < N; i++)
        cout << A[i] << (i < N - 1 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> B(N);

    for (int i = 0; i < N; i++)
        cin >> B[i];

    int most = *max_element(B.begin(), B.end());

    if (most == 0) {
        answer(vector<long long>(N, 1));
        return 0;
    }

    int index = -1;

    for (int i = 0; i < N; i++)
        if (B[i] == most && B[previous(i)] < most)
            index = i;

    if (index == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<long long> A(B.begin(), B.end());

    for (int current = index; previous(current) != index; current = previous(current))
        A[previous(current)] += (current == index ? 2 : 1) * A[current];

    answer(A);
    return 0;
}