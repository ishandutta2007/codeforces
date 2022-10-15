// ./f2-guess-the-k-th-zero-hard-version.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int cnt0(int l, int r) {
    cout << "? " << l << ' ' << r << '\n'; cout.flush();
    int res; cin >> res; assert(res != -1);
    return r-l+1-res;
}

const int MN = 2e5 + 1;
int N, Q;

#define MID int mid = (l+r) / 2, lhs = i+1, rhs = i+(mid-l+1)*2
int sum[MN*2];
bool done[MN*2];
int kth(int k, int i=1, int l=1, int r=N) { 
    if (l == r) return l;
    MID;
    if (!done[lhs]) { sum[lhs] += cnt0(l, mid); done[lhs] = true; }
    if (k <= sum[lhs]) return kth(k, lhs, l, mid);
    else return kth(k-sum[lhs], rhs, mid+1, r);
}
void touch(int k, int i=1, int l=1, int r=N) { 
    if (k > r || k < l) return;
    sum[i]--;
    if (l == r) return;
    MID;
    touch(k, lhs, l, mid); touch(k, rhs, mid+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    while (Q--) {
        int k; cin >> k;
        int idx = kth(k);
        touch(idx);
        cout << "! " << idx << '\n'; cout.flush();
    }

    return 0;
}