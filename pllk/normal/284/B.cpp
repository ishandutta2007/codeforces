#include <iostream>

using namespace std;

int n;
string s;
int a, i, f;

int main() {
    cin >> n >> s;
    for (int x = 0; x < n; x++) {
        if (s[x] == 'A') a++;
        if (s[x] == 'F') f++;
        if (s[x] == 'I') i++;
    }
    if (i >= 2) {
        cout << 0 << endl;
    }
    if (i == 1) {
        cout << 1 << endl;
    }
    if (i == 0) {
        cout << a << endl;
    }
}