#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int si;
        string s;
        cin >> si >> s;
        cout << (si==1 || (si==2 && s[0]!=s[1]) ? "YES" : "NO") << "\n";
    }
    return 0;
}