#include <bits/stdc++.h>

using namespace std;
string s;
int n, cnt, mini, sp;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') cnt++;
        else if (!sp) sp=1;
        else cnt--;
        mini=min(mini, cnt);
    }
    if (sp) cnt--;
    if (cnt==0 && mini>=0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}