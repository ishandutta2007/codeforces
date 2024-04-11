#include <iostream>
#include <algorithm>

using namespace std;

string s, t;

int main() {
    cin >> s >> t;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[j]) j++;
        if (j == t.size()) break;
    }
    if (j == t.size()) {
        cout << "automaton\n";
        return 0;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) {
        cout << "array\n";
        return 0;
    }
    j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[j]) j++;
        if (j == t.size()) break;
    }
    if (j == t.size()) {
        cout << "both\n";
        return 0;
    }
    cout << "need tree\n";
}