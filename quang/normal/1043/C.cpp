#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

string s;
int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            res[i] ^= 1;
            if (i - 1 >= 0) {
                res[i - 1] ^= 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}