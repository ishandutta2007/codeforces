#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}