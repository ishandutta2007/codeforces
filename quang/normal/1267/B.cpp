#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    vector < pair < char, int > > letter;
    for (int i = 0; i < s.size();) {
        int pos = i;
        while (pos < s.size() && s[i] == s[pos]) {
            pos++;
        }
        letter.push_back(make_pair(s[i], pos - i));
        i = pos;
    }

    if (letter.size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    int n = letter.size();
    int mid = n / 2;
    if (letter[mid].f < 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < letter.size(); i++) {
        if (letter[i].f != letter[n - 1 - i].f || letter[i].s + letter[n - 1 - i].s < 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << letter[mid].s + 1 << endl;
    return 0;
}