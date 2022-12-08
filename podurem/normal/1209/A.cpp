#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int &i : A) cin >> i;
    sort(A.begin(), A.end());
    set<int> ans;
    for (int i : A) {
        int ok = 0;
        for (int j : ans) {
            ok |= (i % j) == 0;
        }
        if (!ok) {
            ans.insert(i);
        }
    }
    cout << ans.size() << "\n";
    return 0;
}