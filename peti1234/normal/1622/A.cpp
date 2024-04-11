#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, t[3];
    cin >> w;
    while (w--) {
        cin >> t[0] >> t[1] >> t[2];
        sort(t, t+3);
        cout << (t[2]==t[0]+t[1] || t[0]==t[1] && t[2]%2==0 || t[1]==t[2] && t[0]%2==0 ? "YES" : "NO") << "\n";
    }
    return 0;
}