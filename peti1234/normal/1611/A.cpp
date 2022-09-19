#include <bits/stdc++.h>

using namespace std;
bool ps(char c) {
    return (c=='2' || c=='4' || c=='6' || c=='8');
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        if (ps(s.back())) cout << 0 << "\n";
        else if (ps(s[0])) cout << 1 << "\n";
        else {
            bool jo=0;
            for (auto p:s) {
                if (ps(p)) jo=1;
            }
            cout << (jo ? 2 : -1) << "\n";
        }
    }
    return 0;
}