#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    cin >> s;
    for (int i=2; i<s.size(); i++) {
        int a=s[i-2]-'A', b=s[i-1]-'A', c=s[i]-'A';
        if (((a+b)%26)!=c) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}