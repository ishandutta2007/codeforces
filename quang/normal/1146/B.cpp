#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int check(const string &s, const string &a) {
    if (a.size() % 2 == 1) return -1;
    int sz = a.size() / 2;
    for (int i = 0; i < sz; i++) {
        if (a[i] != a[i + sz]) return -1;
    }
    for (int i = 1; i <= sz; i++) {
        if (s[s.size() - i] == 'a') return -1;
    }
    return s.size() - sz;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string a = "";
    for (char u : s) {
        if (u != 'a') a += u;
    }
    int id = check(s, a);
    if (id == -1) {
        cout << ":(" << endl;
        return 0;
    }
    for (int i = 0; i < id; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}