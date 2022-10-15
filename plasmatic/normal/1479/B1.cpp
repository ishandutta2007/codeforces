// ./b1-painting-the-array-i.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 1e5 + 1;
int N,
    A[MN];
bool sel[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // for (int i = 0; i < N-1; i++) {
    //     if (A[i] == A[i+1] && !sel[i] && !sel[i+1]) {
    //         sel[i+1] = true;
    //     }
    // }

    vector<pii> seg;
    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && A[i] == A[j]) j++;
        seg.push_back({i, j-1});
        i = j;
    }
    int sz = seg.size(), pre = -1, pre1 = -1;
    for (int i = 0; i < sz; i++) {
        int l = seg[i].first, r = seg[i].second;
        if (r > l) {
            // printf("i=%d l=%d-%d pre=%d p2=%d\n",i,l,r,pre, pre1);
            if (pre != -1 && A[pre] == A[l]) {
                // printf("ohno\n");
                if (pre1 != -1) {
                    // printf("foundit\n");
                    sel[pre1] = true;
                }
            }

            sel[l] = true;
            pre = l;
            pre1 = -1;
        }
        else {
            if (pre != -1 && i > 0 && i < sz-1) { // 1s on the edge don't matter
                if (A[seg[i-1].first] != A[seg[i+1].first] && A[pre] != A[l])
                    pre1 = l;
            }
        }
    }
    // for (int i = 0; i < N; i++)  {
    //     printf("%d ", sel[i]);
    // }
    // printf("\n");

    auto cnt = [&] (int s) {
        int pre = 0, res = 0;
        for (int i = 0; i < N; i++) {
            if (sel[i] != s) continue;
            if (pre != A[i]) {
                pre = A[i];
                res++;
            }
        }
        return res;
    };

    // get rest
    // for (int i = 0; i < N; i++) {
    //     if (sel[i]) continue;
    //     if (pre != A[i]) {
    //         pre = A[i];
    //         ans++;
    //     }
    // }

    cout << (cnt(0) + cnt(1)) << '\n';

    return 0;
}