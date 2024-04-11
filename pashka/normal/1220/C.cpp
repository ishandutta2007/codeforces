#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> pos(26, n);
    for (int i = n - 1; i >= 0; i--) {
        pos[s[i] - 'a'] = i;
    }
    for (int i = 0; i < n; i++) {
        int l = i;
        for (int j = 0; j < s[i] - 'a'; j++) {
            l = min(l, pos[j]);
        }
        if (s[l] < s[i]) {
            cout << "Ann\n";
        } else {
            cout << "Mike\n";
        }
    }

    return 0;
}