#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool found = 0;
        vector<int> ls;
        for (int i = 0; i < k; i++) {
            int has = -1;
            for (int j = i; j < n; j += k) {
                if (s[j] == '?') continue;
                int now = s[j] - '0';
                if (has == -1) has = now;
                else if (has != now) {
                    found = 1;
                    break;
                }
            }
            if (has == -1) ls.push_back(i);
            else {
                for (int j = i; j < n; j += k) s[j] = (char)(has + '0');
            }
        }
        if (found) {
            cout << "NO\n";
            continue;
        }
        int num[2] = {0, 0};
        for (int i = 0; i < k; i++) {
            if (s[i] == '?') continue;
            num[s[i] - '0']++;
        }
        if (num[0] > k / 2 || num[1] > k / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }   
    return 0;
}