#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    cout << (int)(s.back() - '0') % 2 << endl;
    return 0;
}