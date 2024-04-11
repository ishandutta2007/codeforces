#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string digits;
    cin >> k;
    for (int i = 1; i < k + 1; i++) {
        digits.append(to_string(i));
    }
    cout << digits[k - 1];
}