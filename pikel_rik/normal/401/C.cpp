#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if (m > 2 * (n + 1) or m < n - 1) {
        cout << "-1\n";
    }
    else {
        string s;
        for (int i = 0; i < min(n, m); i++) {
            s.push_back('1');
            s.push_back('0');
        }

        if (n > m) {
            reverse(all(s));
            s.push_back('0');
        }

        m -= n;

        for (int i = 0; i < s.length(); i++) {
            cout << s[i];
            if (m > 0 and s[i] == '1') {
                cout << s[i];
                m -= 1;
            }
        }
        for (int i = 0; i < m; i++) cout << '1';
    }
    return 0;
}