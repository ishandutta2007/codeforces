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
        set<char> betu;
        int n=s.size();
        for (int i=0; i<n; i++) {
            betu.insert(s[i]);
        }
        int si=betu.size();
        bool jo=1;
        for (int i=si; i<n; i++) {
            if (s[i]!=s[i-si]) {
                jo=0;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}