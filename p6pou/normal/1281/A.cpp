#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    string s;
    cin >> T;
    while (T --) {
        cin >> s;
        int len = s.length();
        if (len >= 2 && s.substr(len - 2) == "po") {
            cout << "FILIPINO" << endl;
        } else if (len >= 4 && (s.substr(len - 4) == "desu" || s.substr(len - 4) == "masu")) {
            cout << "JAPANESE" << endl;
        } else if (len >= 5 && s.substr(len - 5) == "mnida") {
            cout << "KOREAN" << endl;
        }
    }
    return 0;
}