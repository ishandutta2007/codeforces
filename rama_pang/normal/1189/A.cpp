#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[2] = {};
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt[1]++;
        } else {
            cnt[0]++;
        }
    }    
    if (cnt[0] != cnt[1]) {
        cout << 1 << "\n" << s << "\n";
        return 0;
    }
    char a = s.back();
    s.pop_back();
    cout << "2\n" << s << " " << a << "\n";
}