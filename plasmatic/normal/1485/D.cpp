// ./d-multiples-and-power-differences.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 501, MV = 16+1, MP = 31+1, MO = 1e6+1;
int N, M,
    A[MN][MN], B[MN][MN];
// bool p4[MO];

ll p4(int k) { return k*k*k*k; }
vector<int> val[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i+j)%2) B[i][j] = 720720;
            else B[i][j] = 720720-p4(A[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << B[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}