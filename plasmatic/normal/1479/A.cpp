// ./a-searching-local-minimum.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int N;

int ask(int k) {
    if (k < 0 || k >= N) return INF;
    cout << "? " << (k+1) << '\n';
    cout.flush();
    int res; cin >> res;
    return res;
}
void answer(int k) {
    cout << "! " << (k+1) << '\n';
    cout.flush();
}

bool check(int a) {
    bool good = true;
    int q = ask(a);
    if (a > 0) good &= q < ask(a-1);
    if (a < N-1) good &= q < ask(a+1);
    return good;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int l = -2, r = N-1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (ask(mid) > ask(mid+1)) l = mid;
        else r = mid;
    }

    if (check(r)) answer(r);
    else answer(r+1);

    return 0;
}