#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    pair<int, int> A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A, A + N);

    if (N <= 3) {
        cout << 1 << "\n";
        return 0;
    }

    int jump = A[2].first - A[1].first;
    bool can = true;
    for (int i = 2; i < N; i++) {
        if (A[i].first == A[1].first + (jump * (i - 1))) continue;
        can = false;
        break;
    }

    if (can) {
        cout << A[0].second + 1 << "\n";
        return 0;
    }

    can = true;
    jump = A[1].first - A[0].first;
    for (int i = 1; i < N - 1; i++) {
        if (A[i].first == A[0].first + jump * i) continue;
        can = false;
        break;
    }

    if (can) {
        cout << A[N - 1].second + 1 << "\n";
        return 0;
    }

    can = true;
    jump = A[N - 1].first - A[0].first;
    if (jump % (N - 2) != 0) {
        cout << -1 << "\n";
        return 0;
    }
    jump /= (N - 2);
    int cnt = 0, last = -1;
    int off = 0;
    for (int i = 1; i < N - 1; i++) {
        if (A[i].first == A[0].first + (i + off) * jump) continue;
        cnt++;
        last = i;
        off = -1;
    }

    if (cnt == 1) {
        cout << A[last].second + 1 << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}