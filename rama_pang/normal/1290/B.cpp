#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string S;
    cin >> S;

    int pref[S.size() + 5][30] = {};
    for (int i = 0; i < S.size(); i++) {
        pref[i + 1][S[i] - 'a'] = 1;
    }
    int N = S.size();
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 26; j++) {
            pref[i][j] += pref[i - 1][j];
        }
    }
    auto get = [&](int i, int j, int alp) {
        return pref[j][alp] - pref[i - 1][alp];
    };

    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int l, r;
        cin >> l >> r;
        int distinct = 0;
        for (int j = 0; j < 26; j++) {
            distinct += (get(l, r, j) > 0 ? 1 : 0);
        }
        if (l == r || distinct > 2 || S[l - 1] != S[r - 1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}