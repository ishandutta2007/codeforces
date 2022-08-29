#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 505;

int N, M;
int A[MAX][MAX], B[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++) {
        int a_sum = 0, b_sum = 0;

        for (int j = 0; j < M; j++) {
            a_sum += A[i][j];
            b_sum += B[i][j];
        }

        if (a_sum % 2 != b_sum % 2) {
            cout << "No" << '\n';
            return 0;
        }
    }

    for (int j = 0; j < M; j++) {
        int a_sum = 0, b_sum = 0;

        for (int i = 0; i < N; i++) {
            a_sum += A[i][j];
            b_sum += B[i][j];
        }

        if (a_sum % 2 != b_sum % 2) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
}