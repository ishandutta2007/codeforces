#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string s) {
    int n = s.length();

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;
    int n = S.length();
    int longest = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            string s = S.substr(i, j - i);

            if (!is_palindrome(s))
                longest = max(longest, (int) s.length());
        }
    }

    cout << longest << '\n';
    return 0;
}