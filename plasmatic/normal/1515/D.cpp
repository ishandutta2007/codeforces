// ./d-phoenix-and-socks.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1;
int N, L, R,
    C[MN];

void solve() {
    cin >> N >> L >> R;
    for (auto i = 1; i <= L; i++) {
        cin >> C[i];
    }
    for (auto i = L+1; i <= N; i++) {
        cin >> C[i];
    }

    if (L > R) {
        vector<int> tmp(R);
        copy(C+L+1, C+N+1, tmp.begin());
        copy(C+1, C+L+1, C+R+1);
        copy(tmp.begin(), tmp.end(), C+1);
        swap(L, R);
    }

    // printf("N=%d l=%d r=%d\n",N,L,R);
    // for (auto i = 1; i <= N; i++) printf("c=%d\n", C[i]);

    vector<int> fre(N+1);
    for (auto i = 1; i <= N; i++) {
        fre[C[i]] += i <= L ? 1 : -1;
    }

    int need = (R-L)/2, oneed = need;
    vector<bool> use(N+1);
    for (auto i = L+1; i <= N; i++) {
        if (need > 0 && fre[C[i]] <= -2) {
            need--;
            fre[C[i]] += 2;
            use[i] = true;
        }
    }
    for (auto i = L+1; i <= N; i++) {
        if (need > 0 && fre[C[i]] <= -1 && !use[i]) {
            need--;
            fre[C[i]] += 2;
            use[i] = true;
        }
    }
    for (auto i = L+1; i <= N; i++) {
        if (need > 0 && !use[i]) {
            need--;
            fre[C[i]] += 2;
            use[i] = true;
        }
    }

    assert(need == 0);

    int totdif = 0;
    for (auto i = 1; i <= N; i++) {
        totdif += abs(fre[i]);
    }
    assert(totdif % 2 == 0);
    totdif /= 2;

    cout << (oneed + totdif) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}