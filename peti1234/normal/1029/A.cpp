#include <bits/stdc++.h>

using namespace std;
int n, k, len;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    len=n;
    for (int i=1; i<n; i++) {
        if (s.substr(0, i)==s.substr(n-i, i)) {
            len=n-i;
        }
    }
    cout << s;
    for (int i=1; i<k; i++) {
        cout << s.substr(n-len, len);
    }
    cout << "\n";
    return 0;
}
/*
3 4
aaa
*/