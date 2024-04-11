#include <bits/stdc++.h>

using namespace std;
int w, n, kul;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), kul=0;
        for (int i=1; i<n; i++) if (s[i]!=s[i-1]) kul++;
        if (kul) for (int i=0; i<n; i++) cout << "01";
        else cout << s;
        cout << "\n";
    }
    return 0;
}