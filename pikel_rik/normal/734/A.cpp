#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c = 0;
    for (auto x: s) {
        if (x == 'A')
            c += 1;
    }
    if (n < 2 * c)
        cout << "Anton";
    else if (n > 2 * c)
        cout << "Danik";
    else
        cout << "Friendship";
    return 0;
}