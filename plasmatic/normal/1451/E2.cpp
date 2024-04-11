// ./e2-bitwise-queries-hard-version.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int ask(string t, int i, int j) {
    cout << t << ' ' << i << ' ' << j << '\n'; cout.flush();
    int res; cin >> res; assert(res != -1);
    return res;
}

const int MN = (1<<16)+1;
int N,
    X[MN], A[MN];

void answer() {
    cout << "! ";
    for (auto i = 1; i <= N; i++) cout << A[i] << " \n"[i == N];
    cout.flush();
    exit(0);
}

int xordif(int i, int j) { return X[i] ^ X[j]; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int p = 0;
    while ((1<<p) < N) p++;

    for (auto i = 2; i <= N; i++) {
        X[i] = ask("XOR", i-1, i) ^ X[i-1];
    }

    // check for duplicate
    map<int, int> idx;
    for (auto i = 1; i <= N; i++) {
        if (idx.count(X[i])) {
            A[i] = ask("OR", i, idx[X[i]]);
            for (auto j = 1; j <= N; j++)
                if (i != j)
                    A[j] = A[i] ^ xordif(i, j);

            answer();
        }
        idx[X[i]] = i;
    }
    // all distinct
    idx.clear();
    for (auto i = 1; i <= N; i++) {
        int opp = X[i] ^ ((1<<p)-1);
        if (idx.count(opp)) {
            int a = i, b = idx[opp];
            // we recover any other value
            int oth = -1; 
            for (auto j = 1; j <= N; j++) {
                if (j != a && j != b) {
                    oth = j;
                    break;
                }
            }

            int or1 = ask("OR", a, oth), or2 = ask("OR", b, oth);
            A[oth] = (1<<p)-1;
            for (auto j = 0; j < p; j++) {
                if (!((or1 >> j) & 1))
                    A[oth] ^= 1 << j;
                if (!((or2 >> j) & 1))
                    A[oth] ^= 1 << j;
            }

            for (auto j = 1; j <= N; j++)
                if (oth != j)
                    A[j] = A[oth] ^ xordif(oth, j);

            answer();
        }
        idx[X[i]] = i;
    }

    assert(0);

    return 0;
}