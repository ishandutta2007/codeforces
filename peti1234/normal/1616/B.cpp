#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        string s;
        cin >> n >> s;
        int pos=0;
        if (n>1 && s[1]<s[0]) {
            pos++;
            while (pos+1<n && s[pos+1]<=s[pos]) pos++;
        }
        for (int i=0; i<=pos; i++) cout << s[i];
        for (int i=pos; i>=0; i--) cout << s[i];
        cout << "\n";
    }
    return 0;
}