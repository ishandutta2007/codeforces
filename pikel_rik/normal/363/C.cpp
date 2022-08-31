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

    string s;
    cin >> s;

    int n = s.length();
    string ans = "";

    ans += s[0];

    int c = 1, c1 = 0, cur = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1] and cur == 0) {
            c += 1;
        }
        else if (s[i] == s[i-1] and cur == 1) {
            c1 += 1;
        }
        else if (cur == 0) {
            c1 = 1;
            cur = 1;
        }
        else {
            c = 1;
            cur = 0;
        }
        if (cur == 0 and c >= 3)
            continue;
        if (cur == 1 and c1 >= 3)
            continue;
        if (cur == 0 and c1 >= 2 and c >= 2) {
            c -= 1;
            continue;
        }
        if (cur == 1 and c >= 2 and c1 >= 2) {
            c1 -= 1;
            continue;
        }
        ans.push_back(s[i]);
    }

    cout << ans;
    return 0;
}