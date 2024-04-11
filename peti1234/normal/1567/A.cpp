#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (auto c:s) {
            if (c=='D') cout << 'U';
            if (c=='U') cout << 'D';
            if (c=='L') cout << 'L';
            if (c=='R') cout << 'R';
        }
        cout << "\n";
    }
    return 0;
}