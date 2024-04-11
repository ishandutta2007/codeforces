#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    string s; cin >> s;
    vector<int> cnt(10);
    for (char c : s) {
        cnt[c - '0']++;
    }
    if (cnt[0] == 0) {
        cout << "cyan\n";
        return;
    }
    cnt[0]--;
    if (cnt[0] == 0 && cnt[2] == 0 && cnt[4] == 0 && cnt[6] == 0 && cnt[8] == 0) {
        cout << "cyan\n";
        return;
    }
    if ((cnt[1] + 2 * cnt[2] + cnt[4] + 2 * cnt[5] + cnt[7] + 2 * cnt[8]) % 3 != 0) {
        cout << "cyan\n";
        return;
    }
    cout << "red\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}