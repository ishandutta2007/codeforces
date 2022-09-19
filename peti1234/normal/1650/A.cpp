#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string a;
        char b;
        cin >> a >> b;
        bool jo=0;
        for (int i=0; i<a.size(); i+=2) {
            if (a[i]==b) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}