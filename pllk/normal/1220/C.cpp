#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    char g = 'z'+1;
    for (int i = 0; i < n; i++) {
        if (g < s[i]) cout << "Ann\n";
        else cout << "Mike\n";
        if (s[i] < g) g = s[i];
    }
}