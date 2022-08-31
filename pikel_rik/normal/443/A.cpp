#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    if (s[1] < 'a' or s[1] > 'z')
        cout << "0";
    else {
        vector<int> count(26, 0);
        for (int i = 1; i < s.length(); i += 3) {
            count[s[i] - 'a'] += 1;
        }

        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0)
                c += 1;
        }
        cout << c;
    }
    return 0;
}