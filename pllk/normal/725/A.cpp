#include <iostream>

using namespace std;

int c;
int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] != '<') break;
        c++;
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] != '>') break;
        c++;
    }
    cout << c << "\n";
}