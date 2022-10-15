#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, P;
    cin >> N >> M >> P;
    int i = 0, j = 0;
    for (; i < N; i++) {
        int x; cin >> x;
        if (x % P) break;
    }
    for (int j = i+1; j < N; j++) { // finish taking input for 1st array
        int _;
        cin >> _;
    }
    for (; j < M; j++) {
        int x; cin >> x;
        if (x % P) break;
    }
    cout << (i + j) << '\n';
}