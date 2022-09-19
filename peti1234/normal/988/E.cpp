#include <bits/stdc++.h>

using namespace std;
const int c=1000;
int solve(string s, char a, char b) {
    int n=s.size(), pos=-1, ert=0;
    for (int i=0; i<n; i++) {
        if (s[i]==b) pos=i;
    }
    if (pos==-1) {
        return c;
    }
    while (pos+1<n) {
        swap(s[pos], s[pos+1]);
        pos++;
        ert++;
    }
    pos=-1;
    for (int i=0; i<n-1; i++) {
        if (s[i]==a) pos=i;
    }
    if (pos==-1) {
        return c;
    }
    while (pos+2<n) {
        swap(s[pos], s[pos+1]);
        pos++;
        ert++;
    }

    //cout << "fontos " << a << " " << b << " " << ert << "\n";
    if (s[0]!='0') return ert;
    pos=n;
    for (int i=n-3; i>=0; i--) {
        if (s[i]!='0') pos=i;
    }
    if (pos==n) return c;
    return ert+pos;
}
int main()
{
    string s;
    cin >> s;
    if (s.size()==1) {
        cout << -1 << "\n";
        return 0;
    }
    int ans=min({solve(s, '0', '0'), solve(s, '2', '5'), solve(s, '5', '0'), solve(s, '7', '5')});
    cout << (ans==c ? -1 : ans) << "\n";
    return 0;
}