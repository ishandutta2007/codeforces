#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string res = "blue";
    bool locked = false;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "lock") {
            locked = true;
        } else if (s == "unlock") {
            locked = false;
        } else {
            if (!locked) {
                res = s;
            }
        }
    }
    cout << res << "\n";

    return 0;
}