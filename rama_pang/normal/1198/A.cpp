#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint N, K;
    cin >> N >> K;
    K *= 8;

    lint A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto get_val = [&] (lint k) {
        return N * (lint)ceil(log2(k));
    }; 
    
    lint cur = 0;

    lint le = 0, ri = 1e12, mx = 0;
    while (le <= ri) {
        lint mid = (le + ri) / 2;
        if (get_val(mid) <= K) {
            le = mid + 1;
            mx = mid;
        } else {
            ri = mid - 1;
        }
    }
    

    sort(A, A + N);

    vector<lint> B;
    for (int i = 0; i < N; i++) {
        lint cur = i;
        while (i + 1 < N && A[i + 1] == A[cur]) i++;
        B.emplace_back(i - cur + 1);
    }

    vector<lint> pref(B.size());
    pref[0] = B[0];
    for (int i = 1; i < B.size(); i++) pref[i] = pref[i - 1] + B[i];
    lint ans = 1e18;
    lint dif = B.size() - mx;
    if (dif <= 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (mx == 0) {
        cout << N << "\n";
        return 0;
    }
    
    assert(dif < B.size());

    ans = min(ans, pref[dif - 1]);
    ans = min(ans, pref[B.size() - 1] - pref[B.size() - dif - 1]);
    for (int i = 0; i < dif; i++) {
        ans = min(ans, pref[i] + pref[B.size() - 1] - pref[B.size() - dif + i]);
    }

    assert(ans != 1e18);
    cout << ans << "\n";

}