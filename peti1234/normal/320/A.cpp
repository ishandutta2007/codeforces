#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int n=s.size();
    bool jo=1;
    for (auto x:s) {
        if (x!='1' && x!='4') {
            jo=0;
        }
    }
    if (s[0]!='1') {
        jo=0;
    }
    for (int i=1; i+1<n; i++) {
        if (s[i-1]=='4' && s[i]=='4' && s[i+1]=='4') {
            jo=0;
        }
    }
    cout << (jo ? "YES" : "NO") << "\n";
    return 0;
}