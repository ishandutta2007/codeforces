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
        int db=0;
        for (auto c:s) {
            if (c=='N') db++;
        }
        cout << (db==1 ? "NO" : "YES") << "\n";
    }
    return 0;
}