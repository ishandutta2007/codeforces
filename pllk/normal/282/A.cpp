#include <iostream>

using namespace std;

int n;
string s;

int main() {
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[0] == '+' || s[2] == '+') x++;
        else x--;
    }
    cout << x << endl;
}