#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    char minimum = 'z' + 1;

    for (char c : S)
        if (c <= minimum) {
            minimum = c;
            cout << "Mike" << '\n';
        } else {
            cout << "Ann" << '\n';
        }
}