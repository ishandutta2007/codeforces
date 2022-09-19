#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n;
        string s;
        cin >> n >> s;
        bool jo=1;
        int a=0, b=0;
        for (auto c:s) {
            if (c=='W') {
                if (a!=b) jo=0;
                a=0, b=0;
            }
            if (c=='R') a=1;
            if (c=='B') b=1;
        }
        if (a!=b) {
            jo=0;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}