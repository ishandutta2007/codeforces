#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n=s.size(), pos=0;
    while (pos<n) {
        if (s[pos]=='.') {
            cout << 0;
            pos++;
        } else {
            if (s[pos+1]=='.') cout << 1;
            else cout << 2;
            pos+=2;
        }
    }
    return 0;
}