#include <bits/stdc++.h>

using namespace std;
int si, v;
string s;
int main()
{
    cin >> s, si=s.size();
    for (int i=1; i<=si-2; i++) if (s[i-1]!='.' && s[i]!='.' && s[i+1]!='.' && s[i-1]!=s[i] && s[i-1]!=s[i+1] && s[i]!=s[i+1]) v=1;
    if (v) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}