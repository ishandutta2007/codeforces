#include <bits/stdc++.h>
using namespace std;

int N, A[100005], B[100005], r[100005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        r[a] = i;
        A[i] = a;
    }
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        B[a] = i;
    }
    int cur = -1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cur < B[A[i]]) cur = B[A[i]];
        else ans++;
    }
    cout << ans << "\n";
}