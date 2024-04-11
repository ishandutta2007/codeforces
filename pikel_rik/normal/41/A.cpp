#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int flag = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[s1.length()-i-1]) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}