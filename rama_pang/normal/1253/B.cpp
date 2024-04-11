#include <bits/stdc++.h>
#define debug(x) cerr << ">>>> " << #x << " is " << x << endl
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
using namespace std;
using lint = long long;
using loat = long double;

const lint MOD = (lint)1e9 + 7;
const loat PI = cos((loat)-1);

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> ans;
    map<int, int> mp, f;
    int last = -1;
    for (int i = 0; i < N; i++) {
        int k = abs(A[i]);
        if (mp.count(k) == 0) {
            if (A[i] < 0) {
                cout << -1 << "\n";
                return 0;
            }

            mp[k] = 1;
        } else if (mp.count(k)) {
            if (A[i] > 0) {
                cout << -1 << "\n";
                return 0;
            }

            mp.erase(k);
        }

        if (mp.size() == 0) {
            ans.emplace_back(i - last);
            last = i;
        }
    }

    int cur = 0;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = cur; j < cur + ans[i]; j++) {
            f[abs(A[j])]++;
        }
        for (auto j : f) {
            if (j.second != 2) {
                cout << -1 << "\n";
                return 0;
            }
        }
        f.clear();
        cur += ans[i];
    }

    if (ans.size() == 0 || last != N - 1) {
        cout << -1 << "\n";
        return 0;
    }

    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
    return 0;
}