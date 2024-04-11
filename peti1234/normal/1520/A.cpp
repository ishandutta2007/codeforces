#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> s;
        int a=0;
        for (int i=1; i<n; i++) {
            if (s[i]!=s[i-1]) {
                a++;
            }
        }
        sort(s.begin(), s.end());
        for (int i=1; i<n; i++) {
            if (s[i]!=s[i-1]) {
                a--;
            }
        }
        cout << (a ? "NO" : "YES") << "\n";
    }
    return 0;
}