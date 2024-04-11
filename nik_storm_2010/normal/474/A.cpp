#include <iostream>
#include <string>

using namespace std;
const int N = 200;
const string base[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

int main() {
    char shift;
    string s;
    cin >> shift;
    cin >> s;
    for (int i = 0; i < s.length(); i++) for (int x = 0; x < 3; x++) for (int y = 0; y < 10; y++) if (base[x][y] == s[i]) cout << base[x][y + (shift == 'R' ? -1 : +1)];
    return 0;
}