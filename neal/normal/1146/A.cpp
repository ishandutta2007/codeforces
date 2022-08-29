#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int a = 0, b = 0;

    for (char c : s)
        if (c == 'a')
            a++;
        else
            b++;

    cout << s.size() - max(b - (a - 1), 0) << '\n';
}