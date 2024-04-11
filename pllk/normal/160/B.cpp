#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;
int a, b;

int main() {
    cin >> n >> s;
    sort(&s[0], &s[n]);
    sort(&s[n], &s[2*n]);
    for (int i = 0; i < n; i++) {
        if (s[i] >= s[n+i]) a = 1;
        if (s[i] <= s[n+i]) b = 1;
    }
    if (a+b == 2) cout << "NO\n";
    else cout << "YES\n";
}