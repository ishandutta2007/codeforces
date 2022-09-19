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
        bool jo=1;
        int cnt=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='A') cnt++;
            else cnt--;
            if (cnt<0) {
                jo=0;
            }
        }
        if (s.back()!='B') jo=0;
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}