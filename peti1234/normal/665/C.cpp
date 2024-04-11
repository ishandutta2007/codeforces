#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, ans=0;
    string s;
    cin >> s;
    n=s.size();
    for (int i=1; i<n; i++) {
        if (s[i]==s[i-1]) {
            char a=s[i-1], b=(i+1<n ? s[i+1] : '.');
            if (a!='a' && b!='a') s[i]='a';
            else if (a!='b' && b!='b') s[i]='b';
            else s[i]='c';
        }
    }
    cout << s << "\n";
    return 0;
}