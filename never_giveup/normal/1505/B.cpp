#include<bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    while (x >= 10) {
        string s = to_string(x);
        x = 0;
        for (char c : s)
            x += c - 48;
    }
    cout << x;
}