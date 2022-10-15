#include <iostream>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}