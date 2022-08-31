#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i])
            ans.push_back('1');
        else
            ans.push_back('0');
    }
    cout << ans;
    return 0;
}