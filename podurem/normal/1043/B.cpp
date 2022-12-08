#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)3e5 + 3;

int solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1, 0), B(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<int> x(n);
    vector<int> ans;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            x[(i - 1) % k] = A[i] - A[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            B[i] = B[i - 1] + x[(i - 1) % k];
        }
        if (A == B) {
            ans.push_back(k);
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}