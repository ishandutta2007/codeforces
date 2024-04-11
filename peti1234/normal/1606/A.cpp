#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n;
    string s;
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        cout << s.substr(0, n-1) << s[0] << "\n";
    }
    return 0;
}