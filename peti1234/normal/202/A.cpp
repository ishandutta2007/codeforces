#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    for (auto x:s) {
        if (x==s[0]) {
            cout << x;
        }
    }
    cout << "\n";
    return 0;
}