#include <bits/stdc++.h>

using namespace std;
string s, f;
int main()
{
    cin >> s;
    while (s.size()>0 && s.back()=='0') {
        s.pop_back();
    }
    f=s;
    reverse(f.begin(), f.end());
    cout << (f==s ? "YES" : "NO") << "\n";
    return 0;
}