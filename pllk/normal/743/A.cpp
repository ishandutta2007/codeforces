#include <iostream>

using namespace std;

int n, a, b;
string s;

int main() {
    cin >> n >> a >> b;
    cin >> s;
    s = "*"+s;
    if (s[a] == s[b]) cout << "0\n";
    else cout << "1\n";
}