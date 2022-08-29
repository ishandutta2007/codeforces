#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<bool> answer(n, true);
    int remove = (n - k) / 2;

    for (int i = 0; i < n && remove > 0; i++)
        if (s[i] == ')') {
            answer[i] = false;
            remove--;
        }

    remove = (n - k) / 2;

    for (int i = n - 1; i >= 0 && remove > 0; i--)
        if (s[i] == '(') {
            answer[i] = false;
            remove--;
        }

    for (int i = 0; i < n; i++)
        if (answer[i])
            cout << s[i];

    cout << '\n';
    return 0;
}