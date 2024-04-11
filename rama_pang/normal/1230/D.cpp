#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
lint N;
pair<lint, lint> A[7005];
lint p[7005], in[7005];
lint par(lint n) {
    return (p[n] == n)? n : p[n] = par(p[n]);
}
bool check(lint a, lint b) {
    lint tmp = a ^ b;
    for (int i = 0; i < 60; i++) {
        if (tmp & (1ll << i)) {
            if ((a & (1ll << i))) continue;
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = 0; i < N; i++) cin >> A[i].fi;
    for (int i = 0; i < N; i++) cin >> A[i].se;
    lint ans = 0;
    sort(A, A + N);
    reverse(A, A + N);
    set<lint> sub; 
    for (int i = 0; i < N; i++) {
        bool ok = 0;
        while (i < N - 1 && A[i + 1].fi == A[i].fi) {
            in[i] = 1;
            sub.insert(A[i].fi);
            ans += A[i].se;
            i++;
            ok = 1;
        }
        if (ok) in[i] = 1;
        if (ok) ans += A[i].se;
        if (ok) sub.insert(A[i].fi);
    }
    for (int i = 0; i < N; i++) {
        if (in[i] == 1) continue;
        for (auto &k : sub) {
            if (check(k, A[i].fi)) {
                ans += A[i].se;
                in[i] = 1;
                sub.insert(A[i].fi);
                break;
            }
        }
    }
    cout << ans << "\n";
}