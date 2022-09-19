#include <bits/stdc++.h>

using namespace std;
string s;
vector<char> a, b, c, pref;
int main()
{
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i=0; i<s.size(); i++) {
        a.push_back(s[i]);
        pref.push_back(s[i]);
        if (i) pref[i]=min(pref[i], pref[i-1]);
    }
    while (a.size()>0) {
        b.push_back(a.back());
        a.pop_back(), pref.pop_back();
        while (b.size()>0 && (a.size()==0 || b.back()<=pref.back())) {
            c.push_back(b.back());
            b.pop_back();
        }
    }
    for (auto x:c) {
        cout << x;
    }
    cout << "\n";
    return 0;
}