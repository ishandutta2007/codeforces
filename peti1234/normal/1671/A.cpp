#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        int n=s.size();
        bool jo=1;
        for (int i=0; i<n; i++) {
            if ((i==0 || s[i]!=s[i-1]) && (i==n-1 || s[i]!=s[i+1])) jo=0;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}