#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int main() {
    cin.tie();
    cout.tie();
    string s;
    int a = 0;
    int b = 0;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        if (s[i] == '1') {
            cout << 1 << " " << a + 1 << '\n';
            a = (a + 2) % 4;
        }
        if (s[i] == '0') {
            cout << 2 << " " << b + 1 << '\n';
            b = (b + 1) % 4;
        }
    }
}