#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
const double PI = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

string s;

signed main() {
    cin >> s;
    int ans = s.length() / 2;
    if (s.length() & 1) {
        for (int i = 1; i < s.length(); i++)
            if (s[i] == '1') {
                ans++;
                break;
            }
    }
    cout << ans << endl;
}