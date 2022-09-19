#include <bits/stdc++.h>

using namespace std;
int w, n, bal, jobb;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size(), bal=0, jobb=n-1;
        bool baj=0;
        while (n--) {
            if (s[bal]-'a'==n) {
                bal++;
            } else if (s[jobb]-'a'==n) {
                jobb--;
            } else {
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}