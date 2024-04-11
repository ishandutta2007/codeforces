#include <bits/stdc++.h>
using namespace std;
bool done[100005];
int N, S, X;
int main() {
    srand(time(0));
    cin >> N >> S >> X;
    int ai = -1, anext = S;
    // done[S] = true;
    vector<int> rd(N + 1, 0);
    iota(rd.begin(), rd.end(), 0);
    random_shuffle(rd.begin() + 1, rd.end());
    for (int i = 1; i <= min((size_t)999, rd.size() - 1); i++) {
        int k = rd[i];
        if (i == 1) k = S;
        cout << "? " << k << endl;
        int v, n; cin >> v >> n;
        if (v > ai && v < X) {
            ai = v;
            anext = n;
        }
    }

    while (1) {
        if (anext == -1) {
            cout << "! -1" << endl;
            return 0;
        }
        cout << "? " << anext << endl;
        int v, n; cin >> v >> n;
        if (v >= X) {
            cout << "! " << v << endl;
            return 0;
        }
        anext = n;
    }
}