#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        if (s.size()==2) cout << s[1] << "\n";
        else {
            sort(s.begin(), s.end());
            cout << s[0] << "\n";
        }
    }
    return 0;
}