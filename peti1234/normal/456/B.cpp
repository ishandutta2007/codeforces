#include <bits/stdc++.h>

using namespace std;
string s;
int x, n;
int main()
{
    cin >> s;
    n=s.size();
    x=(s[n-1]-'0');
    if (n>1) {
        x+=10*(s[n-2]-'0');
    }
    cout << (x%4 ? 0 : 4) << "\n";
    return 0;
}