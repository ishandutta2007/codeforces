#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    string s = "abcdefghijklmnopqrstuvwxyz";

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string ans = s.substr(0, b);
        while (n >= b) {
            cout << ans;
            n -= b;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}