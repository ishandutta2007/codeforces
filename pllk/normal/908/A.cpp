#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int u = 0;
    for (auto c : s) {
        if (c == 'a') u++;
        if (c == 'e') u++;
        if (c == 'i') u++;
        if (c == 'o') u++;
        if (c == 'u') u++;
        if (c == '1') u++;
        if (c == '3') u++;
        if (c == '5') u++;
        if (c == '7') u++;
        if (c == '9') u++;
    }
    cout << u << "\n";
}