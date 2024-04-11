#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    n = s.length();

    int c = 0;
    bool flag = false;

    if (k == 2) {
        int diff = 0, best = 0;
        string s1, s2;

        for (int i = 0; i < n; i++) {
            if (s[i] != 'A' + i % 2)
                diff += 1;
            s1.push_back('A' + i%2);
        }
        best = diff; diff = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != 'B' - i % 2)
                diff += 1;
            s2.push_back('B' - i % 2);
        }

        if (diff < best)
            cout << diff << "\n" << s2 << "\n";
        else cout << best << "\n" << s1 << "\n";
        return 0;
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i+1] and flag) {
            flag = false;
            continue;
        }
        if (s[i] == s[i-1] and s[i] == s[i+1]) {
            if (s[i - 1] + 1 - 'A' < k)
                s[i] = s[i - 1] + 1;
            else s[i] = s[i - 1] - 1;
            c += 1;
        }
        else if (s[i] == s[i-1]) {
            if (s[i-1] + 1 != s[i+1] and s[i-1] + 1 - 'A' < k)
                s[i] = s[i-1] + 1;
            else if (s[i+1] + 1 != s[i-1] and s[i+1] + 1 - 'A' < k)
                s[i] = s[i+1] + 1;
            else if (s[i-1] - 1 != s[i+1] and s[i-1] - 1 - 'A' >= 0)
                s[i] = s[i-1] - 1;
            else if (s[i+1] - 1 != s[i-1] and s[i+1] - 1 - 'A' >= 0)
                s[i] = s[i+1] - 1;
            else s[i] = s[i+1];

            c += 1;
        }

        flag = true;
        if (s[i] == s[i+1])
            flag = false;
    }

    if (n > 1 and s[n-1] == s[n-2]) {
        if (s[n-2] + 1 - 'A' < k)
            s[n-1] = s[n-2] + 1;
        else s[n-1] = s[n-2] - 1;
        c += 1;
    }

    cout << c << "\n";
    cout << s;
    return 0;
}