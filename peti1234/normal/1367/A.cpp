#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        string s;
        cin >> s;
        cout << s[0];
        for (int i=1; i<s.size(); i+=2) cout << s[i];
        cout << "\n";
    }
    return 0;
}