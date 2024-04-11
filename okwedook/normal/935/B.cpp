#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, x = 0, y = 0;
    char curr = s[0];
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') ++y;
        else ++x;
        if (x < y && curr != 'U') ++ans, curr = 'U';
        if (x > y && curr != 'R') ++ans, curr = 'R';
    }
    cout << ans;
    //system("pause");
    return 0;
}