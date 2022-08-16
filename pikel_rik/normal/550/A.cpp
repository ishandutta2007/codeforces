#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    int pos1 = -1, pos2 = -1;

    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == 'A' and s[i+1] == 'B') {
            if (pos1 == -1)
                pos1 = i;
            else if (pos2 != -1 and pos2 < i - 1) {
                pos1 = i;
                break;
            }
        }
        else if (s[i] == 'B' and s[i+1] == 'A') {
            if (pos2 == -1)
                pos2 = i;
            else if (pos1 != -1 and pos1 < i - 1) {
                pos2 = i;
                break;
            }
        }
    }

    if (pos1 != -1 and pos2 != -1 and abs(pos1 - pos2) != 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}