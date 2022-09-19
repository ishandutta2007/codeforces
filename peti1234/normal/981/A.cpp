#include <bits/stdc++.h>

using namespace std;
bool pal(string s)
{
    for (int i=0; i<s.size(); i++) {
        if (s[i]!=s[s.size()-i-1]) {
            return false;
        }
    }
    return true;
}
bool ugyanaz(string s)
{
    for (int i=0; i<s.size()-1; i++) {
        if (s[i]!=s[i+1]) {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    bool a=pal(s);
    bool b=ugyanaz(s);
    if (b==1) {
        cout << 0 << endl;
    } else {
        cout << s.size()-a << endl;
    }
    return 0;
}