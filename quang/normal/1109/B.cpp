#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

string s;

bool isPal(const string &u) {
    for (int i = 0; i < u.size(); i++) {
        if (u[i] != u[(int)u.size() - i - 1]) return 0;
    }
    return 1;
}

bool check() {
    for (int i = 0; i + 1 < s.size(); i++) {
        string now = "";
        for (int j = i + 1; j < s.size(); j++) now += s[j];
        for (int j = 0; j <= i; j++) now += s[j];
        if (isPal(now) && now != s) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int f = 0;
    for (int i = 1; i < s.size() / 2; i++) {
        if (s[i] != s[i - 1]) {
            f = 1;
            break;
        }
    }
    if (!f) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (check()) cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}