#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> n >> k;

        string s;
        cin >> s;

        sort(all(s));

        if (k == 1) {
            cout << s << "\n";
            continue;
        }
        else if (s[0] == s[n-1]) {
            for (int i = 0; i < (n + k - 1) / k; i++) cout << s[0];
            cout << "\n";
            continue;
        }

        if (s[0] != s[k-1]) {
            cout << s[k-1] << "\n";
            continue;
        }

        if (s[k] == s[n-1]) {
            cout << s[k-1];
            for (int i = 0; i < (n - 1) / k; i++) cout << s[k];
            cout << "\n";
            continue;
        }

        for (int i = k-1; i < n; i++) cout << s[i];
        cout << "\n";
    }
    return 0;
}