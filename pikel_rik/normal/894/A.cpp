#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.length();
    string s1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'Q' or s[i] == 'A')
            s1.push_back(s[i]);
    }

    n = s1.length();
    int c = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] == 'Q') {
            for (int j = i+1; j < n; j++) {
                if (s1[j] == 'A') {
                    for (int k = j+1; k < n; k++) {
                        if (s1[k] == 'Q')
                            c += 1;
                    }
                }
            }
        }
    }
    cout << c;
    return 0;

}