#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' and s[i] <= 'Z')
            c += 1;
    }
    if (s.length() >= 2 * c) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' and s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        }
        cout << s;
    }
    else {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < 'A' or s[i] > 'Z')
                s[i] = s[i] + 'A' - 'a';
        }
        cout << s;
    }
    return 0;
}