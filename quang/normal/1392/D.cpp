#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
string s;

int getRight(int u) {
    return (u + 1) % n;
}

int getLeft(int u) {
    return (u + n - 1) % n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> s;
        if (*max_element(s.begin(), s.end()) == *min_element(s.begin(), s.end())) {
            cout << (n - 1) / 3 + 1 << '\n';
            continue;
        }

        int res = 0;
        // get right
        for (int i = 0; i < n; i++) {
            if (s[i] != 'R') continue;
            int leftId = getLeft(i);
            if (s[leftId] != 'L') continue;

            int pos = i;
            while (s[pos] == 'R') pos = getRight(pos);
            int num = 0;
            if (pos >= i) num = pos - i + 1;
            else num = n - (i - pos - 1);
            res += max(0, (num - 1) / 3);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != 'L') continue;
            int rightId = getRight(i);
            if (s[rightId] != 'R') continue;

            int pos = i;
            while (s[pos] == 'L') pos = getLeft(pos);
            int num = 0;
            if (pos <= i) num = i - pos + 1;
            else num = n - (pos - i - 1);
            res += max(0, (num - 1) / 3);
        }

        //get left
        cout << res << '\n';
    }   
    return 0;
}