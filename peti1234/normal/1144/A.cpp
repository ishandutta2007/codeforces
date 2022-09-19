#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        bool baj=0;
        for (int i=1; i<s.size(); i++) {
            if (s[i]-s[i-1]!=1) {
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}