#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (char u : s) {
        cnt += u == 'a';
    }
    int res = s.size();
    for (int i = cnt; i <= s.size(); i++) {
        if (cnt * 2 <= i) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << s.size() << endl;
    return 0;
}