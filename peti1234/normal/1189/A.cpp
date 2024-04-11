#include <bits/stdc++.h>

using namespace std;
int n, a, b;
string s;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        (s[i]=='0' ? a++ : b++);
    }
    if (a!=b) {
        cout << 1 << "\n" << s << "\n";
    } else {
        cout << 2 << "\n" << s[0] << " " << s.substr(1, n-1) << "\n";
    }
    return 0;
}