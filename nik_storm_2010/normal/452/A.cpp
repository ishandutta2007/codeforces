#include <iostream>
#include <string>

using namespace std;
const string base[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < 8; i++) {
        if (s.length() != base[i].length()) continue;
        bool good = true;
        for (int j = 0; j < s.length(); j++) if (s[j] != '.' && s[j] != base[i][j]) good = false;
        if (!good) continue;
        cout << base[i] << endl;
        break;
    }
    return 0;
}