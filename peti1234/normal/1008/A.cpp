#include <bits/stdc++.h>

using namespace std;
string s;

int main()
{
    cin >> s;
    for (int i=1; i<=s.size()-1; i++) {
        if (s[i]!='a' && s[i]!='e' && s[i]!='o' && s[i]!='u' && s[i]!='i') {
            i--;
            if (s[i]!='a' && s[i]!='e' && s[i]!='o' && s[i]!='u' && s[i]!='i' && s[i]!='n') {
                cout << "NO";
                return 0;
            }
            i++;
        }
    }
    char x=s[s.size()-1];
    if (x!='a' && x!='e' && x!='o' && x!='u' && x!='i' && x!='n') {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}