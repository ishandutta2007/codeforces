#include <iostream>

using namespace std;

string s;
int c;

int main() {
    cin >> s;
    for (int i = 0; i < s.size()/2; i++) {
        if (s[i] != s[s.size()-1-i]) c++;
    }
    if (c > 1 || (c == 0 && s.size()%2 == 0)) cout << "NO\n";
    else cout << "YES\n";
}