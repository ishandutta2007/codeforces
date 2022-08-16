#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    vector<int> lps(n);

    int j = 1, len = 0;
    while (j < n) {
        if (s[j] == s[len]) {
            len++;
            lps[j] = len;
            j++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[j] = 0;
                j++;
            }
        }
    }

    if (lps[n-1] == 0) {
        cout << "Just a legend\n";
        return 0;
    }

    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if (lps[i] == lps[n-1])
            flag = true;
    }

    if (!flag and lps[lps[n-1] - 1] == 0) {
        cout << "Just a legend\n";
        return 0;
    }

    if (flag) {
        for (int i = 0; i < lps[n-1]; i++)
            cout << s[i];
        cout << "\n";
        return 0;
    }

    for (int i = 0; i < lps[lps[n-1] - 1]; i++)
        cout << s[i];
    cout << "\n";
    return 0;
}