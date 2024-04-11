#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, b, a;
    cin >> n >> b >> a;
    int aa = a;
    vector<int> s(n);
    for (int &u : s) cin >> u;

    for (int i = 0; i < s.size(); i++) {
        if (a == 0 && b == 0) {
            cout << i << endl;
            return 0;
        }
        if (s[i] == 1 && b > 0 && a < aa) {
            b--;
            a++;
            continue;
        }
        if (a > 0) a--;
        else b--;
    }
    cout << s.size() << endl;
    return 0;
}