#include <bits/stdc++.h>

using namespace std;

int ask(const vector<int> &u) {
    cout << "? ";
    for (int v : u) cout << v << ' ';
        cout << endl << flush;
    int pos, val;
    cin >> pos >> val;
    return val;
}

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 1; i <= k + 1; i++) {
        vector<int> now;
        for (int j = 1; j <= k + 1; j++) {
            if (i != j) now.push_back(j);
        }
        cnt[ask(now)]++;
    }
    auto res = *cnt.rbegin();
    cout << "! " << res.second << endl;
    return 0;
}