#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint d[4], cnt[4];
lint ans = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> A;
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'U') {
                d[0]++;
            }
            if (s[i] == 'R') {
                d[1]++;
            }
            if (s[i] == 'D') {
                d[2]++;
            }
            if (s[i] == 'L') {
                d[3]++;
            }
        }

        if (min(d[0], d[2]) == 0 && min(d[1], d[3]) == 0) {
            cout << 0 << "\n\n";
            continue;
        }
        if (min(d[0], d[2]) == 0) {
            cout << 2 << "\nRL\n";
            continue;
        }
        if (min(d[1], d[3]) == 0) {
            cout << 2 << "\nUD\n";
            continue;
        }

        ans += abs(d[0] - d[2]);
        ans += abs(d[1] - d[3]);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'U') {
                cnt[0]++;
                if (cnt[0] <= min(d[0], d[2])) {
                    A.emplace_back(0);
                }
            }
            if (s[i] == 'R') {
                cnt[1]++;
                if (cnt[1] <= min(d[1], d[3])) {
                    A.emplace_back(1);
                }
            }
            if (s[i] == 'D') {
                cnt[2]++;
                if (cnt[2] <= min(d[0], d[2])) {
                    A.emplace_back(2);
                }
            }
            if (s[i] == 'L') {
                cnt[3]++;
                if (cnt[3] <= min(d[1], d[3])) {
                    A.emplace_back(3);
                }
            }
        }
        string t;
        sort(A.begin(), A.end());

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0) {
                // d[0]++;
                t.push_back('U');
            }
            if (A[i] == 1) {
                // d[1]++;
                t.push_back('R');
            }
            if (A[i] == 2) {
                t.push_back('D');
                // d[2]++;
            }
            if (A[i] == 3) {
                t.push_back('L');
                // d[3]++;
            }
        }
        

        cout << t.size() << "\n";
        cout << t << "\n";
    }
}