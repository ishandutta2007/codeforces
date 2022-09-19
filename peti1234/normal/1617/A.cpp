#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        if (t=="abc" && s[0]=='a') {
            for (auto x:s) {
                if (x=='a' || x=='c') cout << x;
            }
            for (auto x:s) {
                if (x!='a' && x!='c') cout << x;
            }
        } else {
            cout << s;
        }
        cout << "\n";
    }
    return 0;
}