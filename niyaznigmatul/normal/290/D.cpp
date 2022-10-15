#include <iostream>

using namespace std;

char upcase(char c) {
    if (c >= 'A' && c <= 'Z') return c;
    return c - 'a' + 'A';
}

char lowcase(char c) {
    if (c >= 'a' && c <= 'z') return c;
    return c - 'A' + 'a';
}

int main() {
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < (int) s.length(); i++) s[i] = lowcase(s[i]);
    for (int i = 0; i < (int) s.length(); i++) {
        char c = s[i];
        if (c < n + 97) {
            s[i] = upcase(s[i]);
        } else {
            s[i] = lowcase(s[i]);
        }
    }
    cout << s << "\n";
}