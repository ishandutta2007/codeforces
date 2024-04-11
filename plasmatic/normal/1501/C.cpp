// ./c-going-home.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1, MV = 2.5e6 + 1;
int N, 
    A[MN], idx[MN], mx[MV], mn[MV];
pair<int, int> _A[MN];

void reset() {
    fill(mn, mn+MV, INF);
    fill(mx, mx+MV, -INF);
}
void retyes(int a, int b, int c, int d) {
    cout << "YES\n" << idx[a] << ' ' << idx[b] << ' ' << idx[c] << ' ' << idx[d] << '\n';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> _A[i].first;
        _A[i].second = i+1;
    }
    sort(_A, _A+N);
    for (auto i = 0; i < N; i++)
        tie(A[i], idx[i]) = _A[i];
    reset();
    for (auto i = 0; i < N-1; i++) {
        int d = A[i+1]-A[i];
        mn[d] = min(mn[d], i);
        mx[d] = max(mx[d], i);
    }
    for (auto i = 0; i < MV; i++)
        if (mn[i] + 1 < mx[i])
            retyes(mn[i], mx[i]+1, mn[i]+1, mx[i]);
    reset();
    for (auto i = 0; i < N; i++) {
        for (auto j = i+1; j < N; j++) {
            int d = A[j] - A[i];
            mn[d] = min(mn[d], j);
            mx[d] = max(mx[d], i);
        }
    }
    for (auto i = 0; i < MV; i++) {
        if (mn[i] < mx[i]) {
            int a = mn[i], b = mx[i], c = a, d = b;
            while (A[a]-A[c] < i) c--;
            while (A[d]-A[b] < i) d++;
            retyes(a, b, c, d);
        }
    }
    cout << "NO\n";

    return 0;
}