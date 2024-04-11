// ./d-cut-and-stick.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 3e5 + 1, TRIALS = 60;
int N, Q,
    A[MN];
vector<int> fre[MN];
mt19937 mt(26022021);

int cnt(int x, int l, int r) {
    return upper_bound(fre[x].begin(), fre[x].end(), r) - lower_bound(fre[x].begin(), fre[x].end(), l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        fre[A[i]].push_back(i);
    }
    while (Q--) {
        int l, r; cin >> l >> r;
        uniform_int_distribution<int> dis(l, r);
        int sz = r-l+1, maj = -1;
        for (auto i = 0; i < TRIALS; i++) {
            int v = A[dis(mt)];
            if (cnt(v, l, r) > (sz+1)/2) {
                maj = v;
                break;
            }
        }
        if (maj == -1) cout << "1\n";
        else {
            int ccnt = cnt(maj, l, r), rem = sz-ccnt;
            cout << ccnt-rem << '\n';
        }
    }

    return 0;
}