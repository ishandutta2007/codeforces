#include <iostream>

using namespace std;

string s;
int x, c;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') x = 1;
        if (s[i] == '0' && x) c++;
    }
    if (c >= 6) cout << "yes\n";
    else cout << "no\n";
}