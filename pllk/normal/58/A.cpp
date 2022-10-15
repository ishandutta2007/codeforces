#include <iostream>

using namespace std;

string v = "helloX";
string s;

int main() {
    cin >> s;
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == v[k]) k++;
    }
    if (v[k] == 'X') cout << "YES\n";
    else cout << "NO\n";
}