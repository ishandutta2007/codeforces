#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> M(N, vector<int>(N));
    vector<long long> A(N, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> M[i][j];

    long long triple = round(sqrt(M[0][1]) * sqrt(M[0][2]) * sqrt(M[1][2]));
    A[0] = triple / M[1][2];

    for (int i = 1; i < N; i++)
        A[i] = M[0][i] / A[0];

    for (int i = 0; i < N; i++)
        cout << A[i] << (i < N - 1 ? ' ' : '\n');
}